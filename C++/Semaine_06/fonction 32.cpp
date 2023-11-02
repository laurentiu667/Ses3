#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

// Tableau passé en paramètre

// permute deux éléments
void permuter(int &a, int &b) { int t = a; a = b; b = t; }


// touve l'indice p du plus petit élément du tableau T entre [debut .. fin-1]
size_t pmin(int T[], size_t debut, size_t fin)
{
	size_t p = debut;
	for (size_t i = debut; i < fin; ++i)
		if (T[i] < T[p])
			p = i;
	return p;
}


// 3) Tri par selection (du minimum à répétition)
// Algo:
// a) i = 0
// b) touver l'indice p du plus petit élément dans le sous tableau T [i .. size-1]
// c) permuter T[i] avec T[p]
// d) recommencer avec ++i

void trier(int T[], size_t size)
{
	for (size_t i = 0; i < size; ++i)
		permuter(T[i], T[pmin(T,i,size)]);
}


// 4) afficher le tableau
void afficher(int t[], size_t size)
{
	cout << "[ ";
	for (size_t m = 0; m < size; ++m) cout << t[m] << ", ";
	cout << "\b\b ]" << endl << endl;
}


// 5) initialiser le tableau avec des valeurs aléatoires entre [0..100]
void init(int T[], size_t size)
{
	for (size_t i = 0; i < size; i++) T[i] = rand() % 101;
}


int main()
{
	srand(uint32_t(time(0)));

	const int MAX = 25;
	int T1[MAX];

	init(T1,MAX);	afficher(T1,MAX);
	trier(T1,MAX);	afficher(T1,MAX);

	_getch();
}