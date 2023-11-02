#include <string>
#include <fstream>

#include "db.h"

using namespace std;

const string filename = "contacts.db";

static fstream f;

void db_create()
{
	if (f.is_open())
		f.close();
	f.open(filename, ios::in | ios::out | ios::binary | ios::trunc); // recréer le fichier vide
}

void db_open()
{
	f.open(filename, ios::in | ios::out | ios::binary);
	if (!f.is_open())
		db_create();								// si le fichier n'est pas trouvé le créer
}

bool db_isopen() { return f.is_open(); }

void db_close() { f.close(); }

size_t db_size()
{
	f.seekg(0, ios::end);
	return (size_t)f.tellg() / sizeof(Contact);
}

void db_read(size_t no, Contact* c)					// att: no = numéro logique de l'enregistrement: [1..n]  où n = db_size()
{
	f.seekg((no-1) * sizeof(Contact), ios::beg);
	f.read((char*)c, sizeof(Contact));
}

void db_write(size_t no, Contact* c)				// att: no = numéro logique de l'enregistrement: [1..n]  où n = db_size()
{
	f.seekg((no-1) * sizeof(Contact), ios::beg);
	f.write((char*)c, sizeof(Contact));
}