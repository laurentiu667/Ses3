#include <iostream>
#include <iomanip>

#include "cvm 21.h"			// gotoxy
#include "triangle.h"		// type triangle

using namespace std;

size_t largeur(triangle t)
{ 
	return t.haut * 2 - 1;
}

size_t aire(triangle t)
{
	return ( t.haut * largeur(t) + t.haut ) / 2;
}

void show(triangle t, char c)
{
	cout << setfill(c);
	cout << endl << "Dimension:  H = " << t.haut << ", L = " << largeur(t) << "\n\n";

	size_t ga = t.haut;
	for (size_t l = 0, y = wherey(); l < t.haut; ++l)
	{
		gotoxy(--ga, y++); cout << setw(l*2+1) << c;
	}
	cout << endl;
}