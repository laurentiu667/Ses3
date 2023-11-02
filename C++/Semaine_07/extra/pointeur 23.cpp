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

	Data** T = new Data* [size] {};					// cr�er le tableau T de pointeurs sur des Data, tous initialis�s � nullptr

	for (size_t i = 0; i < size; ++i)				// cr�er les Data, un par un, et enregistrer leur adresse respective dans T
	{
		T[i] = new Data;
		*T[i] = {};									// option: initialiser la structure Data
	}


	// 2) Traitements quelconques sur les Data

	for (size_t i = 0; i < size; ++i)
		if (T[i] != nullptr)						// v�rification prudante: est-ce un pointeur valide ?
		{
			T[i]->name = "un nom";
			T[i]->value = rand() % 100;
		}


	// 3) Recyclage

	for (int i = 0; i < size; ++i)					// d�truire d'abord chaque Data, un par un, � l'aide de son adresse en T[i]
		delete T[i];								// note: delete nullptr ne provoque pas d'erreur

	delete [] T;									// d�truire ensuite le tableau

	_getch();
}