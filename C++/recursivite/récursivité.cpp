#include <iostream>
#include <conio.h>

using namespace std;

/*

 forme générale d'une fonction récursive

	f(n)  =  n  op  f(n-1)

	où n est l'exemplaire à évaluer

	où op est une opération quelconque, complexe ou non

	où f(n-1) est une solution pour l'exemplaire plus petit (n-1)


autrement dit:
	
	si j'ai une solution pour f(n-1) alors je peux obtenir une solution pour f(n) en appliquant
	
	n et une opération (op) sur f(n-1)

*/

void fct_récursive(size_t n)
{
	if (n == 0)					// une condition qui permettra d'arrêter le rappel récursif
	{
		// ...
	}
	else
	{
		// ...

		fct_récursive(n - 1);	// appel récursif

		//...
	}
}


int main()
{
	fct_récursive(20);
	_getch();
}