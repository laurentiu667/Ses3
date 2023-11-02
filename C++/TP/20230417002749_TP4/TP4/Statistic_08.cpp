#include "Sondage.h"
int stat_08(Infection info[], char r4[]) {
	int stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)
	{
		if (info[i].r10 == 0 and info[i].r8 == 1)
			if (r4[i] == 'O')
			{
				stocked++;
			}
	}
	return stocked;
}