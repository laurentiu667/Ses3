#include <iostream>
#include <conio.h>

using namespace std;

/*

 UTILISATION DES PARAM�TRES R�F�RENCES POUR �VITER UNE PASSAGE PAR VALEUR COUTEUX 

	1) il est possible d'utiliser les param�tres r�f�rences pour att�nuer le co�t d'un passage par valeur qui implique de copier l'information
	
	2) il est aussi possible d'utiliser "const" pour garantir que le param�tre ne sera pas modifi�

 */

const int MAX = 20;

struct Mesure
{
	double temp�rature;
	double pression;
	double humidit�;
	double vent;
	double rafale;
};

struct StationM�t�o
{
	int cpt;
	Mesure mesures[MAX];
};


void mesurer(StationM�t�o& sm)					// simulateur des mesures
{
	for (int m = 0; m < MAX; ++m)
	{
		//...
		sm.mesures[m].rafale = rand() % (200+1); // une mesure al�atoire, en km/h, d'une rafale
	}
	sm.cpt = MAX;
}


/*

exemple: trouver la rafale maximum

3 d�clarations possibles de la fonction rafale_max()

	double rafale_max(StationM�t�o sm);			// --> co�teuse copie de "station" de main, vers le param�tre "sm"

	double rafale_max(StationM�t�o& sm);		// --> sm est une r�f�rence sur "station" de main, donc aucune copie

	double rafale_max(const StationM�t�o& sm);	// --> sm est une r�f�rence constante sur "station" de main, donc sm ne peut �tre modifi� par la fonction "rafale_max"

*/


double rafale_max(const StationM�t�o& sm)
{
	double max = sm.mesures[0].rafale;

	for (int m = 1; m < sm.cpt; ++m)
		if (max < sm.mesures[m].rafale)
			max = sm.mesures[m].rafale;

	return max;
}


int main()
{
	StationM�t�o station = {};

	mesurer(station);							// simulation des mesures

	cout << rafale_max(station);

	_getch();
}