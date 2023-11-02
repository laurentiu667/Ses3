// aucune d�pendance sur les librairies standards

#include "bateau.h" // inclure son propre fichier d'en-t�te

using namespace std;

Heures autonomie_en_vitesse_de_croisi�re(Bateau &b)
{
	return b.r�servoir_max / b.conso_en_vitesse_de_croisi�re;
}

Heures autonomie_plein_gaz(Bateau &b)
{
	return b.r�servoir_max / b.conso_plein_gaz;
}

LitresParHeure consommation_moyenne(Bateau &b, Heures dur�e)
{
	return ( b.r�servoir_max - b.r�servoir ) / dur�e ;
}