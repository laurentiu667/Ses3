#include "Sondage.h"
#include "Statistic_10.h"

struct infoville
{
	string ville;
	int stat;
};

struct Item
{
	infoville infoville;
	Item* next;
};

struct List
{
	Item* first, * last;
	size_t size;
};

bool empty(List* l) { return l->size == 0; }

void push_first(List* l, infoville& d)
{
	l->first = new Item{ d, l->first };
	if (!l->last) l->last = l->first;
	l->size++;
}

void insert_after(List* l, Item* pos, infoville& d)
{
	pos->next = new Item{ d, pos->next };
	if (l->last == pos)	l->last = pos->next;
	l->size++;
}

void push_last(List* l, infoville& d)
{
	if (empty(l))
		push_first(l, d);
	else
		insert_after(l, l->last, d);
}

Item* find_testville(List* l, string nom)
{
	for (Item* it = l->first; it; it = it->next)
		if (nom == it->infoville.ville)
			return it;
	return nullptr;
}

string find_city_with_most_test(List* l) {
	int test_max = 0;
	string nom_max = "inconnue";
	// Trouver la ville avec le plus grand nombre
	for (Item* it = l->first; it; it = it->next) {
		if (test_max < it->infoville.stat) {
			test_max = it->infoville.stat;
			nom_max = it->infoville.ville;
		}
	}

	return nom_max;
}

string stat_10(Repondant rep[], Infection info[]) {
	// Création de nouvelle liste.
	List* l = new List{ nullptr,nullptr, 0 };

	// Parcourir toute la liste et additionner le nombre test

	for (int i = 0; i < nb_repondants; ++i) {
		string nom = rep[i].ville;
		int test = info[i].r10;
		Item* itemville = find_testville(l, nom);

		if (itemville == nullptr) {
			infoville* v = new infoville{ nom, test };
			push_last(l, *v);
		}
		else {
			itemville->infoville.stat += test;
		}
	}
	string nom_max = find_city_with_most_test(l);
	return nom_max;
	delete[] l;
}