#include "Sondage.h"
double stat_05(int r2[], Repondant rep[]) {
	double stocked = 0;
	double Personne = 0;
	double persvaudr = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (rep[i].ville == "Vaudreuil")
		{
			persvaudr++;
			if (r2[i] > 1)
			{
				Personne++;
			}
		}
	}

	if (persvaudr >= 1)
	{
		stocked = (Personne / persvaudr) * 100;
	}
	else
	{
		stocked = 0;
	}
	return stocked;
}