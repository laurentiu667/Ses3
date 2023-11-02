#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include <fstream> // pour le type fstream qui permet de manipuler un fichier

#include "../../cvm 21.h"

/*
	Programme exemple pour l'écriture d'un fichier texte.
	
	REM: Le '\n' (ou le "endl") est écrit dans le fichier texte avec 2 caractères : CR (13 ou 0D) et LF (10 ou 0A).

	REM: écrire dans un fichier est similaire à écrire à la console avec la commande cout et ses manipulateurs
*/

using namespace std;

const int D = 7;

string sky[] = { "ensoleillé", "nuageux", "pluvieux", "orageux" };
string week[] = { "dimanche", "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi" };

struct Meteo
{
	int max;
	string sky;
};

struct Forecast
{
	Meteo days[D];
};

void init(Forecast& fc)
{
	for (int d = 0; d < D; ++d)
		fc.days[d] = { rand()%10 + 20, sky[rand()%4] };
}

void write(fstream& file, Forecast& fc)	// file ici doit absolument être une référence
{
	int larg = 12;
	file << left << endl;

	file << setw(larg) << "jour" << setw(larg) << "max" << setw(larg) << "ciel" << setw(larg) << endl;
	file << setw(larg) << "----" << setw(larg) << "---" << setw(larg) << "----" << setw(larg) << endl;

	for (int j = 0; j < 7; ++j)
	{
		file << setw(larg) << week[j] << setw(larg) << fc.days[j].max << setw(larg) << fc.days[j].sky << endl;
	}
}

void save(string fname, bool erase, Forecast& fc)
{
	fstream file;

	if (erase)
		file.open(fname, ios::out);	// mode "output" ==> cré (ou recré) un nouveau fichier vide
	else
		file.open(fname, ios::app);	// mode "append" ==> ajoute à la fin du fichier s'il existe, sinon le cré

	if (file.is_open())
	{
		write(file, fc);
		file.close();
	}
}

int main()
{
	setcp(1252);
	srand(int(time(0)));

	string fname = "output 02.txt";

	Forecast fc;

	init(fc);
	save(fname, true, fc);

	init(fc);
	save(fname, false, fc);

	cout << "Prévisions terminées ! ...";  _getch();
}