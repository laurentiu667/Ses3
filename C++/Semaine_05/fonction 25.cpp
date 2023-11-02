#include <iostream>
#include <conio.h>

using namespace std;

/*

 UTILISATION PR�CISE DES PARAM�TRES POUR �VITER UN PASSAGE D'INFORMATIONS INUTILES

	1) r�gle g�n�rale, il faut fabriquer les param�tres d'une fonction, de sorte qu'ils renseigent sur l'informations essentielles que la fonction
	  n�cessite pour faire sa t�che.
	
		
	2) passer trop d'informations, est une mauvaise pratique en g�n�ral

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

	int �tages;
	double prix;
};


double surface_terrain(Habitation hab)		// BOF		: param�tre de type Habitation qui inclus des informations inutiles pour cette fonction
{
	return hab.terrain.largeur * hab.terrain.longueur;
}

double surface_terrain(Dimension terrain)	// MIEUX	: param�tre plus pr�cis, seulement le terrain
{
	return terrain.largeur * terrain.longueur;
}

double surface(Dimension dm)				// PARFAIT	: g�n�ralisation de la fonction avec un meilleur nom qui peut calculer la surface de toute Dimension
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