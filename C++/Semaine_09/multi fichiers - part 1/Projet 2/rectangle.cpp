#include <iostream>
#include <iomanip>

#include "rectangle.h" // type rectangle

using namespace std;

size_t aire(rectangle r)
{
	return r.haut * r.larg;
}

bool est_un_carré(rectangle r)
{
	if (r.haut == r.larg) return true;
	return false;
}

void show(rectangle r, char c)
{
	cout << endl << "Dimension:  H = " << r.haut << ", L = " << r.larg << "\n\n";
	
	cout << setfill(c);
	for (size_t h = 1; h < r.haut; ++h)
		cout << setw(r.larg) << "" << endl;
}