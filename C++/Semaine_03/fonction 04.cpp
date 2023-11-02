#include <iostream>
#include <conio.h>

using namespace std;

/*

DÉFINITION ET APPEL D'UNE FONCTION (AVEC UNE LISTE DE PARAMÈTRES) ET (UN TYPE DE RETOUR)

A) définition de la fonction

	Type_retour  nom_de_la_fonction ( Type param_1 , Type param_2 , .... , Type param_N )
	{
		// instructions utilisant les informations contenues dans les paramètres
		// ...

		return expression; // l'expression vaut une valeur qui respect le Type_retour
	}

	notes:
	- La clause "return" est obligatoire pour terminer la fonction et retourner une valeur
	- La clause "return" devrait être la dernière instruction


B) appel à la fonction

	exemple:
	
		Type_retour var;

		var = nom_de_la_fonction ( expression_1 , expression_2 , ... , expression_N );

	notes:
	- le résultat de l'appel à la fonction peut être sauvegardé dans un variable

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

int sommer_un_lancer_des_dés(int nombre_de_dés, int nombre_de_faces_par_dé)
{
	int min = nombre_de_dés;
	int max = nombre_de_dés * nombre_de_faces_par_dé;

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
	z = somme(somme(x, y)-2, somme(z*2, z)); // l'appel à somme() peut aussi être une sous-expression d'une autre car somme() retourne une valeur
	cout << "z = " << z << endl;

	// exemples d'appels avec volume_cylindre() et kilo()
	cout << "volume = " << volume_cylindre(10, 3.5) << endl;
	cout << "poids en kilo: " << kilo(157.5) << endl;

	// exemple d'appels avec sommer_un_lancer_des_dés()
	srand(int(time(0)));
	for (int i = 0; i < 20; ++i)
		cout << "somme = " << sommer_un_lancer_des_dés(5,6) << endl;

	_getch(); 
}