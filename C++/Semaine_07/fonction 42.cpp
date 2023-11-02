#include <iostream>
#include <conio.h>

using namespace std;

/*
	LA FONCTION ET LE TABLEAU PASSÉ EN PARAMÈTRE (SYNTAXE ALTERNATIVE)
*/

void shift_left(int* t, size_t size)	// t contient l'adresse du tableau T de main
{
	int temp = t[0];
	for (size_t i = 0; i < size-1; ++i)
		t[i] = t[i+1];
	t[size-1] = temp;
}

int main()
{
	const size_t size = 10;
	int T[size] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	
	shift_left(T,size);					// tableau final --> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }

	_getch();
}