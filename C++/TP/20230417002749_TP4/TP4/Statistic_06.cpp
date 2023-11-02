#include "Sondage.h"
double stat_06(Infection info[]) {
	double stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (info[i].r8 == 1)
		{
			stocked++;
		}
	}
	if (stocked == 0)
	{
		stocked = 0;
	}
	else
	{
		stocked = (stocked / nb_repondants) * 100;
	}
	return stocked;
}