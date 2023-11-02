#include <iostream>
#include <conio.h>

using namespace std;

/*

	D�CLARATION D'UNE FONCTION (concept identique: PROTOTYPE d'une fonction ou ENT�TE d'une fonction)

		- la d�claration d'une fonction est une instruction pour annoncer l'existance d'une fonction.
		
		- la d�claration d'une fonction contient seulement le nom, le type de retour et la liste de param�tres, SANS le bloc {} d'instructions
	
		- la d�claration d'une fonction contient les informations utiles au compilateur pour v�rifier l'exactitude d'un appel � cette fonction

		- la d�claration d'une fonction permet de ranger sa d�finition ailleurs dans le code
	
		- l'usage des d�clarations peut aussi am�liorer la lisibilit� du code

		exemple de d�claration:

			Type_retour nom_fonction ( Type param, ... ) ;		// d�claration de nom_fonction

*/


int fonction_A(int n);	// d�claration de fonction_A
int fonction_B(int n);	// d�claration de fonction_B

int main()
{
	for (int i = 4; i < 8; ++i)
	{
		cout << fonction_A(i*i) << endl;	// appel � fonction_A -- v�rifiable avec sa d�claration ci-haut
	}
	_getch();
}

int fonction_A(int n)						// d�finition de la fonction_A
{
	int m;
	m = fonction_B(n*2);					// appel � fonction_B -- v�rifiable avec sa d�claration ci-haut
	return m;
}

int fonction_B(int n)						// d�finition de la fonction_B
{
	int m;
	m = ++n % 5;
	return m;
}