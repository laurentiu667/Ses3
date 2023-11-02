#include <iostream>
#include <conio.h>

using namespace std;

/*
	UN POINTEUR SUR UN POINTEUR

		pointeur				pointeur				variable
		-------------			-------------			-------------
		|  adresse  |	--->	|  adresse  |	--->	|  valeur   |
		-------------			-------------			-------------		

			pp						p						d
*/

int main()
{
	// 1) soit les définitions

	double d = 100;		// soit d un double

	double* p = &d;		// soit p un pointeur sur le double d

	double** pp = &p;	// soit pp un pointeur sur le pointeur p d'un double   ( hein ?!? )


	// 2) affichage des adresses

	cout << "l'adresse de d : " << p << endl;
	cout << "l'adresse de p : " << pp << endl;
	cout << "l'adresse de pp: " << &pp << endl;

	// de même que
	cout << "l'adresse de d : " << *pp << endl;


	// 3) accès à d en écriture 

	d = 200;			// d vaut 200 maintenant

	*p = 300;			// d vaut 300 maintenant

	**pp = 400;			// d vaut 400 maintenant

	cout << "la valeur de d: " << **pp << endl;

	_getch();
}