#include <iostream>
#include <conio.h>

using namespace std;

/*
	FACTORIELLE

	la factorielle d'un entier naturel n (n!) est le produit des nombres entiers strictement positifs inférieurs ou égaux à n.

	n! = n * (n-1) * (n-2) * ... * 1;
	
	donc
	
	n! = n * (n-1)!
	0! = 1				-- par convention


	ex:

	5! = 5 * 4 * 3 * 2 * 1
	5! = 120

*/


// Exemples itératif et récursif pour le calcul de la fonction factorielle
// note: débordement non gérée


uint64_t facto_i(uint64_t n)		// solution itérative
{
	uint64_t r;
	for (r = 1; n > 1; r *= n--);
	return r;
}

uint64_t facto_r(uint64_t n)		// solution récursive:  n! = n * (n-1)!
{
	if (n == 0 || n == 1)
		return 1;
	else
		return n * facto_r(n-1);	
}

int main()
{
	cout << facto_i(20) << endl;
	cout << facto_r(20) << endl;
	_getch();
}