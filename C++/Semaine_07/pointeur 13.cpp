#include <iostream>
#include <conio.h>

using namespace std;

/*
	ALLOCATION DYNAMIQUE D'UN TABLEAU
*/

int main()
{
	size_t size = 10;

	int* T;
	
	// 1) création d'un tableau T de int où la taille est un entier

	T = new int [size] {};				// T contient l'adresse du premier int de la série. Toutes les valeurs sont à zéro {}


	// 2) initialisation de T avec des valeurs aléatoires de 0 à 100

	for (size_t i = 0; i < size; ++i)
		T[i] = rand() % 101;


	// 3) accès aux éléments de T par un calcul sur l'adresse (T+i)
	// note: T[i]  idem que  *(T+i) 

	for (size_t i = 0; i < size; ++i)
		*(T+i) += 20;					// calcul sous-entendu: T + (i * sizeof(int))

	
	// 4) afficher la dernière valeur de T

	cout << T[size-1]		<< endl;	// avec l'opérateur pour pointeur [], et un indice
	cout << *(T + (size-1))	<< endl;	// avec l'opérateur pour pointeur * , et un calcul sur l'adresse


	// 5) Destruction après usage du tableau T

	delete [] T;		// obligatoire: s'écrit "delete []" car T est un pointeur vers une serie de int --> un tableau

						// note: delete T; --> est une erreur ici car seul le premier int du tableau sera recyclé
	_getch();
}