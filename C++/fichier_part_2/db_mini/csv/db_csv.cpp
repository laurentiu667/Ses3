/*
	Programme exemple pour la lecture d'un fichier texte de type CSV: Comma-Separated Values

	tous les champs d'un enregistrement doivent être séparés par des virgules ',' même si aucune valeur n'est spécifiée pour un champ.

	il y a un enregistrement par ligne, il peut y avoir des lignes vides

	Note : le caractère blanc ==> ' ' ou '\t' ou '\n'

	Format CSV : titre , artiste , album , année , durée , genre

*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
#include <sstream>
#include <fstream>

#include "../../../cvm 21.h"

using namespace std;

const int MAX = 10;

struct Tune									// enregistrement (record)
{
	string titre, artiste, album, genre;
	int année;
	double durée;
};

struct Playlist								// base de données (db: database)
{
	Tune list[MAX];
	int cnt;
};


void clean(string& v)						// enlève les blancs inutiles dans v
{
	string w;
	stringstream ss(v);
	ss >> (v = {});
	while (ss >> w) v += " " + w;
}

string read_field(stringstream& rec)
{
	string f; getline(rec, f, ','); clean(f); return f;
}

void read_val(stringstream& rec, string& v)
{
	v = read_field(rec);
}

void read_val(stringstream& rec, int& v)
{
	stringstream ss(read_field(rec)); ss >> v;
}

void read_val(stringstream& rec, double& v)
{
	stringstream ss(read_field(rec)); ss >> v;
}

void read_rec(string& line, Playlist* db)
{
	clean(line);
	if (line.size())
	{
		Tune t = {};
		stringstream rec(line);
		read_val(rec, t.titre);
		read_val(rec, t.artiste);
		read_val(rec, t.album);
		read_val(rec, t.année);
		read_val(rec, t.durée);
		read_val(rec, t.genre);
		db->list[db->cnt++] = t;
	}
}
void load_db(fstream& f, Playlist* pl)
{
	string line;
	while (getline(f, line) && pl->cnt < MAX)
		read_rec(line, pl);
}

void load_db(string fname, Playlist* pl)
{
	fstream f(fname, ios::in);
	if (f.is_open())
	{
		load_db(f, pl);	
		f.close();
		cout << pl->cnt << " record" << (pl->cnt > 1 ? "s" : "") << " read !";
	}
	else
		cout << "db file not found !" << endl;
}

void save_db(string fname, Playlist* pl)
{
	// à faire en respectant le format lu par la fonction load_db(...)
}

int main()
{
	setcp(1252);
	Playlist* pl = new Playlist {};

	string fname = "db_csv.txt";
	load_db(fname, pl);
	// ... manipulation de la playlist ici
	save_db(fname, pl);

	delete pl;
	_getch();
}