// aucune dépendance sur les librairies standards

#include "bateau.h" // inclure son propre fichier d'en-tête

using namespace std;

Heures autonomie_en_vitesse_de_croisière(Bateau &b)
{
	return b.réservoir_max / b.conso_en_vitesse_de_croisière;
}

Heures autonomie_plein_gaz(Bateau &b)
{
	return b.réservoir_max / b.conso_plein_gaz;
}

LitresParHeure consommation_moyenne(Bateau &b, Heures durée)
{
	return ( b.réservoir_max - b.réservoir ) / durée ;
}