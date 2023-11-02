#include "Sondage.h"
string stat_07(Infection info[]) {

	const string desinfectant[6]{ "Je n’utilise pas de désinfectant", "Savon à vaisselle", "Purell", "Eau de javel", "Alcool à friction", "inconnu" };
	int stock[5]{ 1,2,3,4,5 }; int stocked[5][1] = { {0}, {0}, {0}, {0}, {0} };
	int max_val = -1, max_idx = -1;

	for (size_t i = 0; i < nb_repondants; i++)
	{
		for (size_t j = 0; j < 5; j++)
			if (info[i].r8 == stock[j])
				stocked[j - 1][1]++;
	}
	// Trouver le nombre du array 2D le plus grand
	for (size_t i = 0; i < 5; i++)
	{
		if (stocked[i][0] > max_val)
		{
			max_val = stocked[i][0];
			max_idx = i;
		}
	}
	if (nb_repondants == 0)
	{
		return desinfectant[5];
	}
	else
	{
		return desinfectant[max_idx];
	}
}