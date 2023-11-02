#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

#include "bateau.h"
#include "voiture.h"

using namespace std;

int main()
{
	cout << fixed << setprecision(2);
	
	Voiture v = { { essence, 220, "VW" }, 45, 9.8, 8.6, 200 , 30 };				// une dépendance au type Voiture ==> #include "voiture.h"

	cout << "Voiture" << endl;
	cout << "Autonomie en ville   : " << autonomie_en_ville(v) << " km" << endl;
	cout << "Autonomie sur route  : " << autonomie_sur_route(v) << " km" << endl;
	cout << "Consommation moyenne : " << consommation_moyenne(v, 160) << " L/100km" << endl << endl;


	Bateau b = { { diesel, 320, "Mercury" }, 450, 71.0, 17.6, 26 , 340 };		// une dépendance au type Bateau ==> #include "bateau.h"

	cout << "Bateau" << endl;
	cout << "Autonomie en croisiere : " << autonomie_en_vitesse_de_croisière(b) << " heures" << endl;
	cout << "Autonomie vitesse max  : " << autonomie_plein_gaz(b) << " heures" << endl;
	cout << "Consommation moyenne   : " << consommation_moyenne(b, 3) << " L/heure" << endl;

	_getch();
}