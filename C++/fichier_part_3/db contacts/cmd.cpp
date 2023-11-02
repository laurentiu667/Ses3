#include <iostream>
#include <iomanip>
#include <conio.h>

#include "cvm 21.h"

#include "db.h"
#include "io.h"
#include "cmd.h"

using namespace std;

const int MARG = 4;

void cmd_ajouter()
{
	size_t x = MARG, y = 4, b = 10;

	Contact c;
	size_t no = db_size() + 1; // Le numéro du nouveau contact

	clrscr();
	io_clean();

	gotoxy(x, y += 1); cout << setw(b) << "Nom" << ": "; io_lireString(s_nom, c.nom);
	gotoxy(x, y += 2); cout << setw(b) << "Téléphone" << ": "; io_lireString(s_tel, c.tel);
	c.date = time(NULL); // conservée en secondes

	db_write(no, &c);
}

void titre(XY xy)
{
	size_t pad = 4;
	gotoxy(xy);
	cout << left << setw(pad) << "No" << setw(s_nom + pad) << "Nom" << setw(s_tel + pad) << "Téléphone" << "Date";
}

void afficher(size_t no, Contact& c, XY& xy)
{
	size_t pad = 4;
	gotoxy(xy);
	cout << left << setw(pad) << no << setw(s_nom + pad) << c.nom << setw(s_tel + pad) << c.tel << io_format_date(c.date);
}

void cmd_afficher()
{
	XY xy = {MARG,4};
	size_t b = 20;

	Contact c;
	size_t no, dbsize = db_size();

	clrscr();
	io_clean();

	gotoxy(xy); cout << "Numéro du contact   : "; cin >> no;

	if (cin.fail() || no <= 0 || no > dbsize)
	{
		xy.y += 2;
		io_avertissement("Le numéro du contact est invalide !!!", xy);
	}
	else
	{
		db_read(no, &c);
		xy.y += 3;
		afficher(no, c, xy);
		_getch();
	}
}

void cmd_modifier()
{
	XY xy = {MARG,4};
	size_t b = 20;

	Contact c;
	size_t no, dbsize = db_size();

	clrscr();
	io_clean();

	gotoxy(xy); cout << "Numéro du contact   : "; cin >> no;

	if (cin.fail() || no <= 0 || no > dbsize)
	{
		xy.y += 2;
		io_avertissement("Le numéro du contact est invalide !!!", xy);
	}
	else
	{
		db_read(no, &c);
		xy.y += 3;
		afficher(no, c, xy);
		io_clean();
		xy.y += 3;
		gotoxy(xy.x, xy.y); cout << setw(b) << "Entrez le nouveau téléphone" << ": "; io_lireString(s_tel, c.tel);
		db_write(no, &c);
	}
}

void cmd_lister()
{
	XY xy = {MARG+4, 2};

	Contact c;
	size_t dbsize = db_size();

	clrscr();
	titre(xy);
	xy.y += 2;
	if (dbsize > 0)
	{
		for (size_t no = 1; no <= dbsize; no++, xy.y++)
		{
			db_read(no, &c);
			afficher(no, c, xy);
		}
		_getch();
	}
	else
		io_avertissement("Aucun contact dans la base de données !!!", xy);
}

void cmd_rechercher()
{
	string texte, nom;
	XY xy = {MARG+4, 2};
	size_t b = 20;

	Contact c;
	size_t dbsize = db_size();

	clrscr();
	titre(xy);
	xy.y += 2;

	if (dbsize > 0)
	{
		cout << left;
		gotoxy(xy.x, xy.y); cout << "Nom du contact   : ";
		io_clean();
		getline(cin, texte);

		bool find = false;
		for (unsigned no = 1; no <= dbsize; no++)
		{
			db_read(no, &c);
			nom = c.nom;
			if (nom.find(texte) != string::npos)
			{
				afficher(no, c, xy); xy.y++;
				find = true;
			}
		}
		if (!find)
			io_avertissement("Aucun contact trouvé !!!", xy);
		else
			_getch();
	}
	else
		io_avertissement("Aucun contact dans la base de données !!!", xy);
}

void cmd_effacer()
{
	clrscr();
	if (io_lireQuestionOuiNon("Effacer la base de données", Color::red, {MARG, 3}))
	{
		db_create();
		io_avertissement("Base de données effacée ...", {MARG, 5});
	}
}