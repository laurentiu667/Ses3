#include "Sondage.h"
int stat_01(bool r1[]) {
	int stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)
		if (r1[i] == true)
		{
			stocked++;
		}
	return stocked;
}