#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// Tableau passé en paramètre

const size_t MAX = 10;

struct Participant
{
	string nom;
	size_t age;
	string ville;
};

struct Evenement
{
	size_t cpt = 0;
	Participant list[MAX] = {};
};

// DÉCLARATIONS
void init(Evenement& e);
double age_moyen(Participant list[], size_t size);
Participant doyen(Participant list[], size_t size);


void init(Evenement& e)
{
	e =
	{
		5,
		{
			{"Alice", 26, "Paris"}, {"Cristina", 29, "Rio"}, {"John", 32, "Londre"}, {"Stanley", 25, "New York"}, {"Koto", 31, "Tokyo"}
		}
	};
}

double age_moyen(Participant list[], size_t size)
{
	double moy = 0;
	for (size_t p = 0; p < size; ++p)
		moy += list[p].age;
	return moy / size;
}

Participant doyen(Participant list[], size_t size)
{
	size_t doyen = 0;
	for (size_t p = 0; p < size; ++p)
		if (list[p].age > list[doyen].age)
			doyen = p;
	return list[doyen];
}

int main()
{
	Evenement evnt;
	
	init(evnt);

	cout << "Age moyen: "			<< age_moyen(evnt.list, evnt.cpt) << endl;
	cout << "Nom du doyen(nne): "	<< doyen(evnt.list, evnt.cpt).nom << endl;
	_getch();
}