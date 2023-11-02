#pragma once

#include <string>
#include "cvm 21.h"

using namespace std;

struct XY
{
	size_t x, y;
};

void gotoxy(XY xy);

// FONCTIONS GÉNÉRALES
void io_clean();
double io_round(double v, int p = 2);
string io_format_date(time_t t);

// FONCTIONS GÉNÉRALES POUR LA LECTURE D'UNE STRING, SON NETTOYAGE ET SON TRANSFERT DANS UN TABLEAU DE CHAR
string& io_textCleaner(string& texte); // enlève les blancs et tabulations
void io_copyStringTo(const string& s, const size_t size, char to[]);
void io_lireString(const size_t size, char to[]);

// FONCTIONS POUR DES MESSAGES
void io_bip();
void io_avertissement(string warning, XY xy, Color c = Color::yel);
void io_appuyerSurUneTouchePourContinuer(XY xy);

// FONCTIONS POUR LIRE UNE RÉPONSE OUI OU NON À UNE QUESTION
bool io_lireQuestionOuiNon(string question, Color c, XY xy);
