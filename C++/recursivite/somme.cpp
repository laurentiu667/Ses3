#include <iostream>
#include <conio.h>

using namespace std;

/*
	SOMME
	som(n) = n + (n-1) + (n-2) + ... + 1;
*/


// Exemples itératif et récursif pour le calcul de la somme
// note: débordement non gérée

uint64_t som(uint64_t n) { return n * (n+1) / 2; }

uint64_t som_i(uint64_t n)
{
	uint64_t r;
	for (r = 0; n > 0; --n)
		r += n;
	return r;
}

uint64_t som_r(uint64_t n)		
{
	if (n == 0)
		return 0;
	else
		return n + som_r(n-1);
}

int main()
{
	uint64_t n = 22000;
	cout << som_i(n) << endl;
	cout << som_r(n) << endl;
	_getch();
}