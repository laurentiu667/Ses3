#include <iostream>					// Entrée/sortie standard
#include <conio.h>					// Pour utiliser _getch()
#include <iomanip>					// Pour utiliser setw()
#include <fstream>					// Pour la manipulation de fichiers
#include <sstream>					// Pour la manipulation de flux de chaînes de caractères

#include "commandes_globales.h"		// Fichier d'en-tête pour les commandes globales
#include "cvm 21.h"					// Fichier d'en-tête pour cvm 21
#include "io.h"						// Fichier d'en-tête pour les opérations d'entrée/sortie
#include "show_top_title.h"			// Fichier d'en-tête pour afficher le titre supérieur
#include "confirmer_num_membre.h"   // Fichier d'en-tête pour confirmer le numéro de membre
#include "fonction_importer.h"		// Fichier d'en-tête pour la fonction cmd_importer
#include "List_chainée.h"			// Fichier d'en-tête pour la fonction cmd_list

#include <chrono>
#include <thread>
using namespace std;

// A J O U T E R 

void cmd_ajouter()
{
	size_t x = 1, y = 4, b = 20, c = 30;
	Membre m;
	size_t no = db_size() + 1; // Le numéro du nouveau contact
	clrscr();
	io_clean();
	show_top_title();		   //TITRE
	gotoxy(x + 4, y);		cout << "Création du membre #"; cout << db_size() + 1;
	gotoxy(x + 4, y += 3);  cout << "Informations personnelles";
	gotoxy(x + 4, y += 1);  cout << "-------------------------";
	gotoxy(x + 4, y += 2); cout << left << setw(b) << "Prénom" << ": " << setw(c); io_lireString(NOMBRE_CHAR_MAX, m.prenom);
	gotoxy(x + 4, y += 1); cout << left << setw(b) << "Nom" << ": " << setw(c);	io_lireString(NOMBRE_CHAR_MAX, m.nom);
	gotoxy(x + 4, y += 2); cout << left << setw(b) << "Ville" << ": " << setw(c); io_lireString(NOMBRE_CHAR_MAX, m.ville);
	gotoxy(x + 4, y += 2); cout << left << setw(b) << "Âge [16...120]" << ": " << setw(c);
	int d = wherex(), g = wherey();
	do
	{
		io_clean();
		gotoxy(d, g);
		clreoscr();
		cin >> m.age;
	} while (m.age <= 15 or m.age >= 121);

	db_write(no, &m);
}

// A F F I C H E R

void cmd_afficher()
{
	Membre m;
	clrscr();
	io_clean();
	show_top_title(); cout << endl;		   // TITRE
	int x = wherex(), y = wherey();
	gotoxy(x + 5, y + 2); cout << "Numéro du membre   : ";
	int no = confirmer_num_membre();
	if (no > 0)
	{
		db_read(no, &m);
		afficher(no, "Appuyez sur une touche pour continuer ... ", m, false);
		_getch();
	}
}
void afficher_clubs(size_t no, Membre& m, string phrase, bool modif_true)
{
	size_t u = 1, o = 12, v = 10, h = 10;
	gotoxy(u + 4, o + 2);  cout << "Liste des clubs (" << m.nb_clubs << ")" << endl << endl;
	int x = wherex(), y = wherey(), newX = wherex(), newY = wherey();
	bool xyTrue = true;
	for (size_t i = 0; i < NOMBRE_CLUB_MAX; i++)
	{
		cout << right << setw(9) << i + 1 << ".    " << m.clubs[i].nom_Club << endl;
		if (xyTrue)
		{

			newX = wherex(); // Mettre à jour newX à chaque itération
			newY = wherey(); // Mettre à jour newY à chaque itération
		}
		xyTrue = false;
	}
	setcolor(Color::yel); cout << endl << endl << right << setw(3) << "" << phrase;
	char c;
	int d = wherex(), g = wherey();
	if (modif_true)
	{
		do
		{
			io_clean();
			switch (c = toupper(_getch()))
			{
			case 'A':
			{
				if (m.nb_clubs < 10)
				{
					ajouter_club(no, m, c, newX, newY);
					setcolor(Color::wht);
					gotoxy(u + 4, o + 2);
					clreoscr();
					afficher_clubs(no, m, phrase, false);
				}

				break;
			}
			case 'R':
			{
				retirer_club(no, m, c);
				setcolor(Color::wht);
				gotoxy(u + 4, o + 2);
				clreoscr();
				afficher_clubs(no, m, phrase, false);
				break;
			}
			case 'Q': break;
			default: io_bip(); break;
			}
			
			gotoxy(d, g);
			clreoscr();
		} while (c != 'Q');
	}
}
void afficher(size_t no, string phrase, Membre& m, bool trueORfalse)
{
	size_t x = 1, y = 4, b = 10, c = 10;
	gotoxy(x + 4, y + 2);	cout << "Informations personnelles";
	gotoxy(x + 4, y += 4);	cout << "\t"; cout << left << setw(b) << "Nom" << ": " << m.prenom << " " << m.nom << endl << endl;
	gotoxy(x + 4, y += 2);  cout << "\t"; cout << left << setw(b) << "Ville" << ": " << m.ville << endl;
	gotoxy(x + 4, y += 1);  cout << "\t"; cout << left << setw(b) << "Âge" << ": " << m.age << endl << endl << endl;
	afficher_clubs(no, m, phrase, trueORfalse); // AFFICHE LES CLUBS, LES AJOUTES ET LES RETIRES
}

// A J O U T E R  || R E T I R E R 

void ajouter_club(size_t no, Membre& m, char c, int newX, int newY)
{
	if (m.nb_clubs < 10)
	{
		cout << c;
		gotoxy(newX + 14, ((newY - 1) + m.nb_clubs));
		bool club_existe = false;
		char nouveau_nom_club[NOMBRE_CHAR_MAX];
		setcolor(Color::wht);
		io_lireString(NOMBRE_CHAR_MAX, nouveau_nom_club);
		// Convertir le nom en minuscule
		for (size_t i = 0; nouveau_nom_club[i]; i++) {
			nouveau_nom_club[i] = tolower(nouveau_nom_club[i]);
		}
		// Verifie si club existe
		for (size_t i = 0; i < m.nb_clubs; i++)
		{
			char nom_club[NOMBRE_CHAR_MAX];
			strcpy_s(nom_club, m.clubs[i].nom_Club);
			for (size_t j = 0; nom_club[j]; j++) {
				nom_club[j] = tolower(nom_club[j]);
			}
			if (strcmp(nouveau_nom_club, nom_club) == 0)
			{
				club_existe = true;
				break;
			}
		}
		if (!club_existe)
		{
			strcpy_s(m.clubs[m.nb_clubs].nom_Club, nouveau_nom_club);
			m.nb_clubs++;
			db_write(no, &m);
		}
	}
}
void retirer_club(size_t no, Membre& m, char c)
{
	size_t num = 0;
	cout << c;
	setcolor(Color::red);
	cout << "\t\t\tNuméro : ";
	int d = wherex(), g = wherey();
	do
	{
		io_clean();
		gotoxy(d, g);
		clreoscr();
		cin >> num;

	} while (cin.fail() || num < 0 || num > m.nb_clubs);
	setcolor(Color::yel);
	// Décaler les clubs suivants d'un indice vers la gauche
	if (num >= 1)
	{
		for (size_t i = num - 1; i < m.nb_clubs - 1; i++)
		{
			strcpy_s(m.clubs[i].nom_Club, NOMBRE_CHAR_MAX, m.clubs[i + 1].nom_Club);
		}
		// Réinitialiser la dernière case
		m.clubs[m.nb_clubs - 1].nom_Club[0] = '\0';
		// Décrémenter le nombre de clubs
		m.nb_clubs--;
		// Écrire les modifications dans la base de données
		db_write(no, &m);
	}
}
void cmd_modifier()
{
	Membre m;
	size_t dbsize = db_size();
	clrscr();
	io_clean();
	show_top_title(); cout << endl;		   // TITRE
	int x = wherex(), y = wherey();
	gotoxy(x + 5, y + 2); cout << "Numéro du membre   : ";
	int no = confirmer_num_membre();
	if (no > 0)
	{
		db_read(no, &m);
		// afficher prends en compte afficher_clubs dans cette fonction j'ajoute et retire
		afficher(no, "Ajouter, Retirer un club (A,R,Q) ? ", m, true);
	}
}

// S T A T S

void afficher_stats()
{
	Membre m;
	cout << endl;
	int x = wherex(), y = wherey();
	gotoxy(x + 4, y + 4); setcolor(Color::_yel); cout << "Statistiques\n\n\n"; setcolor(Color::wht);
	setcolor(Color::_blu);  cout << right << setw(11) << "membres" << setw(10) << "clubs" << setw(17) << "distribution" << endl << endl;  setcolor(Color::wht);

	int clubs[NOMBRE_CLUB_MAX + 1] = { 0,1,2,3,4,5,6,7,8,9,10 };
	int nb_membres = db_size();
	int nb_clubs_total = 0;
	int membre_compteur_club[NOMBRE_CLUB_MAX + 1] = { 0 };
	double moyenne = 0;
	cout << fixed << setprecision(1);
	for (size_t i = 1; i <= nb_membres; i++)
	{
		db_read(i, &m);

		nb_clubs_total = m.nb_clubs;

		for (size_t j = 0; j <= NOMBRE_CLUB_MAX; j++)
		{
			if (nb_clubs_total == clubs[j])
			{
				membre_compteur_club[clubs[j]]++;
			}
		}
	}

	// COUT membre clubs et distribution
	for (size_t i = 0; i <= NOMBRE_CLUB_MAX; i++)
	{
		double distr = (membre_compteur_club[i] / static_cast<double>(nb_membres)) * 100;

		cout << right << setw(10) << membre_compteur_club[i] << setw(9) << i << setw(13) << distr << " %" << endl;
	}

	// COUT moyenne clubs ---- membre x clubs \ membre
	for (size_t i = 0; i <= NOMBRE_CLUB_MAX; i++)
	{
		moyenne += (membre_compteur_club[i] * static_cast<double>(i)) / nb_membres;
	}

	cout << endl << right << setw(14) << "moyenne = " << moyenne << (moyenne >= 2 ? " clubs" : " club");
}
void cmd_stats()
{
	clrscr();
	io_clean();
	show_top_title();
	afficher_stats();
	_getch();
}

// L I S T 

void afficher_list()
{
	Membre m;
	setcolor(Color::_yel);
	gotoxy(4, 4);
	cout << "Liste des clubs";
	setcolor(Color::_blu);
	cout << endl;
	find_club_total(m);
}
void cmd_list()
{
	clrscr();
	show_top_title();
	afficher_list();
	_getch();
}

// E X P O R T E R

void _write(fstream& file, Membre& m)
{
	file << "PRENOM = " << m.prenom << endl;
	file << "NOM    = " << m.nom << endl;
	file << "VILLE  = " << m.ville << endl;
	file << "AGE    = " << m.age << endl;
	for (int i = 0; i < m.nb_clubs; i++) {
		file << "CLUB   = " << m.clubs[i].nom_Club << endl;
	}
	file << ";" << endl;
}
void save(string fname, bool erase, Membre& m) 
{
	fstream file;
	int nb_membres = db_size();

	if (erase)
		file.open(fname, ios::out);  // mode "output" ==> crée (ou recrée) un nouveau fichier vide
	else
		file.open(fname, ios::app);  // mode "append" ==> ajoute à la fin du fichier s'il existe, sinon le crée

	if (file.is_open()) {
		if (db_size() > 0)
		{
			for (size_t i = 1; i <= nb_membres; i++)
			{
				db_read(i, &m);
				_write(file, m);
				gotoxy(4, 26);
				setcolor(Color::_yel);
				cout << "''" << fname << "''" << " --> exportation réussie ... ";
				setcolor(Color::wht);
			}
		}
		else
		{
			gotoxy(4, 26);
			setcolor(Color::_yel);
			cout << "Il n'y a aucun membre actuellement ! ";
			setcolor(Color::wht);
		}
		file.close();
	}
}
void cmd_xport() 
{
	setcp(1252);
	string fname = "membres.txt";
	Membre m;
	clrscr();
	show_top_title();
	save(fname, true, m);
	_getch();
}

// I M P O R T E R 

void cmd_import()
{
    Membre m;
    string fname = "membres.txt";
	clrscr();
	show_top_title();
    load_db(fname, &m);
}

// E F F A C E R  -- CLUB OU MEMBRE

void cmd_effacer()
{
	clrscr();
	show_top_title();
	if (io_lireQuestionOuiNon("Voulez-vous supprimer seulement les clubs de chacun des membres", Color::red, { MARG, 3 }))
	{
		for (int i = 1; i <= db_size(); i++)
		{
			Membre m;
			db_read(i, &m);
			m.nb_clubs = 0;

			for (int j = 0; j < NOMBRE_CLUB_MAX; j++)
			{
				m.clubs[j] = {};
			}
			db_write(i, &m);
		}
	}
	else
	{
		if (io_lireQuestionOuiNon("Voulez-vous supprimer tous les membres", Color::red, { MARG, 3 + 2 }))
		{
			db_create();
		}
	}
}

// Q U I T T E R

void cmd_quitter(void)
{
	setcolor(Color::yel);
	clrscr();
	const int nombre = 3;
	const string texte[nombre]
	{
		"Auteur : L A U R E N T I U   D I L I O N",
		"COURS : C22   P R O G R M A T I O N",
		"MESSAGE POUR VOUS : V A I S - J E  R É U S S I R  L' E X A M E N  F I N A L ?"
	};

	int consoleWidth = 120; // Largeur de la console

	for (int i = 0; i < nombre; i++)
	{
		int padding = (consoleWidth - texte[i].size()) / 2;


		string centeredText = string(padding, ' ') + texte[i];

		for (int j = 0; j < centeredText.size(); j++)
		{
			cout << centeredText[j];
			this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	setcolor(Color::red);
	this_thread::sleep_for(chrono::milliseconds(1500));
	int compteur = 0;

	while (compteur <= 100) {
		std::cout << "Déstruction de windows " << compteur << " %" << std::endl;
		compteur++;
		this_thread::sleep_for(chrono::milliseconds(30));
	}
	setcolor(Color::_blu);
	cout << R"(                               ___           ___           ___           ___           ___     
                              /  /\         /  /\         /  /\         /  /\         /  /\    
                             /  /::\       /  /::\       /  /::|       /  /::|       /  /::\   
                            /  /:/\:\     /  /:/\:\     /  /:|:|      /  /:|:|      /  /:/\:\  
                           /  /::\ \:\   /  /:/  \:\   /  /:/|:|__   /  /:/|:|__   /  /::\ \:\ 
                          /__/:/\:\_\:| /__/:/ \__\:\ /__/:/ |:| /\ /__/:/ |:| /\ /__/:/\:\ \:\
                          \  \:\ \:\/:/ \  \:\ /  /:/ \__\/  |:|/:/ \__\/  |:|/:/ \  \:\ \:\_\/
                           \  \:\_\::/   \  \:\  /:/      |  |:/:/      |  |:/:/   \  \:\ \:\  
                            \  \:\/:/     \  \:\/:/       |__|::/       |__|::/     \  \:\_\/  
                             \__\::/       \  \::/        /__/:/        /__/:/       \  \:\    
                                 ~~         \__\/         \__\/         \__\/         \__\/    
                        ___           ___           ___           ___           ___           ___           ___     
          ___          /  /\         /  /\         /  /\         /  /\         /  /\         /  /\         /  /\    
         /  /\        /  /::\       /  /::\       /  /::\       /  /::|       /  /::\       /  /::\       /  /::\   
        /  /:/       /  /:/\:\     /  /:/\:\     /  /:/\:\     /  /:|:|      /  /:/\:\     /  /:/\:\     /__/:/\:\  
       /  /:/       /  /::\ \:\   /  /:/  \:\   /  /::\ \:\   /  /:/|:|__   /  /:/  \:\   /  /::\ \:\   _\_ \:\ \:\ 
      /__/:/  ___  /__/:/\:\_\:\ /__/:/ \  \:\ /__/:/\:\_\:\ /__/:/ |:| /\ /__/:/ \  \:\ /__/:/\:\ \:\ /__/\ \:\ \:\
      |  |:| /  /\ \__\/  \:\/:/ \  \:\  \__\/ \__\/  \:\/:/ \__\/  |:|/:/ \  \:\  \__\/ \  \:\ \:\_\/ \  \:\ \:\_\/
      |  |:|/  /:/      \__\::/   \  \:\            \__\::/      |  |:/:/   \  \:\        \  \:\ \:\    \  \:\_\:\  
      |__|:|__/:/       /  /:/     \  \:\           /  /:/       |__|::/     \  \:\        \  \:\_\/     \  \:\/:/  
       \__\::::/       /__/:/       \  \:\         /__/:/        /__/:/       \  \:\        \  \:\        \  \::/   
           ~~~~        \__\/         \__\/         \__\/         \__\/         \__\/         \__\/         \__\/    )" << '\n';

	this_thread::sleep_for(chrono::milliseconds(5000));
}