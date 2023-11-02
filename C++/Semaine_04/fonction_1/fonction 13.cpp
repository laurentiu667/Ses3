#include <iostream>
#include <conio.h>

using namespace std;

/*

	FONCTION

	PARAM�TRE PASS� PAR R�F�RENCE (PAR OPPOSITION � PASS� PAR VALEUR)

		- une fonction peut avoir un ou des param�tres de type r�f�rence

		- un param�tre de type r�f�rence est une variable r�f�rence locale qui r�f�re au contenant d'une autre variable et cette derni�re sera
		  connue lors de l'appel � la fonction
	  
		- il sera possible avec cette r�f�rence de lire et modifier le contenu de la variable r�f�r�e, qui provient de l'ext�rieur de la fonction

		notes:
			- il est donc possible de retourner de l'information � la fonction appelante par l'usage d'une r�f�rence

			- une r�f�rence peut aussi �tre utile pour �viter le passage par valeur d'une information volumineuse

			Type nom_fonction (Type & param)
			{

			}

*/

double som(double m, double n)
{
	return m + n;								// retourne le r�sultat
}

void som(double m, double n, double & total)	// total est une r�f�rence sur un double
{
	total = m + n;								// retourne le r�sultat par la r�f�rence total
}

void permuter(int & m, int & n)					// m et n �tant chacun une r�f�rence sur un int
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
	
	// a) technique pour obtenir le r�sultat par le retour de la fonction

	xy = som(x, y);
	yz = som(y, z);

	// b) technique pour obtenir le r�sultat par l'entremise d'une variable pass�e par r�f�rence

	som(x, y, xy);		// 'total' sera une r�f�rence sur xy
	som(y, z, yz);		// 'total' sera une r�f�rence sur yz
	
	// notes:
	// - x, y, z : "pass�es par valeur" 
	// - xy, yz  : "pass�es par r�f�rence"


// exemple 2)

	int v1 = 10, v2 = 22;

	permuter(v1, v2); // les valeurs de v1 et v2 seront interchang�es

	// note:
	// - v1 et v2 sont des informations "pass�es par r�f�rences" � la fonction permuter
	// - dans la fonction permuter m r�f�re � v1 et n r�f�re � v2


// exemple 3)

	const size_t S = 10;
	int tableau[S] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	// m�langer le tableau

	for (size_t i = S-1; i > 0; --i)
	{
		permuter( tableau[i] , tableau[rand() % (i+1)] );		// permuter la case i avec une case entre [0..i]
	}

	_getch();
}