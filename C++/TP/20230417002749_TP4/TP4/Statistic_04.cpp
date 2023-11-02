#include "Sondage.h"
double stat_04(char r5[], char r6[], Repondant rep[]) {
	double stocked = 0;
	int Personne = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (r5[i] == 'O' or r6[i] == 'O')
		{
			stocked += rep[i].age;
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