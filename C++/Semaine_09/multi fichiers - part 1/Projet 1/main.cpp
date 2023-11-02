// 1) INCLUDES STANDARDS - à mettre en premier et seulement ceux qui sont nécessaires pour ce module

#include <iostream>
#include <iomanip>
#include <conio.h>

// 2) INCLUDES PARTICULIERS

#include "stats.h" // pour avoir accès aux fonctions moyenne(), variance(), ecart_type()

using namespace std;

int main()
{
	const size_t size = 5;
	double notes[size] = { 50, 60, 70, 80, 90 };

	cout << fixed << setprecision(2) << endl;;
	cout << "moyenne    : " << moyenne(notes, size) << endl;
	cout << "variance   : " << variance(notes, size) << endl;
	cout << "ecart type : " << ecart_type(notes, size) << endl;


	// cout << "somme      : " << somme(notes, size) << endl; 

	// somme() est une fonction privée (static) au fichier stats.cpp et elle est donc invisible ici
	// même si on avait accès à sa déclaration.


	_getch();
}