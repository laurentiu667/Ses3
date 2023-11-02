#pragma once

#include "moteur.h"


using Heures = double;

using Noeuds = double;

using LitresParHeure = double;


struct Bateau
{
	Moteur moteur;				// une dépendance au type Moteur ==> #include "moteur.h"

	Litre réservoir_max;		// une dépendance au type Litre ==> #include "moteur.h"

	LitresParHeure conso_plein_gaz;
	LitresParHeure conso_en_vitesse_de_croisière;

	Noeuds vitesse_max;

	Litre réservoir; // quantité actuelle
};


// déclarations

Heures autonomie_plein_gaz(Bateau &b);

Heures autonomie_en_vitesse_de_croisière(Bateau &b);

LitresParHeure consommation_moyenne(Bateau &b, Heures durée);