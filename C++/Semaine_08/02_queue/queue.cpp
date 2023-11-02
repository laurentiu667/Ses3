#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

// QUEUE

/*

	--------	next	--------	next	--------	next
	| item |	--->	| item |	--->	| item |	--->	nullptr
	--------			--------			--------
		^										^
		|										|
		|										|
	  front									   back

*/


/*

CARACTÉRISTIQUES D'UNE FILE (QUEUE) CHAINÉE D'ITEMS

	1) il y a deux pointeurs importants:

		a) front --> qui pointe toujours vers le premier item de la file
		b) back  --> qui pointe toujours vers le dernier item de la file

	2) au départ, la file est vide et les pointeurs (front) et (back) sont nuls (nullptr)

	3) l'ajout (push) d'un item se fait à l'arrière (back) de la file, et le pointeur (back) est ajusté
		
	4) le retrait (pop) d'un item se fait à l'avant (front) de la file, et le pointeur (front) est ajusté
	
	5) si la file contient un seul item, les pointeurs (back) et (front) pointent les deux sur celui-ci

	6) remarque: le premier item ajouté (push) sera toujours le premier item retiré (pop) ==>  (fifo: first in, first out)
 	
	7) le parcours la file débute à l'avant (front) et se poursuit en suivant le pointeur next de chaque item
	   il est donc impossible de se rendre à un item directement

	8) l'usage d'un pointeur temporaire d'item (it) peut s'avérer utile lors des manipulations de la file

	9) les items retirés (pop) de la file sont recyclés (delete)

*/

struct Data
{
	string info;
	// ...
};

struct Item
{
	Data data;
	Item* next;
};

struct Queue
{
	Item *front, *back;
	size_t size;
};

// FONCTIONS PRINCIPALES

bool empty(Queue* q) { return q->size == 0; }

void push(Queue* q, Data& d)
{
	Item* it = new Item {d, nullptr};

	if (q->back)
		q->back = q->back->next = it;
	else
		q->front = q->back = it;

	q->size++;
}

void pop(Queue* q)
{
	if (q->front)
	{
		Item* it = q->front;
		q->front = q->front->next;
		delete it;

		if (!q->front) q->back = q->front;
		q->size--;
	}
}

Data& back(Queue* q) { return q->back->data; }

Data& front(Queue* q) { return q->front->data; }

void clear(Queue* q) { while (!empty(q)) pop(q); }

void show(Data& d) { cout << d.info << " "; }

void show(Queue* q)
{
	cout << "queue  : ";
	for (Item* it = q->front; it; it = it->next)
		show(it->data);
	cout << "\n\n";
}

int main()
{
	Data dt = {};
	Queue* q = new Queue {nullptr, nullptr, 0};

	dt = {"alex"};		push(q, dt);	show(q);
	dt = {"rosalie"};	push(q, dt);	show(q);
	dt = {"gabriel"};	push(q, dt);	show(q);
	dt = {"nadia"};		push(q, dt);	show(q);			// 4 items dans la queue maintenant	

	if (!empty(q)) front(q) = {"jasmine"};					// modifie le premier item de la queue
	show(q);

	while (!empty(q)) { pop(q); show(q); }

	delete q;

	_getch();
}