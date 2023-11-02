#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cvm 21.h"
#include "Sondage.h"
#include "Statistic_01.h"
#include "Statistic_02.h"
#include "Statistic_03.h"
#include "Statistic_04.h"
#include "Statistic_05.h"
#include "Statistic_06.h"
#include "Statistic_07.h"
#include "Statistic_08.h"
#include "Statistic_09.h"
#include "Statistic_10.h"

using namespace std;

int main()
{
	setcp(1252);

	name = "C21-TP3-Sondage.txt";											// exemple avec un path "C:/dossier/C21-TP3-Sondage.txt"

	// Pour recevoir les donn�es du sondage
	bool* r1 = new bool[REPONDANTS_MAX] {};					// pour la  r�ponse  1
	Protection* pro = new Protection{};					// pour les r�ponses 2-3-4-5-6
	Infection* inf = new Infection[REPONDANTS_MAX]{};		// pour les r�ponses 7-8-9-10
	Repondant* rep = new Repondant[REPONDANTS_MAX]{};		// pour les r�ponses ville, age, scolarit�

	// A - charger les donn�es du sondage

	nb_repondants = lireLesDonn�esDuSondage(r1, pro, inf, rep);

	// Affichage //
	clrscr();
	cout << fixed << setprecision(1)
		<< "R�sultats du sondage :  ( " << nb_repondants << " )\n\n"
		<< "Statistiques\n\n"
		<< "1. Combien de personnes toussent souvent ?\n"
		<< "2. Combien de personnes veulent un masque dans leur auto ?\n"
		<< "3. Combien de masques, en moyenne, ont les gens qui sont dans la trentaine ?\n"
		<< "4. Quel est l'�ge moyen des gens qui se serviraient d�un masque pour d�corer ou pour dormir ?\n"
		<< "5. Quel pourcentage des gens de Vaudreuil poss�dent plus d'un masque ?\n"
		<< "6. Quel pourcentage de la population utilise du d�sinfectant ?\n"
		<< "7. Quel est le type de d�sinfectant le plus r�pandu ?\n"
		<< "8. Combien de gens non test�s et n�utilisant pas de d�sinfectant ont d�j� emprunt� un masque ?\n"
		<< "9. Combien d'ann�es de scolarit�, en moyenne, ont les gens infect�s de Montr�al sans masque ou sans d�sinfectant ?\n"
		<< "10. Quelle est la ville ayant fait subir le plus grand nombre de tests ?\n\n\n"

		<< "R�sultats\n\n";
	// B - appeler vos fonctions statistiques et afficher ici leurs r�sultats
	// ...
	cout << "01) = ";		cout << stat_01(r1);
	cout << "\n02) = ";		cout << stat_02(pro->r3);
	cout << "\n03) = ";		cout << stat_03(pro->r2, rep);
	cout << "\n04) = ";		cout << stat_04(pro->r5, pro->r6, rep);
	cout << "\n05) = ";		cout << stat_05(pro->r2, rep); cout << " %";
	cout << "\n06) = ";		cout << stat_06(inf); cout << " %";
	cout << "\n07) = ";		cout << stat_07(inf);
	cout << "\n08) = ";		cout << stat_08(inf, pro->r4);
	cout << "\n09) = ";		cout << stat_09(rep, pro->r2, inf);
	cout << "\n10) = ";		cout << stat_10(rep, inf);

	_getch();

	// C - Recycler les allocations dynamiques
	delete[] r1;
	delete pro;
	delete[] inf;
	delete[] rep;
}