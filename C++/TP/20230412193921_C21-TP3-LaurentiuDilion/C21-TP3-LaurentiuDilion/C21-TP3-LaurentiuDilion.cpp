#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <fstream>
#include <windows.h>

#include "../cvm 21.h"		// pour setcp(1252)

using namespace std;

// LA CONSTANTE DU PROGRAMME

const size_t REPONDANTS_MAX = 500; // nombre maximun de répondants du sondage

// LES STRUCTURES DE DONNÉES IMPOSÉES

struct Protection
{
	int  r2[REPONDANTS_MAX];
	char r3[REPONDANTS_MAX];
	char r4[REPONDANTS_MAX];
	char r5[REPONDANTS_MAX];
	char r6[REPONDANTS_MAX];
};

struct Infection
{
	bool r7;
	int	r8, r9, r10;
};

struct Repondant
{
	string ville;
	int age;
	int scolarite;
};

// L'UNIQUE VARIABLE GLOBALE

size_t nb_repondants;	// le nombre réel de répondants: nb_repondants = lireLesDonnéesDuSondage(...)

// DÉCALRATIONS DES FONCTIONS  -- écrire vos déclarations ici ...

size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[]);

int stat_01(bool r1[]);
int stat_02(char r3[]);
double stat_03(int r2[], Repondant rep[]);
double stat_04(char r5[], char r6[], Repondant rep[]);
double stat_05(int r2[], Repondant rep[]);
double stat_06(Infection info[]);
string stat_07(Infection info[]);
int stat_08(Infection info[], char r4[]);
double stat_09(Repondant rep[], int r2[], Infection info[]);
string stat_10(Repondant rep[], Infection info[]);

// DÉFINITIONS DES FONCTIONS  --  écrire vos définitions ici ...

// Fonctions et struct pour la stat_10
struct infoville
{
	string ville;
	int stat;
};

struct Item
{
	infoville infoville;
	Item* next;
};

struct List
{
	Item* first, * last;
	size_t size;
};

bool empty(List* l) { return l->size == 0; }

void push_first(List* l, infoville& d)
{
	l->first = new Item{ d, l->first };
	if (!l->last) l->last = l->first;
	l->size++;
}

void insert_after(List* l, Item* pos, infoville& d)
{
	pos->next = new Item{ d, pos->next };
	if (l->last == pos)	l->last = pos->next;
	l->size++;
}

void push_last(List* l, infoville& d)
{
	if (empty(l))
		push_first(l, d);
	else
		insert_after(l, l->last, d);
}

Item* find_testville(List* l, string nom)
{
	for (Item* it = l->first; it; it = it->next)
		if (nom == it->infoville.ville)
			return it;
	return nullptr;
}

string find_city_with_most_test(List* l) {
	int test_max = 0;
	string nom_max = "inconnue";
	// Trouver la ville avec le plus grand nombre
	for (Item* it = l->first; it; it = it->next) {
		if (test_max < it->infoville.stat) {
			test_max = it->infoville.stat;
			nom_max = it->infoville.ville;
		}
	}

	return nom_max;
}

// FONCTIONS PRINCIPALES

int stat_01(bool r1[]) {
	int stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)		
		if (r1[i] == true)
		{
			stocked++;
		}
	return stocked;
}
int stat_02(char r3[]){
	int stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)
		if (r3[i] == 'O')
		{
			stocked++;
		}
	return stocked;
}
double stat_03(int r2[], Repondant rep[]) {
	double stocked = 0;
	int Personne = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (rep[i].age >= 30 and rep[i].age < 40)
		{
			stocked += r2[i];
			Personne++;
		}
	}
	if (stocked == 0)
	{
		stocked = 0;
	}
	else
	{
		stocked /= Personne;
	}
	return stocked;
}
double stat_04(char r5[], char r6[], Repondant rep[]) {
	double stocked = 0;
	int Personne = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (r5[i] == 'O' or r6[i] == 'O')
		{
			stocked += rep[i].age;
			Personne++;
		}
	}
	if (stocked == 0)
	{
		stocked = 0;
	}
	else
	{
		stocked /= Personne;
	}
	return stocked;
}
double stat_05(int r2[], Repondant rep[]) {
	double stocked = 0;
	double Personne = 0;
	double persvaudr = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (rep[i].ville == "Vaudreuil")
		{
			persvaudr++;
			if (r2[i] > 1)
			{
				Personne++;
			}
		}
	}

	if (persvaudr >= 1)
	{
		stocked = (Personne / persvaudr) * 100;
	}
	else
	{
		stocked = 0;
	}
	return stocked;
}
double stat_06(Infection info[]) {
	double stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (info[i].r8 != 1)
		{
			stocked++;
		}
	}
	if (stocked == 0)
	{
		stocked = 0;
	}
	else
	{
		stocked = (stocked / nb_repondants) * 100;
	}
	return stocked;
}
string stat_07(Infection info[]) {
	
	const string desinfectant[6] { "Je n’utilise pas de désinfectant", "Savon à vaisselle", "Purell", "Eau de javel", "Alcool à friction", "inconnu"};
	int stock[5] { 1,2,3,4,5 }; int stocked[5][1] = { {0}, {0}, {0}, {0}, {0} };
	int max_val = -1, max_idx = -1;

	for (size_t i = 0; i < nb_repondants; i++)
	{
		for (size_t j = 0; j < 5; j++)
			if (info[i].r8 == stock[j])
				stocked[j - 1][1]++;
	}
	// Trouver le nombre du array 2D le plus grand
	for (size_t i = 0; i < 5; i++) 
	{
		if (stocked[i][0] > max_val) 
		{
			max_val = stocked[i][0];
			max_idx = i;
		}
	}
	if (nb_repondants == 0)
	{
		return desinfectant[5];
	}
	else
	{
		return desinfectant[max_idx];
	}
}
int stat_08(Infection info[], char r4[]) {
	int stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (info[i].r10 == 0 and info[i].r8 == 1)
			if (r4[i] == 'O')
			{
				stocked++;
			}
	}
	return stocked;
}
double stat_09(Repondant rep[], int r2[], Infection info[]) {
	double stocked = 0;
	int Personne = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (rep[i].ville == "Montréal" and info[i].r9 == 1)
		{
			if (r2[i] == 0 or info[i].r8 == 1)
			{
				stocked += rep[i].scolarite;
				Personne++;
			}
		}
	}
	if (stocked == 0)
	{
		stocked = 0;
	}
	else
	{
		stocked /= Personne;
	}
	
	return stocked;
}
string stat_10(Repondant rep[], Infection info[]) {
	// Création de nouvelle liste.
	List* l = new List{ nullptr,nullptr, 0 };

	// Parcourir toute la liste et additionner le nombre test

	for (int i = 0; i < nb_repondants; ++i) {
		string nom = rep[i].ville;
		int test = info[i].r10;
		Item* itemville = find_testville(l, nom);

		if (itemville == nullptr) {
			infoville* v = new infoville{ nom, test };
			push_last(l, *v);
		}
		else {
			itemville->infoville.stat += test;
		}
	}
	string nom_max = find_city_with_most_test(l);
	return nom_max;
	delete[] l;
}

size_t lireLesDonnéesDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[])
{
	string name = "C21-TP3-Sondage.txt";											// exemple avec un path "C:/dossier/C21-TP3-Sondage.txt"
	fstream f(name, ios::in);

	if (f.fail()) // fichier ouvert ?
	{
		MessageBoxA(NULL, "Impossible d'ouvrir le fichier, Fin du programme", "Erreur", MB_OK | MB_ICONSTOP);
		exit(EXIT_FAILURE); // fin abrupte
	}

	char c;
	size_t r;
	for (r = 0; r < REPONDANTS_MAX; ++r)											// lire les réponses de chaque répondant
	{
		f >> c;	if (c == 'O') r1[r] = true; else r1[r] = false;						// r1
		f >> pro->r2[r] >> pro->r3[r] >> pro->r4[r] >> pro->r5[r] >> pro->r6[r];	// r2 à r6
		f >> c; if (c == 'O') inf[r].r7 = true; else inf[r].r7 = false;				// r7
		f >> inf[r].r8 >> inf[r].r9 >> inf[r].r10;									// r8 à r10
		f >> rep[r].ville >> rep[r].age >> rep[r].scolarite;						// ville, age, scolarité
		if (f.fail()) { f.clear(); break; }
	}
	f.close();
	return r; // r = le nombre de répondants lus
}

int main()
{
	setcp(1252);

	// Pour recevoir les données du sondage
	bool* r1 = new bool[REPONDANTS_MAX] {};					// pour la  réponse  1
	Protection* pro = new Protection {};					// pour les réponses 2-3-4-5-6
	Infection* inf = new Infection[REPONDANTS_MAX] {};		// pour les réponses 7-8-9-10
	Repondant* rep = new Repondant[REPONDANTS_MAX] {};		// pour les réponses ville, age, scolarité

	// A - charger les données du sondage
	nb_repondants = lireLesDonnéesDuSondage(r1,pro,inf,rep);

	// Affichage //
	clrscr();
	cout << fixed << setprecision(1)
		<< "Résultats du sondage :  ( " << nb_repondants << " )\n\n"
		<< "Statistiques\n\n"
		<< "1. Combien de personnes toussent souvent ?\n"
		<< "2. Combien de personnes veulent un masque dans leur auto ?\n"
		<< "3. Combien de masques, en moyenne, ont les gens qui sont dans la trentaine ?\n"
		<< "4. Quel est l'âge moyen des gens qui se serviraient d’un masque pour décorer ou pour dormir ?\n"
		<< "5. Quel pourcentage des gens de Vaudreuil possèdent plus d'un masque ?\n"
		<< "6. Quel pourcentage de la population utilise du désinfectant ?\n"
		<< "7. Quel est le type de désinfectant le plus répandu ?\n"
		<< "8. Combien de gens non testés et n’utilisant pas de désinfectant ont déjà emprunté un masque ?\n"
		<< "9. Combien d'années de scolarité, en moyenne, ont les gens infectés de Montréal sans masque ou sans désinfectant ?\n"
		<< "10. Quelle est la ville ayant fait subir le plus grand nombre de tests ?\n\n\n"

		<< "Résultats\n\n";
		// B - appeler vos fonctions statistiques et afficher ici leurs résultats
		// ...
		cout << "01) = ";		cout <<	stat_01(r1);
		cout << "\n02) = ";		cout <<	stat_02(pro->r3);
		cout << "\n03) = ";		cout << stat_03(pro->r2, rep);
		cout << "\n04) = ";		cout <<	stat_04(pro->r5, pro->r6, rep);
		cout << "\n05) = ";		cout << stat_05(pro->r2, rep); cout << " %";
		cout << "\n06) = ";		cout << stat_06(inf); cout << " %";
		cout << "\n07) = ";		cout << stat_07(inf);
		cout << "\n08) = ";		cout <<	stat_08(inf, pro->r4);
		cout << "\n09) = ";		cout << stat_09(rep, pro->r2, inf);
		cout << "\n10) = ";		cout <<	stat_10(rep, inf);

	_getch();

	// C - Recycler les allocations dynamiques
	delete[] r1;
	delete pro;
	delete[] inf;
	delete[] rep;
}