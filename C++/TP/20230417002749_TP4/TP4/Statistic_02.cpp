#include "Sondage.h"
int stat_02(char r3[]) {
	int stocked = 0;
	for (size_t i = 0; i < nb_repondants; i++)
		if (r3[i] == 'O')
		{
			stocked++;
		}
	return stocked;
}