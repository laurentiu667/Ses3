#include <string>
#include "db.h"
#include "List_chainée.h"
#include <iostream>
#include <iomanip>
#include "cvm 21.h"


bool vide(Liste* l) 
{ 
	return l->size == 0; 
}

void push_firste(Liste* l, Item_Club& c)
{
	l->first = new Item{ c, l->first };
	if (!l->last) l->last = l->first;
	l->size++;
}

void insert_after(Liste* l, Item* pos, Item_Club& c)
{
	pos->next = new Item{ c, pos->next };
	if (l->last == pos)	l->last = pos->next;
	l->size++;
}

void push_last(Liste* l, Item_Club& c)
{
	if (vide(l))
		push_firste(l, c);
	else
		insert_after(l, l->last, c);
}

Item* find_name_club(Liste* l, std::string nom)
{
	for (Item* it = l->first; it; it = it->next)
		if (nom == it->club.club)
			return it;
	return nullptr;
}

std::string find_club_total(Membre& m) 
{
	// Création de nouvelle liste.
	Liste* l = new Liste{ nullptr,nullptr, 0 };
	int nombre_club = 0;
	// Compter le nombre de club different

	for (int i = 1; i <= db_size(); ++i) {
		db_read(i, &m);
		for (size_t j = 0; j < m.nb_clubs; j++)
		{
			std::string nom = m.clubs[j].nom_Club;
			Item* item_club = find_name_club(l, nom);
			

			if (item_club == nullptr) {
				Item_Club* c = new Item_Club { nom, 1 };
				push_last(l, *c);
			}
			else {
				item_club->club.nb_club++;
			}
		}
	}
	std::cout << std::endl << std::setw(11) << "membres" << std::setw(16) << "distribution" << std::setw(10) << "club (" << l->size << ")" << std::endl << std::endl;

	for (Item* it = l->first; it; it = it->next)
	{
		if (l->size >= 1)
		{
			setcolor(Color::wht);
			double distr = (it->club.nb_club / static_cast<double>(db_size())) * 100;
			std::cout << std::setw(10) << it->club.nb_club << std::setw(11) << std::fixed << std::setprecision(1) << distr << " %" << std::setw(8) << " " << std::left << it->club.club << std::endl << std::right;
		}
	}

	delete[] l;
	return "";
}