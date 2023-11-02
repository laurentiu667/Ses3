#include <iostream>
#include <conio.h>
#include <iostream>
#include <iomanip>

// vos autres includes ici

#include "cvm 21.h"

// PRAGMA
#pragma warning (disable:6031)		// valeur de retour ignorée '_getch'
#pragma warning (disable:26812)		// type enum 'type-name' est non délimité. Préférez 'enum class' à 'enum' (enum.3)

using namespace std;

// DIMENSION DU DAMIER

const size_t LIG = 8, COL = 12;											// lignes et colonnes du damier

// POSITION DU DAMIER À LA CONSOLE

const size_t START_X = 10;												// x du coin supérieur gauche du damier dans la console
const size_t START_Y = 5;												// y du coin supérieur gauche du damier dans la console

// CARACTÉRISTIQUES DES CASES À LA CONSOLE

const size_t CASE_X = 6;										    	// largeur d'une case à l'affichage, 2 minimum
const size_t CASE_Y = 3;												// hauteur d'une case à l'affichage, 2 minimum

const size_t SPACE_X = 2;												// nombres de colonnes vides entre les cases, 1 minimum
const size_t SPACE_Y = 1;												// nombres de lignes vides entre les cases, 1 minimum

const size_t DELTA_X = CASE_X + SPACE_X;								// saut d'une case à l'autre, sur l'axe des X
const size_t DELTA_Y = CASE_Y + SPACE_Y;								// saut d'une case à l'autre, sur l'axe des Y

// DIMENSION DE LA FENÊTRE

const size_t WIN_X = 2 * START_X + (COL - 1) * DELTA_X + CASE_X;		// nombres de colonnes pour l'affichage d'une case
const size_t WIN_Y = 2 * START_Y + (LIG - 1) * DELTA_Y + CASE_Y;		// nombres de lignes   pour l'affichage d'une case

// COMMANDES

enum class Arrowkeys						// Code ascii décimal des touches fléchées du clavier
{
	up_left = 71,
	up = 72,
	up_right = 73,
	left = 75,
	right = 77,
	down_left = 79,
	down = 80,
	down_right = 81,
};

using Ak = Arrowkeys;						// un alias plus concis

// CASES, DAMIER ET TRANSFORMATIONS

enum Case { CO, CS, CD, CF, CV};			// les différentes cases possibles: ordinaire, surprise, dollars, fragile, vide

Case damier[LIG][COL] =						// le damier et ses cases initiales
{
	{ CO, CO, CO, CO, CO, CO, CO, CO, CV, CO, CO, CS },
	{ CO, CO, CV, CV, CO, CO, CO, CO, CO, CV, CO, CV },
	{ CO, CO, CV, CS, CV, CO, CO, CO, CO, CO, CV, CS },
	{ CO, CO, CV, CS, CV, CO, CO, CV, CV, CO, CV, CS },
	{ CS, CO, CV, CV, CV, CS, CV, CO, CV, CO, CV, CO },
	{ CS, CO, CS, CS, CO, CS, CV, CS, CV, CO, CV, CO },
	{ CS, CO, CS, CO, CO, CO, CV, CV, CV, CO, CV, CO },
	{ CS, CS, CO, CO, CO, CO, CO, CO, CO, CO, CO, CO }
};

Case futur[5] = { CF, CD, CF, CV};		// la liste des transformations possibles  --  ex: futur[CO] ==> CF

// COOODONNÉE LOGIQUE D'UN DÉPLACEMENT 

struct LC									// ligne et colonne (l,c) d'une case du damier[l][c]
{
	size_t l, c;							// ligne: [0..LIG-1] -- colonne: [0..COL-1]
};

struct Move									// coordonnées des 2 cases impliquées dans un déplacement
{
	LC from, to;
};

// AFFICHAGE DES CASES

struct XY									// coordonnée graphique (x,y) d'une case dans la console
{
	size_t x, y;
};

struct Style								// le style pour l'affichage d'une case
{
	Color color; char c;					// le membre 'c' est le caractère à utiliser pour l'affichage
};

Style map[5] =								// les style pour toutes les cases
{
	{ Color::blu, '\xB2' },					// ex: map[CO].c == '\xB2'				==> le caractère à utiliser
	{ Color::blu, '\xB2' },
	{ Color::grn, '\x24' },					// ex: map[CD].color == Color::grn		==> la couleur à utiliser
	{ Color::pur, '\xB0' },
	{ Color::blk, '\xff' }
};

// AFFICHAGE DU CURSEUR

char cursor[3][3] =							// informations pour l'affichage du curseur
{
	{ '\xC9', '\xCB', '\xBB' },
	{ '\xCC', '\xCE', '\xB9' },
	{ '\xC8', '\xCA', '\xBC' }
};

void ecran_d_affichage()
{
	const string Titre = "D\220COUVREZ ET AMASSEZ 15 CASES $$$$";
	int x, y = 2;
	x = (WIN_X - Titre.size()) / 2;
	gotoxy(x, y);
	cout << Titre;
}

int main()
{
	setwsize(WIN_Y, WIN_X);
	show(false);
	Move m;
	m.from = { 0,0 }; m.to = { 0, 0 };
	LC lc = {0, 0};
	uint8_t c;
	XY xy;
	Case box;
	// Mes déclarations
	int compteurdollars = 0;
	int deplacement = 0;
	int i;
	int x = 10, y = 5;
	int L = NULL, C = NULL;
	int L2 = 0, C2 = 0;
	gotoxy(START_X, START_Y);
	do
	{
		setcolor(Color::wht);
		ecran_d_affichage();

		for (int i = 0; i < COL; i++)									// Affichage du damier
		{
			lc.c = i;
			for (int j = 0; j < LIG; j++)
			{
				lc.l = j;
				box = damier[lc.l][lc.c];
				xy = { START_X + (lc.c * DELTA_X) , START_Y + (lc.l * DELTA_Y) };
				setcolor(map[box].color);
				for (size_t y = 0; y < CASE_Y; ++y)
				{
					gotoxy(xy.x, xy.y++);
					for (size_t x = 0; x < CASE_X; ++x)
						cout << map[box].c;
				}
				setcolor(Color::wht);
			}
		}
		setcolor(Color::yel);
		gotoxy(10, 37);
		if (C == 0 and L == 0)											// Afficher la position précédente et la position actuelle
			cout << "move:" << " ( " << L << "," << C << " ) ";
		else
		{
			cout << "move:" << " ( " << L2 << "," << C2 << " ) " << " --> ( " << L << "," << C << " ) ";
			L2 = L;
			C2 = C;
		}
		gotoxy(96, 37);
		setcolor(Color::grn);
		cout << "$$$$ : " << compteurdollars;							// Afficher le nombre de $$$$
		
		setcolor(Color::yel);
		gotoxy(x, y);													// Affichage du curseur
		cout << cursor[0][0];
		for (int i = 0; i < CASE_X - 2; i++)
		{
			cout << cursor[0][1];
		}
		cout << cursor[0][2];
		gotoxy(x, y + 1);
		for (i = 0; i < CASE_Y - 2; i++)
		{
			cout << cursor[1][0];
			cout << right << setw(CASE_X - 2) << setfill(cursor[1][1]) << "";
			cout << cursor[1][2];
			gotoxy(x, y + i + 2);
		}
		gotoxy(x, y + i + 1);
		cout << cursor[2][0];
		for (int i = 0; i < CASE_X - 2; i++)
		{
			cout << cursor[2][1];
		}
		cout << cursor[2][2];

		c = _getch();

		if (c == 0 || c == 224)
		{
			if (_kbhit())
			{
				c = _getch();
				switch (Ak(c))											// Faire bouger le curseur avec les fleches
				{
				case Ak::up:
					if (damier[m.from.l - 1][m.from.c] != CV) {
						if (m.from.c - 1 >= 0 and m.from.l - 1 < LIG)
						{
							y -= DELTA_Y;
							m.to.c = m.from.c;
							m.to.l = m.from.l - 1;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							L--;
							deplacement++;
						}
					}
					break;
				case Ak::left:
					if (damier[m.to.l][m.to.c - 1] != CV)  {
						if (m.from.c <= 11 and m.from.c - 1 < COL)
						{
							x -= DELTA_X;
							m.to.c = m.from.c - 1;
							m.to.l = m.from.l;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							C--;
							deplacement++;
						}
					}
					break;
				case Ak::right:
					if (damier[m.to.l][m.to.c + 1] != CV) {
						if (m.from.c + 1 >= 0 and m.from.c + 1 < COL)
						{
							x += DELTA_X;
							m.to.l = m.from.l;
							m.to.c = m.from.c + 1;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							C++;
							deplacement++;
						}
					}
					break;
				case Ak::down:
					if (damier[m.to.l + 1][m.to.c] != CV) {
						if (m.from.c >= 0 and m.from.l + 1 < LIG)
						{
							y += DELTA_Y;
							m.to.l = m.from.l + 1;
							m.to.c = m.from.c;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							L++;
							deplacement++;
						}
					}
					break;
				case Ak::up_left:
					if (damier[m.to.l - 1][m.to.c - 1] != CV) {
						if (m.from.c - 1 >= 0 and m.from.l - 1 < LIG)
						{
							y -= DELTA_Y;
							x -= DELTA_X;
							m.to.l = m.from.l - 1;
							m.to.c = m.from.c - 1;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							L--;
							C--;
							deplacement++;
						}
					}
					break;
				case Ak::down_left:
					if (damier[m.to.l + 1][m.to.c - 1] != CV) {
						if (m.from.c - 1 >= 0 and m.from.l + 1 < LIG)
						{
							y += DELTA_Y;
							x -= DELTA_X;
							m.to.l = m.from.l + 1;
							m.to.c = m.from.c - 1;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							L++;
							C--;
							deplacement++;
						}
					}
					break;
				case Ak::up_right:
					if (damier[m.to.l - 1][m.to.c + 1] != CV) {
						if (m.from.c + 1 >= 0 and m.from.l - 1 < LIG)
						{
							y -= DELTA_Y;
							x += DELTA_X;
							m.to.l = m.from.l - 1;
							m.to.c = m.from.c + 1;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							L--;
							C++;
							deplacement++;
						}
					}
					break;
				case Ak::down_right:
					if (damier[m.to.l + 1][m.to.c + 1] != CV) {
						if (m.from.c + 1 >= 0 and m.from.l + 1 < LIG)
						{
							y += DELTA_Y;
							x += DELTA_X;
							m.to.l = m.from.l + 1;
							m.to.c = m.from.c + 1;
							damier[m.from.l][m.from.c] = futur[damier[m.from.l][m.from.c]];
							C++;
							L++;
							deplacement++;
						}
					}
					break;
				}
				if (damier[m.to.l][m.to.c] == CD)					// Compteur de dollars
				{
					compteurdollars++;
				}
			}
		}
		m.from.c = m.to.c;
		m.from.l = m.to.l;
	} while (compteurdollars != 15);

	system("CLS");
	cout << setfill(' ');
	if (compteurdollars == 15)										// Si le joueur réussi à avoir 15 $$$$
	{
		setcolor(Color::grn);
		cout << "VICTOIRE !\n\n";
		cout << " Total des points               :" << compteurdollars << " sur un objectif de 15\n\n";
		cout << " Total des d\202placements         :" << deplacement << endl << endl;
		cout << " Temps \202coul\202                   :" << "Je n'ai pas reussi a le faire" << "\n\n\n";
		cout << " Appuyez sur 'Q' pour quitter";
		_getch();
	}
}


