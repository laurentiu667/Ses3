#include <iostream>
#include <conio.h>

using namespace std;

void afficher_le_diam�tre_de_la_terre()
{
	using KM = double;
	
	const double PI = 3.141592;
	const KM circonf�rence = 40075.017;

	KM diam�tre = circonf�rence / PI;

	cout << "Le diam\x8atre \x82quatorial de la Terre = " << diam�tre << " km" << endl;
}

int main()
{
	// ...
	afficher_le_diam�tre_de_la_terre(); // d�l�guer � cette fonction la t�che d'afficher le diam�tre de la Terre
	// ...

	// la fonction appel�e est   :  afficher_le_diam�tre_de_la_terre();
	// la fonction appelante est :  main()

	_getch();
}