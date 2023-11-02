#include "cvm 21.h"
#include "db.h"
#include <iostream>
void show_top_title() // TITRE PRESENT SUR TOUTES LES FONCTIONS
{
	gotoxy(4, 1);
	setcolor(Color::grn);
	std::cout << "CLUB SOCIAL DU CVM";
	gotoxy(4, 2);
	std::cout << "------------------";
	gotoxy(90, 1);
	std::cout << db_size() << (db_size() > 0 ? " membres" : " membre\n");
	setcolor(Color::wht);
}