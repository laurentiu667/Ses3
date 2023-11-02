#include <iostream>
#include <conio.h>

using namespace std;

/*

	FONCTION

	PARAMÈTRE PASSÉ PAR RÉFÉRENCE (PAR OPPOSITION À PASSÉ PAR VALEUR)

		- une fonction peut avoir un ou des paramètres de type référence

		- un paramètre de type référence est une variable référence locale qui réfère au contenant d'une autre variable et cette dernière sera
		  connue lors de l'appel à la fonction
	  
		- il sera possible avec cette référence de lire et modifier le contenu de la variable référée, qui provient de l'extérieur de la fonction

		notes:
			- il est donc possible de retourner de l'information à la fonction appelante par l'usage d'une référence

			- une référence peut aussi être utile pour éviter le passage par valeur d'une information volumineuse

			Type nom_fonction (Type & param)
			{

			}

*/

double som(double m, double n)
{
	return m + n;								// retourne le résultat
}

void som(double m, double n, double & total)	// total est une référence sur un double
{
	total = m + n;								// retourne le résultat par la référence total
}

void permuter(int & m, int & n)					// m et n étant chacun une référence sur un int
{
	int temp = m;
	m = n;
	n = temp;
}

int main()
{
// exemple 1)

	double xy = 0, yz = 0;
	double x = 156.45, y = 340.89, z = 640.72;
	
	// a) technique pour obtenir le résultat par le retour de la fonction

	xy = som(x, y);
	yz = som(y, z);

	// b) technique pour obtenir le résultat par l'entremise d'une variable passée par référence

	som(x, y, xy);		// 'total' sera une référence sur xy
	som(y, z, yz);		// 'total' sera une référence sur yz
	
	// notes:
	// - x, y, z : "passées par valeur" 
	// - xy, yz  : "passées par référence"


// exemple 2)

	int v1 = 10, v2 = 22;

	permuter(v1, v2); // les valeurs de v1 et v2 seront interchangées

	// note:
	// - v1 et v2 sont des informations "passées par références" à la fonction permuter
	// - dans la fonction permuter m réfère à v1 et n réfère à v2


// exemple 3)

	const size_t S = 10;
	int tableau[S] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// mélanger le tableau

	for (size_t i = S-1; i > 0; --i)
	{
		permuter( tableau[i] , tableau[rand() % (i+1)] );		// permuter la case i avec une case entre [0..i]
	}

	_getch();
}