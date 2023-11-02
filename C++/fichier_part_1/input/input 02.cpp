/*
	2 exemples pour la lecture d'un fichier texte

	==> mot par mot
	==> ligne par ligne

	REM:	Le '\n' est repr�sent� dans le fichier texte par 2 caract�res : LF (10) et CR (13).
			Ces deux caract�res sont lus comme un seul caract�re et seulement le LF (10) est retourn�.
			'\n' est �quivalent � LF
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include <fstream>

#include "../../cvm 21.h"

using namespace std;

// lire le fichier texte f

// mot par mot avec l'op�rateur ">>"  ( utilisation du manipulateur "skipws" seulement )

void lireFichierTexte_ex3(fstream &f)
{
	cout << "\n" << "3) mot par mot avec l'op�rateur >>" << "\n\n";

	string mot;

	f >> skipws;						// Att : f >> noskipws	==> ne marche pas avec les string car ignore toujours les blancs, tab et endl

	while (f >> mot)					// devient faux lorsque la fin du fichier est atteint  ==> donc f.fail() est vrai
		cout << mot << " ";

	f.clear();							// � faire car f.fail() est vrai maintenant
}


// lire f : ligne par ligne avec getline()
void lireFichierTexte_ex4(fstream &f)
{
	cout << "\n\n" << "4) ligne par ligne avec la fonction getline()" << "\n\n";

	string ligne;

	while (getline(f,ligne))			// Att : le caract�re '\n' n'est pas ajout� � la variable ligne.  getline devient faux lorsque la fin du fichier est atteint  ==> donc f.fail() est vrai
		cout << ligne << "\n";

	f.clear();							// � faire car f.fail() est vrai maintenant
}

void reset(fstream& f)
{
	f.clear();							// � faire car si f.fail() est vrai alors f.seekg() ne marchera pas
	f.seekg(0, ios::beg);				// pour remettre le curseur de lecture au d�but du fichier f
}

int main()
{
	setcp(1252);

	fstream f;

	string fname = "input 01.txt";

	f.open(fname, ios::in);				// mode "input" ==> ouvre le fichier et place le curseur de lecture au d�but du fichier
	if (f.is_open())
	{
		lireFichierTexte_ex3(f); reset(f);
		lireFichierTexte_ex4(f); reset(f);
		f.close();
	}
	else
	{
		cout << "le fichier: \"" << fname << "\" n'a pu �tre ouvert" << endl;
	}

	cout << "\n\n" << "D�mo termin�e ! ...";  _getch();
}