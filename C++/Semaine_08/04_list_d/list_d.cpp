#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// LIST -- DOUBLE LINKED

/*
								next				next				next
					--------	--->	--------	--->	--------	--->	nullptr
					| item |	    	| item |			| item |
nullptr		<---	--------	<---	--------	<---	--------
			prev		^		prev				prev		^
						|										|
						|										|
					  first 								   last

*/


/*

CARACTÉRISTIQUES D'UNE LISTE DOUBLEMENT CHAINÉE D'ITEMS

	1) il y a deux pointeurs importants pour la liste: (first) et (last)

	2) chaque item possède deux pointeurs (prev) et (next) vers ses items adjacents dans la liste

	3) au départ, la liste est vide et les deux pointeurs (first) et (last) sont nuls (nullptr)

	4) l'ajout et le retrait d'un item peut se faire n'importe où dans la liste

	5) si la liste contient un seule item, les pointeurs (first) et (last) pointent sur celui-ci

	6) le parcours la liste peut se faire dans les deux directions: first --> last  ou  last --> first
	   il est impossible de se rendre à un item directement

	7) l'usage d'un pointeur auxiliaire d'item (it) peut s'avérer utile lors des manipulations de la liste
	
	8) les items retirés de la liste sont recyclés (delete)

*/

struct Data
{
	int info;
	// ...
};

struct Item
{
	Data data;
	Item *prev, *next;
};

struct List
{
	Item *first, *last;
	size_t size;
};

// FONCTIONS PRINCIPALES

bool empty(List* l) { return l->size == 0; }

void push_first(List* l, Data& d) {}	// à faire

void push_last(List* l, Data& d)
{
	Item* it = new Item {d, l->last, nullptr};

	if (l->last)
		l->last = l->last->next = it;
	else
		l->last = l->first = it;

	l->size++;
}

void pop_first(List* l)
{
	if (l->size)
	{
		Item* it = l->first;
		l->first = l->first->next;
		delete it;

		if (!l->first) l->last = nullptr;
		else l->first->prev = nullptr;

		l->size--;
	}
}

void pop_back(List* l) {}				// à faire


Data& last(List* l) { return l->last->data; }

Data& first(List* l) { return l->first->data; }

void clear(List* l) { while (!empty(l)) pop_first(l); }


Item* find(List* l, Data& d)
{
	for (Item* it = l->first; it; it = it->next)
		if (d.info == it->data.info)
			return it;
	return nullptr;
}

void replace(List* l, Data& dt, Data& new_dt)
{
	if (Item* it = find(l, dt))
		it->data = new_dt;
}

// FONCTIONS UTILITAIRES

void show(Data& d) { cout << d.info << " "; }

void show_fwd(List* l)
{
	for (Item* it = l->first; it; it = it->next)
		show(it->data);
}

void show_bwd(List* l)
{
	for (Item* it = l->last; it; it = it->prev)
		show(it->data);
}

void erase(List* l, Item* it)
{
	if (it->next) it->next->prev = it->prev; else l->last = it->prev;
	if (it->prev) it->prev->next = it->next; else l->first = it->next;
	delete it;
	l->size--;
}

void erase(List* l) { while (l->first) erase(l, l->first); }


void insert(List* l, Item* pos, Data& d)
{
	Item *it = pos->prev = new Item {d, pos->prev, pos};

	if (it->prev) it->prev->next = it;
	else l->first = it;

	l->size++;
}

void insert(List* l, Data& d)
{
	Item* it;
	for (it = l->first; it; it = it->next)
		if (d.info < it->data.info)
			break;
	if (it) insert(l, it, d); else push_last(l, d);
}

int main()
{
	Data dt;
	List* l = new List {nullptr, nullptr, 0};

	while (l->size < 10)
	{
		dt = { rand() % 100 };
		push_last(l, dt);
	}
	cout << endl << "list  : ";	show_fwd(l);
	cout << endl << "rlist : ";	show_bwd(l);
	erase(l);

	while (l->size < 30)
	{
		dt = { rand() % 100 };
		insert(l, dt);
	}
	cout << endl << "list  : ";	show_fwd(l);
	cout << endl << "rlist : ";	show_bwd(l);
	erase(l);

	delete l;

	_getch();
}