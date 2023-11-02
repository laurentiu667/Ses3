#pragma once

#include "moteur.h"


using Heures = double;

using Noeuds = double;

using LitresParHeure = double;


struct Bateau
{
	Moteur moteur;				// une d�pendance au type Moteur ==> #include "moteur.h"

	Litre r�servoir_max;		// une d�pendance au type Litre ==> #include "moteur.h"

	LitresParHeure conso_plein_gaz;
	LitresParHeure conso_en_vitesse_de_croisi�re;

	Noeuds vitesse_max;

	Litre r�servoir; // quantit� actuelle
};


// d�clarations

Heures autonomie_plein_gaz(Bateau &b);

Heures autonomie_en_vitesse_de_croisi�re(Bateau &b);

LitresParHeure consommation_moyenne(Bateau &b, Heures dur�e);