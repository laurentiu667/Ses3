// aucune d�pendance sur les librairies standards

#include "voiture.h" // inclure son propre fichier d'en-t�te

using namespace std;

KM autonomie_en_ville(Voiture &v)				// une d�pendance au type Voiture et KM
{
	return v.r�servoir_max / v.conso_ville * 100;
}

KM autonomie_sur_route(Voiture &v)
{
	return v.r�servoir_max / v.conso_route * 100;
}

LitresAu100KM consommation_moyenne(Voiture &v, KM distance_parcourue)
{
	return ( v.r�servoir_max - v.r�servoir ) / distance_parcourue * 100;
}