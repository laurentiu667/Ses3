#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

DÉFINITION ET APPEL D'UNE FONCTION (VERSION SIMPLE)

A) définition de la fonction

	void nom_de_la_fonction()
	{

		// définitions des constantes "locales"
		// ...

		// définitions des types "locaux"
		// ...

		// définitions des variables "locales"
		// ...

		// instructions de la fonction
		// ...
	}

	notes:
	- une fonction est un outil de rangement pour nommer et regrouper les instructions d'une tâche spécifique
	- seule la fonction "main" est obligatoire mais
	- la décomposition du programme en plusieurs fonctions est nécessaire pour faciliter sa lisibilité, son entretien et son évolution


	notes:
	- l'écriture d'une nouvelle fonction ce fait de la même manière que la fonction main()
	- l'utilisation du type "void" est obligatoire (pour le moment)
	- les parenthèses () après le nom sont aussi obligatoires


B) appel à la fonction

	nom_de_la_fonction();

	notes:
	- un appel à la fonction consiste à exiger son exécution et par conséquent d'exécuter ses instructions
	- les parenthèses () sont obligatoires

*/

// déninition
void effectuer_des_instructions()
{
	const int C = 10;

	struct Type
	{
		string membre;
	};

	Type var;

	// instructions
	// ...
	cout << "instructions termin\202es" << endl;

	// à la fin de la fonction, toutes les constantes et les variables créées seront détruites
}

// déninition
void effectuer_d_autres_instructions()
{
	string statut;

	statut = "termin\202es";
	// ...
	cout << "instructions autres " << statut << endl;
}


// déninition obligatoire
int main()
{
	effectuer_des_instructions();		// main "appelle" la fonction "effectuer_des_instructions()"
	effectuer_d_autres_instructions();	// main "appelle" la fonction "effectuer_d_autres_instructions()"

	_getch(); // _getch() est une fonction !
}