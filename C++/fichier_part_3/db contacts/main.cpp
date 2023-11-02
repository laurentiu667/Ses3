/*

Programme exemple pour l'utilisation d'un fichier binaire avec des enregistrements de tailles égales.

Le programme gère une base de données de contacts très simple.

*/

#include <iostream>
#include <conio.h>

#include "cvm 21.h"

#include "db.h"
#include "cmd.h"

using namespace std;

const int MARG = 4;

// LE MENU

enum class Cmd { ajouter, afficher, modifier, lister, rechercher, effacer, quitter, invalide };

void iu_afficherMenu()
{
	int x = MARG, y = 4, lf = 2;
	clrscr();
	gotoxy(x, y);		cout << "1. Ajouter un contact";
	gotoxy(x, y += lf);	cout << "2. Afficher un contact";
	gotoxy(x, y += lf);	cout << "3. Modifier un contact";
	gotoxy(x, y += lf);	cout << "4. Lister tous les contacts";
	gotoxy(x, y += lf);	cout << "R. Rechercher des contacts";
	gotoxy(x, y += lf);	cout << "E. Effacer tous les contacts";
	gotoxy(x, y += lf);	cout << "Q. Quitter";
	gotoxy(x, y += lf + 1);	cout << "Entrez votre choix : ";
}

Cmd ui_lireUnChoix()
{
	char c;
	Cmd cmd = Cmd::invalide;
	do
		switch (c = toupper(_getch()))
		{
			case '1': cmd = Cmd::ajouter;		break;
			case '2': cmd = Cmd::afficher;		break;
			case '3': cmd = Cmd::modifier;		break;
			case '4': cmd = Cmd::lister;		break;
			case 'R': cmd = Cmd::rechercher;	break;
			case 'E': cmd = Cmd::effacer;		break;
			case 'Q': cmd = Cmd::quitter;		break;
		}
	while (cmd == Cmd::invalide);
	cout << c;
	return cmd;
}

void main ()
{
	setcp(1252);

	Cmd cmd = Cmd::invalide;
	db_open();
	do
	{
		iu_afficherMenu();
		switch (cmd = ui_lireUnChoix())
		{
			case Cmd::ajouter		: cmd_ajouter();	break;
			case Cmd::afficher		: cmd_afficher();	break;
			case Cmd::modifier		: cmd_modifier();	break;
			case Cmd::lister		: cmd_lister();		break;
			case Cmd::rechercher	: cmd_rechercher();	break;
			case Cmd::effacer		: cmd_effacer();	break;
		}
	} while(cmd != Cmd::quitter);
	db_close();
}