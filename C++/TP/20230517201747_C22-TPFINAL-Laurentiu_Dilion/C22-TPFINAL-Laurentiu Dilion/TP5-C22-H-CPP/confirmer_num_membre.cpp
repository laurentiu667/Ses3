#include "cvm 21.h"
#include "io.h"
#include <iostream>
#include "db.h"
int confirmer_num_membre() // TITRE PRESENT SUR TOUTES LES FONCTIONS
{
	int d = wherex(), g = wherey();
	size_t no, dbsize = db_size();
	do
	{
		io_clean();
		gotoxy(d, g);
		clreoscr();
		std::cin >> no;
	} while (cin.fail() || no < 0 || no > dbsize);
	return no;
}