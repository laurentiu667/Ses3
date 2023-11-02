#include "Sondage.h"
double stat_09(Repondant rep[], int r2[], Infection info[]) {
	double stocked = 0;
	int Personne = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (rep[i].ville == "Montréal" and info[i].r9 == 1)
		{
			if (r2[i] == 0 or info[i].r8 == 1)
			{
				stocked += rep[i].scolarite;
				Personne++;
			}
		}
	}
	if (stocked == 0)
	{
		stocked = 0;
	}
	else
	{
		stocked /= Personne;
	}

	return stocked;
}