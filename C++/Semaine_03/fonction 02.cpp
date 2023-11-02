#include <iostream>
#include <conio.h>

using namespace std;

void afficher_le_diamètre_de_la_terre()
{
	using KM = double;
	
	const double PI = 3.141592;
	const KM circonférence = 40075.017;

	KM diamètre = circonférence / PI;

	cout << "Le diam\x8atre \x82quatorial de la Terre = " << diamètre << " km" << endl;
}

int main()
{
	// ...
	afficher_le_diamètre_de_la_terre(); // déléguer à cette fonction la tâche d'afficher le diamètre de la Terre
	// ...

	// la fonction appelée est   :  afficher_le_diamètre_de_la_terre();
	// la fonction appelante est :  main()

	_getch();
}