#include <iostream>
#include <conio.h>

using namespace std;

/*
	�VITER LES VARIABLES (LES INFORMATIONS) GLOBALES

		1) le principe d'isolation des informations dans une programme est important � respecter en programmation
	
		2) r�gle g�n�rale, il faut �viter d'exposer une information � tout le programme, mais plut�t l'exposer
		uniquement aux parties du programme qui en ont besoins
	
		3) par exemple, si des informations sont n�cessaires � une fonction, il est pr�f�rable de transmettre ces informations
		par l'entremise des param�tres de la fonction (ou par d'autres techniques qui respectent le principe d'isolation)

		4) de m�me que si une fonction doit retourner des informations � son appelant, il est pr�f�rable de transmettre ces informations
		par le retour de la fonction ou par l'usage de r�f�rences (ou par d'autres techniques qui respectent le principe d'isolation)
	
		5) par contre si une information est d'int�r�t g�n�ral dans un programme, l'exposition globale peut s'av�rer utile
		car l'alternative (les points 1 � 4) pourrait alourdir l'�criture et la lisibilit� du programme
 */


// EXEMPLE � �VITER

// variables globales
int input;
string output;

void je_m_habille_comment(void)							// version difficile � comprendre
{
	if (input <= -10)		output = "tu mets ton menteau";
	else if (input <= 15)	output = "tu mets ton poncho";
	else					output = "tu mets ton t-shirt";
}


// EXEMPLE � SUIVRE
string je_m_habille_comment(int temp�rature)			// version qui favorise l'isolation et la lisibilit�
{
	string habit;

	if (temp�rature <= -10)		habit = "tu mets ton menteau";
	else if (temp�rature <= 15)	habit = "tu mets ton poncho";
	else						habit = "tu mets ton t-shirt";

	return habit;
}


int main()
{
	int temp�rature_actuelle = 20;
	string habillement;


	// style de programmation � �viter et difficile � lire
	input = temp�rature_actuelle;
	je_m_habille_comment();
	habillement = output;
	cout << habillement << endl;


	// style qui favorise l'isolation et la lisibilit�
	habillement = je_m_habille_comment(temp�rature_actuelle);
	cout << habillement;

	_getch();
}