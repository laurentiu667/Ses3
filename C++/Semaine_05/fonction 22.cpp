#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

/*

 FONCTION AVEC DES PARAMÈTRES AYANT DES VALEURS PAR DÉFAUT

	1) Une fonction peut avoir des paramètres pour lesquels on peut spécifier une valeur par défaut

	2) Les règles à respecter:

		a) Cette valeur doit être du bon type
		b) Si un paramètre (p) a une valeur par défaut, alors le paramètre suivant (à droite) a aussi une valeur par défaut

	
	3) Attention: le fait d'utiliser des valeurs par défaut dans une fonction peut provoquer une ambiguité
	   au niveau des surcharges de cette fonction

	4) Attention: c'est dans la déclaration de la fonction qu'il faut donner les valeurs par défauts et non dans la définition,
	   à moins qu'il n'y ait pas de déclaration

 */


const double TPS = 0.05, TVQ = 0.09975;

// définition 1)
double taxer(double montant, double taxe_1 = TPS, double taxe_2 = TVQ)		// 2 paramètres ont des valeurs par défaut
{
	return montant * (1 + taxe_1 + taxe_2);
}


// définition 2)
void ligner(int size, char c = '-')											// 1 paramètre a une valeur par défaut
{
	cout << setw(size) << setfill(c) << "" << setfill(' ');
}


// définition 3)
void f(int a = 10, int b = 20, int c = 30)									// tous les paramètres ont des valeurs par défaut
{
	//...
}



// Attention aux surcharges qui pourraient être conflictuelles

// définition 4)

/*
	void ligner(int size)		// en conflit avec la définition 2)
	{
		// ...
	}
*/

// cette surcharge provoquera une erreur de lien car le compilateur ne saura pas quelle définition utiliser avec l'appel:  ligner(20);
// est-ce la définition 2) ou est-ce la définition 4)



int main()
{

// 1) les 3 façons d'appeler la fonction taxer
	
	taxer(100.50);
	taxer(100.50, 0.1);
	taxer(100.50, 0.1, 0.05);

	// syntaxe invalide  -->  taxer(100.50 ,  , 0.05);


// 2) les 2 façons d'appeler la fonction ligner

	ligner(10);
	ligner(20,'+');

	// syntaxe invalide  -->  ligner();


// 3) les 4 façons d'appeler la fonction f

	f();
	f(1);
	f(2,3);
	f(4,5,6);

	// syntaxe invalide  -->  f( , 5 );


	_getch();
}