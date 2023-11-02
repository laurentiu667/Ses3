#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include <fstream>

#include "../../cvm 21.h"

using namespace std;

/*

	EXEMPLE D'UTILISATION DE LA FONCTION GETLINE ET SON DÉLIMITEUR POUR EXTRAIRE UNE STRING DANS UN FICHIER TEXTE

*/

int main()
{
	setcp(1252);

	fstream f;

	string fname = "getline.txt";

	string textes[4];

	f.open(fname, ios::in);
	if (f.is_open())
	{
		getline(f, textes[0], ',');		// lire les caractères jusqu'au délimiteur ',' inclusivement (ou la fin de fichier). Mais le délimiteur ',' n'est pas ajouté à la string textes[i]
		getline(f, textes[1], ',');
		getline(f, textes[2]);			// par défaut, le délimiteur est '\n'
		getline(f, textes[3]);
		f.close();
	}
	else
		cout << "file not found !" << endl;

	_getch();
}