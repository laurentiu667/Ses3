#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// LIST -- FORWARD LINKED ONLY

/*

	--------	next	--------	next	--------	next
	| item |	--->	| item |	--->	| item |	--->	nullptr
	--------			--------			--------
		^										^
		|										|
		|										|
	  first									   last

*/


/*

CARACTÉRISTIQUES D'UNE LISTE SIMPLEMENT CHAINÉE D'ITEMS

	1) il y a deux pointeurs importants pour la liste
		a) un pointeur (last) vers le dernier item
		b) un pointeur (first) vers le premier item

	2) chaque item possède un pointeur (next) vers l'item suivant de la liste, à moins d'être le dernier

	3) au départ, la liste est vide et les deux pointeurs (first) et (last) sont nuls (nullptr)

	4) l'ajout (push) d'un item peut se faire au début comme à la fin de la liste
		
	5) le retrait (pop) d'un item se fait au début de la liste
	 	
	6) le parcours la liste débute au début (first) et se poursuit en suivant le pointeur next de chaque item
	   il est donc impossible de se rendre à un item directement

	7) l'usage d'un pointeur temporaire d'item (it) peut s'avérer utile lors des manipulations de la liste

	8) les items retirés (pop) de la liste sont recyclés (delete)

*/

struct Data
{
	string title;
	string artist;
	// ...
};

struct Item
{
	Data data;
	Item* next;
};

struct List
{
	Item *first, *last;
	size_t size;
};

// FONCTIONS PRINCIPALES

bool empty(List* l) { return l->size == 0; }

void push_first(List* l, Data& d)
{
	l->first = new Item {d, l->first};
	if (!l->last) l->last = l->first;
	l->size++;
}

void insert_after(List* l, Item* pos, Data& d)
{	
	pos->next = new Item {d, pos->next};
	if (l->last == pos)	l->last = pos->next;
	l->size++;
}

void push_last(List* l, Data& d)
{
	if (empty(l))
		push_first(l, d);
	else
		insert_after(l, l->last, d);
}

void pop_first(List* l)
{
	if (l->first)
	{
		Item* it = l->first;
		l->first = l->first->next;
		delete it;

		if (!l->first) l->last = l->first;
		l->size--;
	}
}

Data& last(List* l) { return l->last->data; }
Data& first(List* l) { return l->first->data; }

void clear(List* l) { while (!empty(l)) pop_first(l); }


Item* find(List* l, Data& d)
{
	for (Item* it = l->first; it; it = it->next)
		if (d.title == it->data.title && d.artist == it->data.artist)
			return it;
	return nullptr;
}

void replace(List* q, Data& old_dt, Data& new_dt)
{
	if (Item* it = find(q, old_dt))
		it->data = new_dt;
}

// FONCTIONS UTILITAIRES

void show(Data& d) { cout << "[" << d.title << "]  "; }

void show(List* l)
{
	cout << "list  : ";
	for (Item* it = l->first; it; it = it->next)
		show(it->data);
	cout << "\n\n";
}

int main()
{
	Data dt = {};
	List* l = new List {nullptr, 0};

	dt = { "Time", "Pink Floyd" };					push_last(l, dt);	show(l);
	dt = { "Dazed And Confused", "Led Zeppelin" };	push_last(l, dt);	show(l);
	dt = { "Money", "Pink Floyd" };					push_first(l, dt);	show(l);
	dt = { "Shattered", "Rolling Stones" };			push_first(l, dt);	show(l);		// 4 items dans la liste maintenant	

	if (!empty(l)) last(l) = {"Let It Be", "beatles" };									// modifie le dernier item de la liste
	show(l);

	Data old = { "Money", "Pink Floyd" }, sub = { "Have a Cigar", "Pink Floyd" };
	replace(l, old, sub);																// fait un remplacement
	show(l);

	clear(l);
	delete l;

	_getch();
}