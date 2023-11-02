#include <string>
#include <fstream>

#include "db.h"

using namespace std;

const string filename = "clubsocial.db";

static fstream f;

void db_create()
{
	if (f.is_open())
		f.close();
	f.open(filename, ios::in | ios::out | ios::binary | ios::trunc); // recr�er le fichier vide
}

void db_open()
{
	f.open(filename, ios::in | ios::out | ios::binary);
	if (!f.is_open())
		db_create();								// si le fichier n'est pas trouv� le cr�er
}

bool db_isopen() { return f.is_open(); }

void db_close() { f.close(); }

size_t db_size()
{
	f.seekg(0, ios::end);
	return (size_t)f.tellg() / sizeof(Membre);
}

void db_read(size_t no, Membre* m)					// att: no = num�ro logique de l'enregistrement: [1..n]  o� n = db_size()
{
	f.seekg((no-1) * sizeof(Membre), ios::beg);
	f.read((char*)m, sizeof(Membre));
}

void db_write(size_t no, Membre* m)				// att: no = num�ro logique de l'enregistrement: [1..n]  o� n = db_size()
{
	f.seekg((no-1) * sizeof(Membre), ios::beg);
	f.write((char*)m, sizeof(Membre));
}
