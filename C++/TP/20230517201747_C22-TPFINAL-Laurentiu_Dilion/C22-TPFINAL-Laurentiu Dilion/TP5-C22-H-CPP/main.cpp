#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cctype>
//
#include "cvm 21.h"
//
#include "show_top_title.h"
#include "confirmer_num_membre.h"
#include "commandes_globales.h"
#include "db.h"
#include "io.h"
#include "fonction_importer.h"



using namespace std;

// LE MENU

enum class Cmd { add, show, edit, stats, list, xport, import_, whip, quit, invalide };

void iu_afficherMenu()
{
	const int MARG = 8;
	const int size = 9;
	string menu[size] = { "1. Ajouter un membre","2. Afficher un membre", "3. Éditer les clubs d'un membre", "S. Statistiques", "L. Lister les clubs", "E. Exporter la liste des membres", "I. Importer une liste de membres", "D. Supprimer tous les membres", "Q. Quitter" };
	int x = MARG, y = 6, lf = 2;
	clrscr();

	show_top_title();

	setcolor(Color::_yel);
	gotoxy(4, 4);
	cout << "Commandes\t";
	setcolor(Color::wht);

	for (size_t i = 0; i < size; i++)
	{
		gotoxy(x, y);	cout << menu[i];
		y += lf;
	}
	setcolor(Color::_yel);
	gotoxy(4, y + 2);
	cout << "Entrez votre choix : ";
	setcolor(Color::wht);
}

Cmd ui_lireUnChoix()
{
	char c;
	Cmd cmd = Cmd::invalide;
	do
		switch (c = toupper(_getch()))
		{
		case '1': cmd = Cmd::add;		 cmd_ajouter();		break;
		case '2': cmd = Cmd::show;		 cmd_afficher();	break;
		case '3': cmd = Cmd::edit;		 cmd_modifier();	break;
		case 'S': cmd = Cmd::stats;		 cmd_stats();		break;
		case 'L': cmd = Cmd::list;		 cmd_list();		break;
		case 'E': cmd = Cmd::xport;		 cmd_xport();		break;
		case 'I': cmd = Cmd::import_;	 cmd_import();		break;
		case 'D': cmd = Cmd::whip;		 cmd_effacer();		break;
		case 'Q': cmd = Cmd::quit;		 cmd_quitter();		break;
		default :						 io_bip();		    break;
		}
	while (cmd == Cmd::invalide);
	cout << c;
	return cmd;
}

void main()
{
	setcp(1252);
	Cmd cmd = Cmd::invalide;
	db_open();

	do
	{
		iu_afficherMenu();
		switch (cmd = ui_lireUnChoix())
		{
		case Cmd::add:		break;
		case Cmd::show:		break;
		case Cmd::edit:		break;
		case Cmd::stats:	break;
		case Cmd::list:		break;
		case Cmd::xport:	break;
		case Cmd::import_:	break;
		case Cmd::whip:		break;
		case Cmd::quit:		break;
		}
	} while (cmd != Cmd::quit);

	db_close();
}