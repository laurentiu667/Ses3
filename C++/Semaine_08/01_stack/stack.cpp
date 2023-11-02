#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// STACK 

/*
		--------
top -->	| item |
		--------
			|
			| below
			v
		--------
		| item |	<--- it
		--------
			|
			| below
			v
		--------
		| item |
		--------
			|
			| below
			v
		 nullptr
*/


/*

CARACT�RISTIQUES D'UNE PILE (STACK) CHAIN�E D'ITEMS
	
	1) il y a un pointeur important (top) qui pointe toujours vers l'item du haut de la pile

	2) au d�part, la pile est vide et le pointeur (top) est nul (top = nullptr)

	3) l'ajout (push) d'un item se fait au dessus de la pile et le pointeur (top) est ajust�
		
	4) le retrait (pop) d'un item se fait au dessus de la pile et le pointeur (top) est ajust�

	5) remarque: le dernier item ajout� (push) sera toujours le premier item retir� (pop) ==> (lifo: last in, first out)
 
	6) chaque item poss�de un pointeur (below) vers l'item du dessous, qui sera nul pour le permier item de la pile

	7) un parcours de la pile d�bute au (top) et se poursuit en suivant le pointeur below de chaque item
	   il est donc impossible de se rendre � un item directement

	8) l'usage d'un pointeur temporaire d'item (it) peut s'av�rer utile lors des manipulations de la pile

	9) les items retir�s de la pile sont recycl�s (delete)


NOTE: un pointeur (p) peut servir de pr�dicat dans un test: nullptr vaut false

	if (p)	// idem que: (si le pointeur n'est pas nul) ==> if (p != nullptr)
	{

	}

 */

struct Data
{
	string info;
	// ...
};

struct Item
{
	Data data;
	Item* below;
};

struct Stack
{
	Item* top;
	size_t size;
};

// FONCTIONS PRINCIPALES

bool empty(Stack* s) { return s->size == 0; }

void push(Stack* s, Data& d)						// ajoute un item
{
	s->top = new Item {d, s->top};
	s->size++;
}

void pop(Stack* s)									// supprime un item
{
	if (s->top)
	{
		Item* it = s->top;
		s->top = s->top->below;
		delete it;
		s->size--;
	}
}

Data& top(Stack* s) { return s->top->data; }

void clear(Stack* s) { while (!empty(s)) pop(s); }

void show(Data& d) { cout << d.info << endl; }

void show(Stack* s)
{
	cout << endl << "stack" << endl;
	for (Item* it = s->top; it; it = it->below)
		show(it->data);
}

int main()
{
	// ex: g�rer l'historique de navigation et son retour arri�re (back) avec un pile

	Data dt = {};
	Stack* s = new Stack {nullptr, 0};

	dt = {"www.cvm.qc.ca"};		push(s, dt);
	dt = {"www.google.com"};	push(s, dt);
	dt = {"www.cplusplus.com"};	push(s, dt);
	dt = {"www.facebook.com"};	push(s, dt);		// 4 items sur la pile maintenant
	show(s);

	if (!empty(s)) top(s) = {"www.learncpp.com"};	// modifier le data du top
	show(s);

	while (!empty(s))
	{
		pop(s); show(s);
	}

	delete s;

	_getch();
}