#include <iostream>
#include <conio.h>

using namespace std;

/*

 forme g�n�rale d'une fonction r�cursive

	f(n)  =  n  op  f(n-1)

	o� n est l'exemplaire � �valuer

	o� op est une op�ration quelconque, complexe ou non

	o� f(n-1) est une solution pour l'exemplaire plus petit (n-1)


autrement dit:
	
	si j'ai une solution pour f(n-1) alors je peux obtenir une solution pour f(n) en appliquant
	
	n et une op�ration (op) sur f(n-1)

*/

void fct_r�cursive(size_t n)
{
	if (n == 0)					// une condition qui permettra d'arr�ter le rappel r�cursif
	{
		// ...
	}
	else
	{
		// ...

		fct_r�cursive(n - 1);	// appel r�cursif

		//...
	}
}


int main()
{
	fct_r�cursive(20);
	_getch();
}