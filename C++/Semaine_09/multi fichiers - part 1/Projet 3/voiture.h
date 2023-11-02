#pragma once

#include "moteur.h"


using KM = double;

using KMH = double;

using LitresAu100KM = double;


struct Voiture
{
	Moteur moteur;				// une d�pendance au type Moteur ==> #include "moteur.h"

	Litre r�servoir_max;		// une d�pendance au type Litre ==> #include "moteur.h"

	LitresAu100KM conso_ville;
	LitresAu100KM conso_route;

	KMH vitesse_max;

	Litre r�servoir; // quantit� actuelle
};


// d�clarations

KM autonomie_en_ville(Voiture &v);

KM autonomie_sur_route(Voiture &v);

LitresAu100KM consommation_moyenne(Voiture &v, KM distance_parcourue);