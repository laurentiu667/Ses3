#include <iostream>
#include <conio.h>

using namespace std;

/*

 UTILISATION PRÉCISE DES PARAMÈTRES POUR ÉVITER UN PASSAGE D'INFORMATIONS INUTILES

	1) règle générale, il faut fabriquer les paramètres d'une fonction, de sorte qu'ils renseigent sur l'informations essentielles que la fonction
	  nécessite pour faire sa tâche.
	
		
	2) passer trop d'informations, est une mauvaise pratique en général

 */


struct Dimension
{
	double largeur;
	double longueur;
};

struct Habitation
{
	Dimension terrain;
	Dimension batiment;

	int étages;
	double prix;
};


double surface_terrain(Habitation hab)		// BOF		: paramètre de type Habitation qui inclus des informations inutiles pour cette fonction
{
	return hab.terrain.largeur * hab.terrain.longueur;
}

double surface_terrain(Dimension terrain)	// MIEUX	: paramètre plus précis, seulement le terrain
{
	return terrain.largeur * terrain.longueur;
}

double surface(Dimension dm)				// PARFAIT	: généralisation de la fonction avec un meilleur nom qui peut calculer la surface de toute Dimension
{
	return dm.largeur * dm.longueur;
}


int main()
{
	Habitation hab = { {30,90}, {30,60}, 3, 1000000 };

	//...

	cout << surface_terrain(hab) << endl;

	cout << surface_terrain(hab.terrain) << endl;

	cout << surface(hab.terrain) << endl;
	cout << surface(hab.batiment) << endl;

	_getch();
}