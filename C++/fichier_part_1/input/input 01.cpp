/*
	2 exemples pour la lecture d'un fichier texte ==> caractère par caractère
	
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

// 1) avec la fonction f.get()
void lireFichierTexte_ex1(fstream &f)		// ici f doit absolument être une référence sur le f de main
{
	cout << "\n" << "1) caractère par caractère avec la fonction get()" << "\n\n";

	char c;
	while (f.get(c))						// devient faux lorsque la fin du fichier est atteint  ==> donc f.fail() est vrai
		cout << c;

	f.clear();								// à faire car f.fail() est vrai maintenant
}


// 2) avec l'opérateur ">>"  ( utilisation des manipulateurs "skipws" ou "noskipws" )
void lireFichierTexte_ex2(fstream &f, bool skip)
{
	cout << "\n\n" << "2) caractère par caractère avec l'opérateur >> et le manipulateur " << (skip ? "skipws" : "noskipws") << "\n\n";

	char c;

	// "no skip white space"
	f >> ( skip ? skipws : noskipws );		// sans ce manipulateur la commande (f >> c) ignore les blancs, tab et endl (pour le remettre faire: f >> skipws;

	while (f >> c)							// devient faux lorsque la fin du fichier est atteint  ==> donc f.fail() est vrai
		cout << c;

	f.clear();								// à faire car f.fail() est vrai maintenant
}


void reset(fstream &f)
{
	f.clear();								// à faire car si f.fail() est vrai alors f.seekg() ne marchera pas
	f.seekg(0, ios::beg);					// pour remettre le curseur de lecture au début du fichier f
}


int main()
{
	setcp(1252);

	fstream f;

	string fname = "input 01.txt";

	f.open(fname, ios::in);					// mode "input" ==> ouvre le fichier et place le curseur de lecture au début du fichier
	if (f.is_open())
	{
		lireFichierTexte_ex1(f); reset(f);
		lireFichierTexte_ex2(f,false); reset(f);
		lireFichierTexte_ex2(f,true); reset(f);
		f.close();
	}
	else
	{
		cout << "le fichier: \"" << fname << "\" n'a pu être ouvert" << endl;
	}

	cout << "\n\n" << "Démo terminée ! ...";  _getch();
}