#include <iostream>
#include <conio.h>
using namespace std;

/*
	ALLOCATION DYNAMIQUE DES TABLEAUX � PLUSIEURS DIMENSIONS

	1) allocation en m�moire dans un espace d'adresses contigu�s

	2) syntaxe:

		new Type [size][CONSTANTE]...[CONSTANTE];

	3) la taille (size) de la premi�re dimension est dynamique, les autres doivent �tre d�termin�es � la compilation


	4) alternativement, il est toujours possible d'allouer un tr�s grand tableau � une seule dimension et de g�r�r manuellement
	l'organisation int�rieure (les dimensions) et la fa�on d'y acc�der

*/

int main()
{
	// la clause "constexpr" permet de d�finir une constante dont la valeur doit obligatoirement �tre connue � la compilation
	// note: le compilateur peut faire des calculs simples: ( + - * / % )
	constexpr size_t C1 = 5 + 5;
	constexpr size_t C2 = C1 * 2;
	constexpr size_t C3 = C2 / 4;

	// soit la variable
	size_t size;


	// 1D) allocation d'un tableau � 1 dimension
	size = 5;
	int (*tab1D) = new int [size] {};	// init � z�ro

	tab1D[0] = 10;			// acc�s


	// 2D) allocation d'un tableau � 2 dimensions
	size = 3;
	int (*tab2D) [C1] = new int [size][C1] {};	// init � z�ro
		
	tab2D[0][0] = 20;		// acc�s


	// 3D) allocation d'un tableau � 3 dimensions
	size = 4;
	int (*tab3D) [C1][C2] = new int[size][C1][C2] {};	// init � z�ro

	tab3D[0][0][0] = 30;	// acc�s


	// 4D) allocation d'un tableau � 4 dimensions
	size = 6;
	auto tab4D = new int[size][C1][C2][C3] {};	// laiser le compilateur d�duire le type avec la clause "auto"

	tab4D[0][0][0][0] = 40;	// acc�s


	// FIN) d�sallocation de tous les tableaux
	delete[] tab1D;
	delete[] tab2D;
	delete[] tab3D;
	delete[] tab4D;

	_getch();
}