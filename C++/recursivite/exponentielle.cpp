#include <iostream>
#include <conio.h>

using namespace std;

/*
	EXPONENTIELLE

	b: base  	e: exposant

       e
	(b)  = b * b * b * ... * b
		   ------ e fois -----

       0
	(b)  = 1   // par convention


	ex:
	
	   3
	(2)  = 2 * 2 * 2 = 8

*/

// Exemples itératif et récursif pour le calcul de la fonction exponentielle
// note: débordement non gérée

uint64_t exp_i(uint64_t base, uint64_t exp)		// solution itérative
{
	uint64_t r = 1;
	for (uint64_t e = 0; e < exp; ++e)
		r *= base;
	return r;
}

uint64_t exp_r(uint64_t base, uint64_t exp)		// solution récursive
{
	if (exp == 0)
		return 1;
	else
		return base * exp_r(base, exp-1);
}

int main()
{
	uint64_t b = 7, e = 15;
	cout << exp_r(b,e) << endl;
	cout << exp_i(b,e) << endl;
	_getch();
}