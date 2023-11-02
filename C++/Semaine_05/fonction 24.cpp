#include <iostream>
#include <conio.h>

using namespace std;

/*

 UTILISATION DES PARAMÈTRES RÉFÉRENCES POUR ÉVITER UNE PASSAGE PAR VALEUR COUTEUX 

	1) il est possible d'utiliser les paramètres références pour atténuer le coût d'un passage par valeur qui implique de copier l'information
	
	2) il est aussi possible d'utiliser "const" pour garantir que le paramètre ne sera pas modifié

 */

const int MAX = 20;

struct Mesure
{
	double température;
	double pression;
	double humidité;
	double vent;
	double rafale;
};

struct StationMétéo
{
	int cpt;
	Mesure mesures[MAX];
};


void mesurer(StationMétéo& sm)					// simulateur des mesures
{
	for (int m = 0; m < MAX; ++m)
	{
		//...
		sm.mesures[m].rafale = rand() % (200+1); // une mesure aléatoire, en km/h, d'une rafale
	}
	sm.cpt = MAX;
}


/*

exemple: trouver la rafale maximum

3 déclarations possibles de la fonction rafale_max()

	double rafale_max(StationMétéo sm);			// --> coûteuse copie de "station" de main, vers le paramètre "sm"

	double rafale_max(StationMétéo& sm);		// --> sm est une référence sur "station" de main, donc aucune copie

	double rafale_max(const StationMétéo& sm);	// --> sm est une référence constante sur "station" de main, donc sm ne peut être modifié par la fonction "rafale_max"

*/


double rafale_max(const StationMétéo& sm)
{
	double max = sm.mesures[0].rafale;

	for (int m = 1; m < sm.cpt; ++m)
		if (max < sm.mesures[m].rafale)
			max = sm.mesures[m].rafale;

	return max;
}


int main()
{
	StationMétéo station = {};

	mesurer(station);							// simulation des mesures

	cout << rafale_max(station);

	_getch();
}