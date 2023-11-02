#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*
	ALLOCATION DYNAMIQUE D'UN TABLEAU DE POINTEURS

	tableau
	-------------------------------------------------------------			-------------
	|  adresse	|  adresse	|  adresse	|  adresse	|  adresse	|  ......	|  adresse	|
	-------------------------------------------------------------			-------------
		|			|			|			|			|						|
		|			|			|			|			|						|
		|			V			|			V			|						|
		|						|						|						|
		|		 nullptr		|		 nullptr		|						|
		|						|						|						|
		V						V						V						V
	-------------			-------------			-------------			-------------
	|   data	|			|   data	|			|   data	|			|	data	|
	-------------			-------------			-------------			-------------
*/

struct Data
{
	string name;
	double value;
};

int main()
{
	const size_t size = 5;

	// 1) Allocation dynamique du tableau

	Data** T = new Data* [size] {};					// créer le tableau T de pointeurs sur des Data, tous initialisés à nullptr

	for (size_t i = 0; i < size; ++i)				// créer les Data, un par un, et enregistrer leur adresse respective dans T
	{
		T[i] = new Data;
		*T[i] = {};									// option: initialiser la structure Data
	}


	// 2) Traitements quelconques sur les Data

	for (size_t i = 0; i < size; ++i)
		if (T[i] != nullptr)						// vérification prudante: est-ce un pointeur valide ?
		{
			T[i]->name = "un nom";
			T[i]->value = rand() % 100;
		}


	// 3) Recyclage

	for (int i = 0; i < size; ++i)					// détruire d'abord chaque Data, un par un, à l'aide de son adresse en T[i]
		delete T[i];								// note: delete nullptr ne provoque pas d'erreur

	delete [] T;									// détruire ensuite le tableau

	_getch();
}