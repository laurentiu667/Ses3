/*
	2 exemples pour la lecture d'un fichier texte

	==> mot par mot
	==> ligne par ligne

	REM:	Le '\n' est représenté dans le fichier texte par 2 caractères : LF (10) et CR (13).
			Ces deux caractères sont lus comme un seul caractère et seulement le LF (10) est retourné.
			'\n' est équivalent à LF
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include <fstream>

#include "../../cvm 21.h"

using namespace std;

// lire le fichier texte f

// mot par mot avec l'opérateur ">>"  ( utilisation du manipulateur "skipws" seulement )

void lireFichierTexte_ex3(fstream &f)
{
	cout << "\n" << "3) mot par mot avec l'opérateur >>" << "\n\n";

	string mot;

	f >> skipws;						// Att : f >> noskipws	==> ne marche pas avec les string car ignore toujours les blancs, tab et endl

	while (f >> mot)					// devient faux lorsque la fin du fichier est atteint  ==> donc f.fail() est vrai
		cout << mot << " ";

	f.clear();							// à faire car f.fail() est vrai maintenant
}


// lire f : ligne par ligne avec getline()
void lireFichierTexte_ex4(fstream &f)
{
	cout << "\n\n" << "4) ligne par ligne avec la fonction getline()" << "\n\n";

	string ligne;

	while (getline(f,ligne))			// Att : le caractère '\n' n'est pas ajouté à la variable ligne.  getline devient faux lorsque la fin du fichier est atteint  ==> donc f.fail() est vrai
		cout << ligne << "\n";

	f.clear();							// à faire car f.fail() est vrai maintenant
}

void reset(fstream& f)
{
	f.clear();							// à faire car si f.fail() est vrai alors f.seekg() ne marchera pas
	f.seekg(0, ios::beg);				// pour remettre le curseur de lecture au début du fichier f
}

int main()
{
	setcp(1252);

	fstream f;

	string fname = "input 01.txt";

	f.open(fname, ios::in);				// mode "input" ==> ouvre le fichier et place le curseur de lecture au début du fichier
	if (f.is_open())
	{
		lireFichierTexte_ex3(f); reset(f);
		lireFichierTexte_ex4(f); reset(f);
		f.close();
	}
	else
	{
		cout << "le fichier: \"" << fname << "\" n'a pu être ouvert" << endl;
	}

	cout << "\n\n" << "Démo terminée ! ...";  _getch();
}