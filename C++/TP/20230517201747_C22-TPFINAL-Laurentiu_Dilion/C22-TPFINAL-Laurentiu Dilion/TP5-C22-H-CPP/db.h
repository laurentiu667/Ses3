#pragma once

#include <ctime>

// VARIABLE GLOBALE

const int NOMBRE_CHAR_MAX = 51; // 50 + 1 (Caractere boutoir)
const int NOMBRE_CLUB_MAX = 10;
const int MARG = 4;

struct Clubs
{
	char nom_Club[NOMBRE_CHAR_MAX];
};

struct Membre
{
	char prenom[NOMBRE_CHAR_MAX] = {};
	char nom[NOMBRE_CHAR_MAX] = {};
	char ville[NOMBRE_CHAR_MAX] = {};
	int age;
	int nb_clubs = 0;
	Clubs clubs[NOMBRE_CLUB_MAX] = {};
};

void db_create();
void db_open();
bool db_isopen();
void db_close();
size_t db_size();
void db_read(size_t no, Membre* m);
void db_write(size_t no, Membre* m);