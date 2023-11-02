#pragma once

#include <string>

using namespace std; // ne pas oublier ici pour string

enum Combustible { essence, diesel, hydrog�ne, �thanol };

using ChevalVapeur = double;

using Litre = double;

struct Moteur
{
	Combustible carburant;
	ChevalVapeur puissance;

	string marque; // une d�pendance au type string ==> #include <string> dans ce fichier d'en-t�te
};