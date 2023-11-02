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

int main()
{
	setcp(1252);

	fstream f;

	string fname = "output 01.txt";

	f.open(fname, ios::out);				// mode "output" ==> cré (ou recré) un nouveau fichier vide
	if (f.is_open())
	{

		double montant = 100.00;
		double tps = montant * 0.05, tvq = montant * 0.09975;
		double total = montant + tps + tvq;

		f << fixed << setprecision(2) << right << "\n";

		f << "Détails de la facture" << "\n";
		f << "---------------------" << "\n\n";

		f << "Montant : " << setw(7) << montant << " $" << "\n\n";

		f << "    tps : " << setw(7) << tps << " $" << "\n\n";
		f << "    tvq : " << setw(7) << tvq << " $" << "\n\n";

		f << "Total   : " << setw(7) << total << " $";

		f.close();							// ferme le fichier

		cout << "écriture terminée !";
	}
	else
		cout << "impossible de créer ou d'ouvrir le fichier " << fname;

	_getch();
}