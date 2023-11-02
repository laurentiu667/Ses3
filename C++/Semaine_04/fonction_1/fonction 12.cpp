#include <iostream>
#include <conio.h>

using namespace std;

/*

	DÉCLARATION D'UNE FONCTION (concept identique: PROTOTYPE d'une fonction ou ENTÊTE d'une fonction)

		- la déclaration d'une fonction est une instruction pour annoncer l'existance d'une fonction.
		
		- la déclaration d'une fonction contient seulement le nom, le type de retour et la liste de paramètres, SANS le bloc {} d'instructions
	
		- la déclaration d'une fonction contient les informations utiles au compilateur pour vérifier l'exactitude d'un appel à cette fonction

		- la déclaration d'une fonction permet de ranger sa définition ailleurs dans le code
	
		- l'usage des déclarations peut aussi améliorer la lisibilité du code

		exemple de déclaration:

			Type_retour nom_fonction ( Type param, ... ) ;		// déclaration de nom_fonction

*/


int fonction_A(int n);	// déclaration de fonction_A
int fonction_B(int n);	// déclaration de fonction_B

int main()
{
	for (int i = 4; i < 8; ++i)
	{
		cout << fonction_A(i*i) << endl;	// appel à fonction_A -- vérifiable avec sa déclaration ci-haut
	}
	_getch();
}

int fonction_A(int n)						// définition de la fonction_A
{
	int m;
	m = fonction_B(n*2);					// appel à fonction_B -- vérifiable avec sa déclaration ci-haut
	return m;
}

int fonction_B(int n)						// définition de la fonction_B
{
	int m;
	m = ++n % 5;
	return m;
}