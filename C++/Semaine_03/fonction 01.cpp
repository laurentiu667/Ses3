#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

D�FINITION ET APPEL D'UNE FONCTION (VERSION SIMPLE)

A) d�finition de la fonction

	void nom_de_la_fonction()
	{

		// d�finitions des constantes "locales"
		// ...

		// d�finitions des types "locaux"
		// ...

		// d�finitions des variables "locales"
		// ...

		// instructions de la fonction
		// ...
	}

	notes:
	- une fonction est un outil de rangement pour nommer et regrouper les instructions d'une t�che sp�cifique
	- seule la fonction "main" est obligatoire mais
	- la d�composition du programme en plusieurs fonctions est n�cessaire pour faciliter sa lisibilit�, son entretien et son �volution


	notes:
	- l'�criture d'une nouvelle fonction ce fait de la m�me mani�re que la fonction main()
	- l'utilisation du type "void" est obligatoire (pour le moment)
	- les parenth�ses () apr�s le nom sont aussi obligatoires


B) appel � la fonction

	nom_de_la_fonction();

	notes:
	- un appel � la fonction consiste � exiger son ex�cution et par cons�quent d'ex�cuter ses instructions
	- les parenth�ses () sont obligatoires

*/

// d�ninition
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

	// � la fin de la fonction, toutes les constantes et les variables cr��es seront d�truites
}

// d�ninition
void effectuer_d_autres_instructions()
{
	string statut;

	statut = "termin\202es";
	// ...
	cout << "instructions autres " << statut << endl;
}


// d�ninition obligatoire
int main()
{
	effectuer_des_instructions();		// main "appelle" la fonction "effectuer_des_instructions()"
	effectuer_d_autres_instructions();	// main "appelle" la fonction "effectuer_d_autres_instructions()"

	_getch(); // _getch() est une fonction !
}