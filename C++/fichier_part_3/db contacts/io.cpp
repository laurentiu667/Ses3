#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <string>
#include <sstream>

#include "cvm 21.h"
#include "io.h"

using namespace std;

// FONCTIONS GÉNÉRALES

void gotoxy(XY xy) { gotoxy(xy.x, xy.y); }

void io_clean() // vider les tampons d'input
{
	if (cin.fail()) cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	while (_kbhit()) _getch();
}

double io_round(double v, int p) // arrondir v avec la précision p
{
	double e = pow(10, p);
	return round(v * e) / e;
}

string io_format_date(time_t t) // converti une date t sous la forme d'une string 
{
	stringstream ss;
	tm d;
	localtime_s(&d, &t);
	ss << setfill('0') << right;
	ss << setw(2) << d.tm_mday << "/" << setw(2) << d.tm_mon + 1 << "/" << setw(2) << d.tm_year + 1900;
	return ss.str();
}

// FONCTIONS GÉNÉRALES POUR LA LECTURE D'UNE STRING, SON NETTOYAGE ET SON TRANSFERT DANS UN TABLEAU DE CHAR

string& io_textCleaner(string& texte) // enlève les blancs et tabulations dans texte
{
	string mot;
	stringstream ss(texte);
	texte = "";
	while (ss >> mot)
		if (texte.size()) texte += " " + mot; else texte = mot;
	return texte;
}

void io_copyStringTo(const string& s, const size_t size, char to[]) // copy s dans to. size est la taille de to
{
	unsigned int i;
	for (i = 0; (i < size - 1) && (i < s.size()); ++i)
		to[i] = s[i];
	to[i] = 0;
}

void io_lireString(const size_t size, char to[])
{
	string texte;
	getline(cin, texte);
	io_textCleaner(texte);
	io_copyStringTo(texte, size, to);
}

// FONCTIONS GÉNÉRALES POUR L'AFFICHAGE DE MESSAGES

void io_bip() { cout << "\a"; }

void io_message(string message, Color c, XY xy)
{
	setcolor(c); gotoxy(xy); cout << message; clreol(); setcolor(Color::wht);
}

void io_avertissement(string warning, XY xy, Color c)
{
	io_clean();
	io_message(warning, c, xy); _getch();
}

void io_appuyerSurUneTouchePourContinuer(XY xy)
{
	io_avertissement("Appuyez sur une touche pour continuer ...", xy, Color::yel);
}


// FONCTIONS POUR LIRE UNE RÉPONSE OUI OU NON À UNE QUESTION

bool io_lireOuiNon()
{
	int choixb = 0, choix;
	io_clean();
	while (true)
		switch (choix = toupper(_getch()))
		{
		case 0:	case -32: // control key
			if (_kbhit()) _getch();	break;

		case 13: // enter
			if (choixb == 'O' || choixb == 'N') return choixb == 'O'; break;

		case 'O': case 'N':
			cout << char(choixb = choix) << "\b"; break;
		}
}

bool io_lireQuestionOuiNon(string question, Color c, XY xy)
{
	io_message(question + " (O / N) ? : ", c, xy);
	return io_lireOuiNon();
}