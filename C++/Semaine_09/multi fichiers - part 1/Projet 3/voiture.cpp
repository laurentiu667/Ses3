// aucune dépendance sur les librairies standards

#include "voiture.h" // inclure son propre fichier d'en-tête

using namespace std;

KM autonomie_en_ville(Voiture &v)				// une dépendance au type Voiture et KM
{
	return v.réservoir_max / v.conso_ville * 100;
}

KM autonomie_sur_route(Voiture &v)
{
	return v.réservoir_max / v.conso_route * 100;
}

LitresAu100KM consommation_moyenne(Voiture &v, KM distance_parcourue)
{
	return ( v.réservoir_max - v.réservoir ) / distance_parcourue * 100;
}