#include <iostream>
#include <conio.h>

using namespace std;

/*
	LA FONCTION ET SES PARAM�TRES

	1) il existe 3 fa�ons usuelles de passer une information en param�tre

		A) un passage par valeur
		B) un passage par r�f�rence
		C) un passage par adresse
 */

struct Type
{
	int no;
};

void affiche(Type info)				// A) info: passage par valeur
{
	cout << info.no << endl;
}

void affiche_r(Type& info)			// B) info: passage par r�f�rence		att: fonction renomm�e car la surcharge serait ambigu� avec (A)
{ 
	cout << info.no << endl;
}

void affiche(Type* info)			// C) info: passage par adresse
{
	cout << (*info).no << endl;		// idem: info->no
}

int main()
{
	Type data = {10};

	// A) passage par valeur
	affiche({25});
	affiche(data);

	// B) passage par r�f�rence
	affiche_r(data);				// att: affiche_r( {25} ); impossible de prendre une r�f�rence simple sur {25} une valeur temporaire

	// C) passage par adresse
	Type* ptr = &data;

	affiche(ptr);
	affiche(&data);

	_getch();
}