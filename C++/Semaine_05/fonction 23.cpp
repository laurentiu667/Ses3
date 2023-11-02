#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

/*
	EXEMPLE

		- passage par valeur
		- passage par référence
		- déclaration de fonctions (prototype)
		- définition de fonction surchargée
		- paramètre avec une valeur par défaut

*/

const int MAX = 10;

struct Song
{
	string name;
	string artist;
	double time;
};

struct Playlist
{
	string name;
	int cpt = 0;
	Song list[MAX];
};

// DÉCLARATIONS

void show(Song t);
void show(Playlist& pl);

bool isfull(Playlist& pl);
void add(Playlist& pl, Song t);
void add(Playlist& to, Playlist& from);

void swap(Song& t1, Song& t2);
void draw(Playlist& pl);

Song rem(Playlist& pl, int no = 1);		// no : 1 à n


// DÉFINITIONS

// Afficher

void show(Song s)
{
	cout << left << fixed << setprecision(2);
	cout << '\t' << setw(30) << s.name << s.time << "   Art: " << s.artist << endl;
}

void show(Playlist& pl)					// fonction surchargée
{
	cout << pl.name;
	for (int s = 0; s < pl.cpt; ++s)
		show(pl.list[s]);
	cout << "\n";
}


// Ajouter

bool isfull(Playlist& pl) {	return pl.cpt == MAX; }

void add(Playlist& pl, Song s)			// on pourrait faire aussi la fonction insérer
{
	if (!isfull(pl))
		pl.list[pl.cpt++] = s;
}

void add(Playlist& to, Playlist& from)  // fonction surchargée
{
	for (int s = 0, cpt = from.cpt; s < cpt; ++s)
		add(to, from.list[s]);
}


// Mélanger

void swap(Song& s1, Song& s2)
{
	Song temp = s1;
	s1 = s2;
	s2 = temp;
}

void draw(Playlist& pl)
{
	for (int s = pl.cpt - 1; s > 0; --s)
		swap(pl.list[s], pl.list[rand()%(s+1)]);
}


// Retirer

Song rem(Playlist& pl, int no)			// no : 1 à n, par défaut 1 (voir la déclaration)
{
	Song s = {};

	if (no >= 1 && no <= pl.cpt)
	{
		s = pl.list[no-1];
		for (int i = no-1; i < pl.cpt-1; ++i)
			pl.list[i] = pl.list[i+1];
		pl.list[--pl.cpt] = {};
	}
	return s;
}


int main()
{
	Song s;
	Playlist L1 = {"L1"}, L2 = {"L2"};

	s = { "Time", "Pink Floyd" , 7.06 };
	add(L1, s);
	s = { "Dazed And Confused", "Led Zeppelin" , 6.29 };
	add(L1, s);
	show(L1);

	s = { "Money", "Pink Floyd" , 5.06 };
	add(L2,s);
	s = { "Shattered", "Rolling Stones" , 3.47 };
	add(L2,s);
	show(L2);

	add(L1, L2);	L1.name = "L1+L2";
	show(L1);

	draw(L1);		L1.name = "L1+L2@";
	show(L1);

	add(L2, rem(L1, L1.cpt));
	show(L1);
	show(L2);

	s = rem(L1);
	show(s);

	_getch();
}