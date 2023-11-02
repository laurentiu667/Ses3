#include <iostream>
#include <conio.h>

using namespace std;

/*

D�FINITION ET APPEL D'UNE FONCTION (AVEC UNE LISTE DE PARAM�TRES) ET (UN TYPE DE RETOUR)

A) d�finition de la fonction

	Type_retour  nom_de_la_fonction ( Type param_1 , Type param_2 , .... , Type param_N )
	{
		// instructions utilisant les informations contenues dans les param�tres
		// ...

		return expression; // l'expression vaut une valeur qui respect le Type_retour
	}

	notes:
	- La clause "return" est obligatoire pour terminer la fonction et retourner une valeur
	- La clause "return" devrait �tre la derni�re instruction


B) appel � la fonction

	exemple:
	
		Type_retour var;

		var = nom_de_la_fonction ( expression_1 , expression_2 , ... , expression_N );

	notes:
	- le r�sultat de l'appel � la fonction peut �tre sauvegard� dans un variable

*/

int somme(int a, int b)
{
	int total = a + b;
	return total;
}

double volume_cylindre(double hauteur, double rayon)
{
	const double PI = 3.141592653589793;

	return PI * (rayon * rayon) * hauteur;
}

double kilo(double livres)
{
	const double le_kilo = 2.20462;

	return livres / le_kilo;
}

int sommer_un_lancer_des_d�s(int nombre_de_d�s, int nombre_de_faces_par_d�)
{
	int min = nombre_de_d�s;
	int max = nombre_de_d�s * nombre_de_faces_par_d�;

	int total = rand() % (max - min + 1) + min;
	return total;
}

bool estPair(int v)
{
	return v % 2 == 0;
}

bool estImpair(int v)
{
	return !estPair(v);
}

int main()
{
	int x = 10, y = 20, z;
	
	// exemples d'appels avec somme()
	z = somme(x, y);
	z = somme(x/2, y*2);
	z = somme(z, z);
	z = somme(somme(x, y)-2, somme(z*2, z)); // l'appel � somme() peut aussi �tre une sous-expression d'une autre car somme() retourne une valeur
	cout << "z = " << z << endl;

	// exemples d'appels avec volume_cylindre() et kilo()
	cout << "volume = " << volume_cylindre(10, 3.5) << endl;
	cout << "poids en kilo: " << kilo(157.5) << endl;

	// exemple d'appels avec sommer_un_lancer_des_d�s()
	srand(int(time(0)));
	for (int i = 0; i < 20; ++i)
		cout << "somme = " << sommer_un_lancer_des_d�s(5,6) << endl;

	_getch(); 
}