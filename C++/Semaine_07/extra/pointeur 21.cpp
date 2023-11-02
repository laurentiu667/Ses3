#include <iostream>
#include <conio.h>
using namespace std;

/*
	ALLOCATION DYNAMIQUE DES TABLEAUX À PLUSIEURS DIMENSIONS

	1) allocation en mémoire dans un espace d'adresses contiguës

	2) syntaxe:

		new Type [size][CONSTANTE]...[CONSTANTE];

	3) la taille (size) de la première dimension est dynamique, les autres doivent être déterminées à la compilation


	4) alternativement, il est toujours possible d'allouer un très grand tableau à une seule dimension et de gérér manuellement
	l'organisation intérieure (les dimensions) et la façon d'y accéder

*/

int main()
{
	// la clause "constexpr" permet de définir une constante dont la valeur doit obligatoirement être connue à la compilation
	// note: le compilateur peut faire des calculs simples: ( + - * / % )
	constexpr size_t C1 = 5 + 5;
	constexpr size_t C2 = C1 * 2;
	constexpr size_t C3 = C2 / 4;

	// soit la variable
	size_t size;


	// 1D) allocation d'un tableau à 1 dimension
	size = 5;
	int (*tab1D) = new int [size] {};	// init à zéro

	tab1D[0] = 10;			// accès


	// 2D) allocation d'un tableau à 2 dimensions
	size = 3;
	int (*tab2D) [C1] = new int [size][C1] {};	// init à zéro
		
	tab2D[0][0] = 20;		// accès


	// 3D) allocation d'un tableau à 3 dimensions
	size = 4;
	int (*tab3D) [C1][C2] = new int[size][C1][C2] {};	// init à zéro

	tab3D[0][0][0] = 30;	// accès


	// 4D) allocation d'un tableau à 4 dimensions
	size = 6;
	auto tab4D = new int[size][C1][C2][C3] {};	// laiser le compilateur déduire le type avec la clause "auto"

	tab4D[0][0][0][0] = 40;	// accès


	// FIN) désallocation de tous les tableaux
	delete[] tab1D;
	delete[] tab2D;
	delete[] tab3D;
	delete[] tab4D;

	_getch();
}