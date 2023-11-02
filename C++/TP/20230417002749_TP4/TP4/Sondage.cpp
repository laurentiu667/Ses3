#pragma once
#include "Sondage.h"
#include <fstream>
#include <windows.h>
using namespace std;

size_t nb_repondants;

string name;

size_t lireLesDonn�esDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[])
{
	fstream f(name, ios::in);

	if (f.fail()) // fichier ouvert ?
	{
		MessageBoxA(NULL, "Impossible d'ouvrir le fichier, Fin du programme", "Erreur", MB_OK | MB_ICONSTOP);
		exit(EXIT_FAILURE); // fin abrupte
	}

	char c;
	size_t r;
	for (r = 0; r < REPONDANTS_MAX; ++r)											// lire les r�ponses de chaque r�pondant
	{
		f >> c;	if (c == 'O') r1[r] = true; else r1[r] = false;						// r1
		f >> pro->r2[r] >> pro->r3[r] >> pro->r4[r] >> pro->r5[r] >> pro->r6[r];	// r2 � r6
		f >> c; if (c == 'O') inf[r].r7 = true; else inf[r].r7 = false;				// r7
		f >> inf[r].r8 >> inf[r].r9 >> inf[r].r10;									// r8 � r10
		f >> rep[r].ville >> rep[r].age >> rep[r].scolarite;						// ville, age, scolarit�
		if (f.fail()) { f.clear(); break; }
	}
	f.close();
	return r; // r = le nombre de r�pondants lus
}
