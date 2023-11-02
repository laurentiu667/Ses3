#include <iostream>
#include <conio.h>

using namespace std;

/*
	ÉVITER LES VARIABLES (LES INFORMATIONS) GLOBALES

		1) le principe d'isolation des informations dans une programme est important à respecter en programmation
	
		2) règle générale, il faut éviter d'exposer une information à tout le programme, mais plutôt l'exposer
		uniquement aux parties du programme qui en ont besoins
	
		3) par exemple, si des informations sont nécessaires à une fonction, il est préférable de transmettre ces informations
		par l'entremise des paramètres de la fonction (ou par d'autres techniques qui respectent le principe d'isolation)

		4) de même que si une fonction doit retourner des informations à son appelant, il est préférable de transmettre ces informations
		par le retour de la fonction ou par l'usage de références (ou par d'autres techniques qui respectent le principe d'isolation)
	
		5) par contre si une information est d'intérêt général dans un programme, l'exposition globale peut s'avérer utile
		car l'alternative (les points 1 à 4) pourrait alourdir l'écriture et la lisibilité du programme
 */


// EXEMPLE À ÉVITER

// variables globales
int input;
string output;

void je_m_habille_comment(void)							// version difficile à comprendre
{
	if (input <= -10)		output = "tu mets ton menteau";
	else if (input <= 15)	output = "tu mets ton poncho";
	else					output = "tu mets ton t-shirt";
}


// EXEMPLE À SUIVRE
string je_m_habille_comment(int température)			// version qui favorise l'isolation et la lisibilité
{
	string habit;

	if (température <= -10)		habit = "tu mets ton menteau";
	else if (température <= 15)	habit = "tu mets ton poncho";
	else						habit = "tu mets ton t-shirt";

	return habit;
}


int main()
{
	int température_actuelle = 20;
	string habillement;


	// style de programmation à éviter et difficile à lire
	input = température_actuelle;
	je_m_habille_comment();
	habillement = output;
	cout << habillement << endl;


	// style qui favorise l'isolation et la lisibilité
	habillement = je_m_habille_comment(température_actuelle);
	cout << habillement;

	_getch();
}