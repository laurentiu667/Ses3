#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <windows.h>

#include "../cvm 21.h"

using namespace std;


const size_t CLIENTS_MAX = 2;						// nombre maximal de clients
const size_t COMPTES_MAX = 3;						// nombre de comptes par client

const double MARGE_CREDIT_MAX = 10000;				// marge de cr�dit maximun d'un compte du client
const double SOLDE_COMPTE_MAX = 1000000;			// maximun � ne pas d�passer dans un compte d'un client


enum class Commandes { ajouter, afficher, deposer, retirer, virer, lister, supprimer, quitter, inconnu };
using Cmd = Commandes;

struct Nom											// nom d'un client
{
	string prenom;
	string nom;
};

struct Adresse										// adresse d'un client
{
	string noCivique;
	string rue;
	string ville;
	string codePostal;
};

struct Personne										// informations personnelles d'un client
{
	Nom		nom;
	Adresse	adresse;
	string	telephone;
	string	nas;
};

struct Compte										// un compte d'un client
{
	double solde;
	double margeCredit;
};

struct Client										// informations relatives � un client
{
	Personne	info;
	Compte		comptes[COMPTES_MAX];
	tm		    date;								// date d'ajout du client
};

struct Banque										// La banque de clients
{
	size_t cpt = 0;									// cpt: compteur de client [0..CLIENTS_MAX]
	Client clients[CLIENTS_MAX];
};

/* ----------------------------------- */
/* LES VARIABLES GLOBALES DU PROGRAMME */
/* ----------------------------------- */

// ATTENTION: les variables globales ne sont pas permises dans ce TP


/* ------------------------------------------ */
/* LES D�CLARATIONS (PROTOTYPES) DE FONCTIONS */
/* ------------------------------------------ */

void io_bip();
void io_clean();
double io_round(double v, size_t p = 2);			// par defaut la pr�cision est � deux d�cimales (p = 2)

/*
	Suggestion de fonctions:
		
		size_t lireNoCompteValide();
		double lireMontantValide(double maxmontant);
		void afficherComptesClient(Client& client);
*/

// �crire ici toutes vos d�clarations de fonctions ...
// ...
void ClientMaxError();
void ajouterInfoClient(Personne& info);
void afficherInfoClient(Personne& info);
void deposerORretirerORvirer(Banque& b, int client);
void compteurMargeSolde(Client& client);

/* ------------------------------------- */
/* FONCTIONS TRÉS GÉN�RALES DU PROGRAMME */
/* ------------------------------------- */

void io_bip() { Beep(200, 300); }

void io_clean()										// pour vider les 2 tampons
{
	cin.clear();									// s'assure que le cin est remis en marche
	cin.ignore(cin.rdbuf()->in_avail());			// vide le tampon du cin
	while (_kbhit()) (void)_getch();				// vide le tampon de la console
}

double io_round(double v, size_t p)					// tous les montants lus devront �tre arrondis avec cette fonction (v:valeur et p:pr�cision)
{
	double e = pow(10, p);
	return round(v * e) / e;
}

/* ----------------------------------------------------------------------- */
/* FONCTIONS G�N�RALES POUR L'INTERFACE USAGER (UI) EN LECTURE OU �CRITURE */
/* ----------------------------------------------------------------------- */

void afficherMenu()
{
	int x = 16;
	string Menu[10]{ "BANQUE CVM - Succ C21\n\n\n\n","1. Ajouter un client\n", "2. Afficher les informations d'un client\n", "3. Dépot\n", "4. Retrait\n", "5. Virement\n",
					 "6. Lister les clients et leur crédit actuel\n", "7. Supprimer un client\n", "Q. Quitter\n\n\n\n\n", "Entrez votre choix: " };
	for (int i = 0; i < 9; i++)
		cout << left << setw(x) << " " << Menu[i] << endl;
	cout << left << setw(x) << " " << "Entrez votre choix: "; // Entrer le char
}

Commandes lireChoixMenu()
{
	Commandes cmd = Cmd::inconnu;
	char touche;
	touche = _getch();
	touche = toupper(touche);
	cout << touche;
	switch (touche)
	{
	case '1': cmd = Cmd::ajouter;			break;
	case '2': cmd = Cmd::afficher;			break;
	case '3': cmd = Cmd::deposer;			break;
	case '4': cmd = Cmd::retirer;			break;
	case '5': cmd = Cmd::virer;				break;
	case '6': cmd = Cmd::lister;			break;
	case '7': cmd = Cmd::supprimer;			break;
	case 'Q': cmd = Cmd::quitter;			break;
	default:  cmd = Cmd::inconnu; io_bip();	break;
	}
	// lire la commande et la retourner � main ...
	return cmd;
}

/* ------------------------------------------------------------ */
/* LES FONCTIONS OBLIGATOIRES POUR CHAQUE COMMANDE DU PROGRAMME */
/* ------------------------------------------------------------ */

void ClientMaxError()
{
	clrscr();
	cout << "CMD - Ajouter un client\n\n\n\n";
	setcolor(Color::yel); cout << "La banque n'ajoute plus de nouveau client, désolé ..."; setcolor(Color::wht);
	_getch();
}

void compteurMargeSolde(Client& client)
{
	for (size_t i = 0; i < COMPTES_MAX; i++)
	{
		client.comptes[i].margeCredit = 0;
		client.comptes[i].solde = 0;
	}
}

void comptedate(Client& client)
{
	time_t secondes = time(NULL);		// la date en secondes depuis 01/01/1970
	tm date;							// tm est une structure de windows pour ranger les informations temporelle
	localtime_s(&date, &secondes);		// pour obtenir les informations temporelle à partir des secondes
	cout << date.tm_mday << "/" << date.tm_mon + 1 << "/" << date.tm_year + 1900 << "\n\n";
}

void ajouterInfoClient(Personne& info)
{
	cout << "\n\nPrénom                : ";
	getline(cin, info.nom.prenom);
	cout << "Nom                   : ";
	getline(cin, info.nom.nom);
	cout << "\nNuméro civique        : ";
	getline(cin, info.adresse.noCivique);
	cout << "Rue                   : ";
	getline(cin, info.adresse.rue);
	cout << "Ville                 : ";
	getline(cin, info.adresse.ville);
	cout << "Code postal           : ";
	getline(cin, info.adresse.codePostal);
	cout << "Téléphone             : ";
	getline(cin, info.telephone);
	cout << "\nNo assurance social   : ";
	getline(cin, info.nas); cout << endl;
}

void afficherInfoClient(Personne& info)
{
	int x = 5;
	cout << "    \nInformation personnelles\n\n";
	cout << "    #" << setw(x) << "       : " << info.adresse.noCivique << endl;
	cout << "    Rue" << setw(x) << "     : " << info.adresse.rue << endl;
	cout << "    Ville" << setw(x) << ": " << info.adresse.ville << endl;
	cout << "    CP" << setw(x) << "      : " << info.adresse.codePostal << endl;
	cout << "    Tel" << setw(x) << "     : " << info.telephone << endl;
	cout << "    NAS" << setw(x) << "     : " << info.nas << endl << endl;
	setcolor(Color::yel); cout << "\n\nAppuyez sur une touche pour continuer ..."; setcolor(Color::wht);
}

int AfficherCompteInfo(Banque& b, bool verif2, string titre) //
{
	bool verif = true;
	int numeroclient;
	cout << titre;
	gotoxy(0, 20);
	cout << "Numéro du client  : ";
	do {
		io_clean();
		cin >> numeroclient;
		Client& C = b.clients[numeroclient - 1];
		if (numeroclient <= b.cpt)
		{
			clrscr();
			gotoxy(4, 20);
			cout << "Membre          : "; comptedate(C);
			gotoxy(0, 0);
			cout << titre;
			gotoxy(0, 3);
			cout << "Nom: " << C.info.nom.nom << endl << endl;
			cout << " # Comptes" << right << setw(16) << "Solde" << setw(21) << "Marge de crédit" << endl << endl;

			for (int i = 0; i < COMPTES_MAX; i++)
				cout << right << setw(6) << i + 1 << setw(20) << C.comptes[i].solde << " $" << setw(20) << C.comptes[i].margeCredit << " $" << endl;
			if (verif2)
				afficherInfoClient(C.info);
			verif = false;
		}
	} while (verif);
	return numeroclient;
}

void deposerORretirerORvirer(Banque& b, int client, string deposerORretirerORvirer) //
{
	int numeroCompte, numeroCompte2;
	double montant, montantMax;
	Client& C = b.clients[client - 1];
	gotoxy(0, 22);
	cout << "\n\nDu compte 1 à " << COMPTES_MAX << ") : ";
	do
	{
		clreol();
		cin >> numeroCompte;
		if (deposerORretirerORvirer == "virer")
		{
			cout << "Au compte 1 à " << COMPTES_MAX << ") : ";
			cin >> numeroCompte2;
		}
	} while (cin.fail());

	io_clean();
	if (numeroCompte <= COMPTES_MAX)
	{
		if (deposerORretirerORvirer == "deposer")
			montantMax = SOLDE_COMPTE_MAX - C.comptes[numeroCompte - 1].solde;
		else if (deposerORretirerORvirer == "retirer" or deposerORretirerORvirer == "virer")
			montantMax = C.comptes[numeroCompte - 1].solde + C.comptes[numeroCompte - 1].margeCredit;
		cout << "Dépôt maximum : $ " << montantMax;
		cout << "\nMontant : ";
		do
		{
			io_clean();
			cin >> montant;
			montant = io_round(montant);

		} while (montant > montantMax or montant < 0 or cin.fail());
		if (deposerORretirerORvirer == "deposer")
			C.comptes[numeroCompte - 1].solde += montant;
		else if (deposerORretirerORvirer == "retirer")
			C.comptes[numeroCompte - 1].solde -= montant;
		else if (deposerORretirerORvirer == "virer")
		{
			C.comptes[numeroCompte2 - 1].solde += (C.comptes[numeroCompte - 1].solde + C.comptes[numeroCompte - 1].margeCredit);
			C.comptes[numeroCompte - 1].solde -= montant;
		}
	}
	io_clean();
}

Banque cmd_ajouter(Banque& b)
{
	int x = 51, y = 15;
	bool verif = true;
	Client& C = b.clients[b.cpt];
	char touche;
	if (b.cpt < CLIENTS_MAX)
	{ 
		compteurMargeSolde(C);
		io_clean(); clrscr();
		cout << "CMD - ajoute un client\n\n";
		cout << "Création du client #" << b.cpt + 1;
		ajouterInfoClient(C.info);
		for (int i = 0; i < COMPTES_MAX; i++)
		{
			io_clean();
			cout << "Marge de crédit du compte #" << i + 1 << " (Max de " << MARGE_CREDIT_MAX << " $) : ";
			do
			{
				io_clean();
				gotoxy(x, y);
				clreoscr();
				cin >> C.comptes[i].margeCredit;
				C.comptes[i].margeCredit = io_round(C.comptes[i].margeCredit);
			} while (cin.fail() || C.comptes[i].margeCredit <= 0 || C.comptes[i].margeCredit > MARGE_CREDIT_MAX);
			y++;
		}
		cout << "\nDate de création du dossier: "; comptedate(b.clients[b.cpt]);
		setcolor(Color::yel); cout << "Enregistrer le nouveau client ? (O/N) : "; setcolor(Color::wht);
		do
		{
			touche = _getch();
			touche = toupper(touche);
			switch (touche)
			{
			case 'O': b.cpt++; verif = false; break;
			case 'N': b.clients[b.cpt] = {}; verif = false; break;
			default: io_clean(); verif = true; break;
			}
		} while (verif);
	}
	else if (b.cpt >= CLIENTS_MAX)
		ClientMaxError();
	clrscr();
	return b;
}

void cmd_afficher(Banque& b)
{
	clrscr();
	AfficherCompteInfo(b, true, "CMD - afficher toutes les informations d'un client");
	_getch();
}

void cmd_deposer(Banque& b)
{
	clrscr();
	deposerORretirerORvirer(b, AfficherCompteInfo(b, false, "CMD - faire un dépôt dans un compte client"), "deposer");
}

void cmd_retirer(Banque& b)
{
	clrscr();
	deposerORretirerORvirer(b, AfficherCompteInfo(b, false, "CMD - faire un retrait dans un compte client"), "retirer");
}

void cmd_virer(Banque& b)
{
	deposerORretirerORvirer(b, AfficherCompteInfo(b, false, "CMD - faire un virement dans les comptes d'un seul client"), "virer");
}

void cmd_lister(Banque& b)
{
	int x = 50, g = 65, y = 7;
	double totalMargeCredit = 0;
	clrscr();
	cout << "CMD - lister les clients et leur crédit actuel";
	cout << "\n\nRapport pour " << b.cpt << " client\n\n";
	cout << "No    Nom" << setw(x) << " " << "Limite de Retrait" << endl;
	cout << "--    ---" << setw(x) << " " << "-----------------" << endl << endl;
	for (int i = 0; i < b.cpt; i++)
	{
		for (int j = 0; j < COMPTES_MAX; j++)
			totalMargeCredit += b.clients[i].comptes[j].margeCredit;
		cout << i + 1 << setw(5) << " " << b.clients[i].info.nom.prenom << " " << b.clients[i].info.nom.nom;
		gotoxy(g, y);
		cout << right << totalMargeCredit << "$" << endl;
		totalMargeCredit = 0; y++;
	}
	setcolor(Color::yel); cout << "\n\n\nAppuyez sur une touche pour continuer ..."; setcolor(Color::wht);
	_getch();
}

void suppcompte(Banque& b, int client)
{
	b.clients[client - 1] = b.clients[client];
	for (int i = client; i < (b.cpt - client); i++)
		b.clients[i] = b.clients[i + 1];
	b.cpt--;
}

void cmd_supprimer(Banque& b)
{
	int client;
	cout << "CMD - Supprimer un client";
	cout << "\n\n\n\n\n\nNuméro du client  : ";
	do
	{
		io_clean();
		cin >> client;
	} while (cin.fail() || client <= 0 || client > b.cpt);
	suppcompte(b, client);
}

void cmd_quitter()
{
	system("CLS");
	gotoxy(35, 15);
	cout << "A U  R  E  V  O  I  R";
	Sleep(2000);
}

/* ---------------------- */
/* LA FONCTION PRINCIPALE */
/* ---------------------- */

int main()
{
	setcp(1252);
	cout << fixed << setprecision(2);	// tous les montants sont affich�s avec une pr�cision � 2
	Cmd cmd = Cmd::inconnu;
	Banque& b = *new Banque;	// création dynamique d'une Banque
	do
	{
		clrscr();
		afficherMenu();
		cmd = lireChoixMenu();

		clrscr();

		switch (cmd)
		{
		case Cmd::ajouter:		cmd_ajouter(b);		break;
		case Cmd::afficher:		cmd_afficher(b); 	break;
		case Cmd::deposer:		cmd_deposer(b);		break;
		case Cmd::retirer:		cmd_retirer(b); 	break;
		case Cmd::virer:		cmd_virer(b); 		break;
		case Cmd::lister:		cmd_lister(b); 		break;
		case Cmd::supprimer:	cmd_supprimer(b); 	break;
		case Cmd::quitter:		cmd_quitter(); 		break;
		}
		clrscr();
	} while (cmd != Cmd::quitter);

	delete& b;
}