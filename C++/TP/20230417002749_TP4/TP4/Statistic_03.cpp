#include "Sondage.h"
double stat_03(int r2[], Repondant rep[]) {
	double stocked = 0;
	int Personne = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (rep[i].age >= 30 and rep[i].age < 40)
		{
			stocked += r2[i];
			Personne++;
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