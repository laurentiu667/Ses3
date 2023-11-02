#pragma once

#include <ctime>

const int s_nom = 21;	// 20 caractères max pour le nom + 1 caractère butoir
const int s_tel = 15;	// ex: 1-800-555-1212

struct Contact
{
	char nom[s_nom];
	char tel[s_tel];
	time_t date;
};


void db_create();
void db_open();
bool db_isopen();
void db_close();

size_t db_size();
void db_read(size_t no, Contact* c);
void db_write(size_t no, Contact* c);