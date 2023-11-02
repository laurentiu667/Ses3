#include <iostream>
#include <conio.h>

#include "triangle.h"	// copiera ici le type triangle, et les déclarations des fonctions aire et afficher
#include "rectangle.h"	// copiera ici le type rectangle, et les déclarations des fonctions aire, est_un_carré et afficher

using namespace std;

int main()
{
	rectangle r = { 5, 10 };

	show(r, char(176));
	cout << endl << "Aire: " << aire(r) << endl;
	cout << endl << "Est-ce un carr\x82 ? : " << (est_un_carré(r) ? "oui" : "non") << " !" << endl << endl;


	triangle t = { 10 };

	show(t, char(178));
	cout << endl << "Aire: " << aire(t) << endl;

	_getch();
}