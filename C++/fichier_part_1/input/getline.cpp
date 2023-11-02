#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include <fstream>

#include "../../cvm 21.h"

using namespace std;

/*

	EXEMPLE D'UTILISATION DE LA FONCTION GETLINE ET SON D�LIMITEUR POUR EXTRAIRE UNE STRING DANS UN FICHIER TEXTE

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
		getline(f, textes[0], ',');		// lire les caract�res jusqu'au d�limiteur ',' inclusivement (ou la fin de fichier). Mais le d�limiteur ',' n'est pas ajout� � la string textes[i]
		getline(f, textes[1], ',');
		getline(f, textes[2]);			// par d�faut, le d�limiteur est '\n'
		getline(f, textes[3]);
		f.close();
	}
	else
		cout << "file not found !" << endl;

	_getch();
}