/*
	KEY VALUE DATABASE
	
	Programme exemple pour la lecture des enregistrements d'une base de donn�es dans un fichier texte
	
	Chaque enregistrement est une liste de couple (cl� = valeur) sur des lignes diff�rentes

	La fin d'un enregistrement doit obligatoirement �tre sp�cifi�e avec la cl� "fin"

	Il est possible d'omettre un couple (cl� = valeur) auquel cas cette cl� aura la valeur 0 ou l'�quivalent
	
	L'ordre des couples (cl� = valeur) n'a pas d'importance
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
	int ann�e;
	double dur�e;
};

struct Playlist								// base de donn�es (db: database)
{
	Tune list[MAX];
	int cnt;
};


void clean(string& v)						// enl�ve les blancs inutiles dans v
{
	string w;
	stringstream ss(v);
	ss >> (v = {});
	while (ss >> w) v += " " + w;
}

void read_val(stringstream& ss, string& v)	{ getline(ss, v); clean(v); }

void read_val(stringstream& ss, int& v)		{ ss >> v; }

void read_val(stringstream& ss, double& v)	{ ss >> v; }

void read_key(stringstream& ss, string& k)	{ getline(ss, k, '='); clean(k); }

bool read_kv(string& line, Tune& t)			// lire un couple key = value
{
	string key;
	stringstream ss(line);

	read_key(ss, key);

	if (key == "fin") return true;			// fin d'un enregistrement

	else if (key == "titre")
		read_val(ss, t.titre);
	else if (key == "artiste")
		read_val(ss, t.artiste);
	else if (key == "album")
		read_val(ss, t.album);
	else if (key == "ann�e")
		read_val(ss, t.ann�e);
	else if (key == "dur�e")
		read_val(ss, t.dur�e);
	else if (key == "genre")
		read_val(ss, t.genre);

	return false;
}

void read_rec(fstream& f, Playlist* pl)
{
	Tune t = {};
	string line;
	bool eorf = false;								// end of record found
	do
	{
		getline(f, line);
		eorf = read_kv(line, t);
	}
	while (!f.fail() && !eorf);

	if (eorf) pl->list[pl->cnt++] = t;
}

void load_db(fstream& f, Playlist* pl)
{
	while (!f.fail() && pl->cnt < MAX) read_rec(f, pl);
}

void load_db(string name, Playlist* pl)
{
	fstream f(name, ios::in);
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
	// � faire en respectant le format lu par la fonction load_db(...)
}

int main()
{
	setcp(1252);
	Playlist* pl = new Playlist{};

	string fname = "db_key.txt";
	load_db(fname, pl);
	// ... manipulation de la playlist ici
	save_db(fname, pl);

	delete pl;
	_getch();
}