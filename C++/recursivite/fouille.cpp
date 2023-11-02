#include <iostream>
#include <conio.h>

using namespace std;


// Exemple de fouille dans un tableau tri� pour d�terminer si une valeur v existe
// 3 m�thodes

const int INDICE_INVALIDE = -1;					// indique que l'�l�ment n'a pas �t� trouv�

int rech_seque_i(int T[], int size, int v)		// fouille s�quentielle it�rative
{
	for (int i = 0 ; i < size ; i++ )
		if (T[i] == v)
			return i;
	return INDICE_INVALIDE;
}

int rech_dicho_i(int T[], int size, int v)		// fouille dichotomique it�rative
{
	int min = 0, mil, max = size-1;
	while ( min <= max )
	{
		mil = (min + max) / 2;
		if ( v == T[mil] )
			return mil;
		else if ( v < T[mil] )
			max = mil-1;
		else
			min = mil+1;
	}
	return INDICE_INVALIDE;
}

int rech_dicho_r(int T[], int min, int max, int v)	// fouille dichotomique r�cursive
{
	if (min <= max)
	{
		int mil = (min + max) / 2;
		if ( v == T[mil] )
			return mil;
		else if ( v < T[mil] )
			return rech_dicho_r(T, min, mil-1, v);
		else
			return rech_dicho_r(T, mil+1, max, v);
	}
	else
		return INDICE_INVALIDE;
}

int main()
{
	const int size = 8;
	int T[size] = { -4 , -2 , 0 , 2 , 4 , 6 , 8 , 10 };	// tableau tri�

	int v = 6; // valeur recherch�e

	cout << "recherche_sequentielle_iterative de : " << v << "  ind = : " << rech_seque_i(T, size, v)	 << endl ;
	cout << "recherhce_dichotomique_iterative de : " << v << "  ind = : " << rech_dicho_i(T, size, v)	 << endl ;
	cout << "recherche_dichotomique_recursive de : " << v << "  ind = : " << rech_dicho_r(T, 0, size, v) << endl ;

	_getch();
}