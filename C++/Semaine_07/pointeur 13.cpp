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
	
	// 1) cr�ation d'un tableau T de int o� la taille est un entier

	T = new int [size] {};				// T contient l'adresse du premier int de la s�rie. Toutes les valeurs sont � z�ro {}


	// 2) initialisation de T avec des valeurs al�atoires de 0 � 100

	for (size_t i = 0; i < size; ++i)
		T[i] = rand() % 101;


	// 3) acc�s aux �l�ments de T par un calcul sur l'adresse (T+i)
	// note: T[i]  idem que  *(T+i) 

	for (size_t i = 0; i < size; ++i)
		*(T+i) += 20;					// calcul sous-entendu: T + (i * sizeof(int))

	
	// 4) afficher la derni�re valeur de T

	cout << T[size-1]		<< endl;	// avec l'op�rateur pour pointeur [], et un indice
	cout << *(T + (size-1))	<< endl;	// avec l'op�rateur pour pointeur * , et un calcul sur l'adresse


	// 5) Destruction apr�s usage du tableau T

	delete [] T;		// obligatoire: s'�crit "delete []" car T est un pointeur vers une serie de int --> un tableau

						// note: delete T; --> est une erreur ici car seul le premier int du tableau sera recycl�
	_getch();
}