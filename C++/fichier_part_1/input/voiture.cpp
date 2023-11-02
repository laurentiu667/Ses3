#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include <fstream>

#include "../../cvm 21.h"

using namespace std;

struct Voiture
{
	string marque;
	string modele;
	string couleur;
	int annee;
	int km;
	double prix;
};

int main()
{
	setcp(1252);
	
	fstream f;

	string fname = "voiture.txt";

	Voiture v;

	f.open(fname, ios::in);
	if (f.is_open())
	{
		f >> v.marque >> v.modele >> v.couleur >> v.annee >> v.km >> v.prix;	// valeurs séparées par au moins un blanc dans le fichier (blanc = ' ' ou '\t' ou '\n') 
		f.close();
	}
	else
		cout << "file not found !" << endl;

	_getch();
}