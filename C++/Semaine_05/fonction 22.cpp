#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

/*

 FONCTION AVEC DES PARAM�TRES AYANT DES VALEURS PAR D�FAUT

	1) Une fonction peut avoir des param�tres pour lesquels on peut sp�cifier une valeur par d�faut

	2) Les r�gles � respecter:

		a) Cette valeur doit �tre du bon type
		b) Si un param�tre (p) a une valeur par d�faut, alors le param�tre suivant (� droite) a aussi une valeur par d�faut

	
	3) Attention: le fait d'utiliser des valeurs par d�faut dans une fonction peut provoquer une ambiguit�
	   au niveau des surcharges de cette fonction

	4) Attention: c'est dans la d�claration de la fonction qu'il faut donner les valeurs par d�fauts et non dans la d�finition,
	   � moins qu'il n'y ait pas de d�claration

 */


const double TPS = 0.05, TVQ = 0.09975;

// d�finition 1)
double taxer(double montant, double taxe_1 = TPS, double taxe_2 = TVQ)		// 2 param�tres ont des valeurs par d�faut
{
	return montant * (1 + taxe_1 + taxe_2);
}


// d�finition 2)
void ligner(int size, char c = '-')											// 1 param�tre a une valeur par d�faut
{
	cout << setw(size) << setfill(c) << "" << setfill(' ');
}


// d�finition 3)
void f(int a = 10, int b = 20, int c = 30)									// tous les param�tres ont des valeurs par d�faut
{
	//...
}



// Attention aux surcharges qui pourraient �tre conflictuelles

// d�finition 4)

/*
	void ligner(int size)		// en conflit avec la d�finition 2)
	{
		// ...
	}
*/

// cette surcharge provoquera une erreur de lien car le compilateur ne saura pas quelle d�finition utiliser avec l'appel:  ligner(20);
// est-ce la d�finition 2) ou est-ce la d�finition 4)



int main()
{

// 1) les 3 fa�ons d'appeler la fonction taxer
	
	taxer(100.50);
	taxer(100.50, 0.1);
	taxer(100.50, 0.1, 0.05);

	// syntaxe invalide  -->  taxer(100.50 ,  , 0.05);


// 2) les 2 fa�ons d'appeler la fonction ligner

	ligner(10);
	ligner(20,'+');

	// syntaxe invalide  -->  ligner();


// 3) les 4 fa�ons d'appeler la fonction f

	f();
	f(1);
	f(2,3);
	f(4,5,6);

	// syntaxe invalide  -->  f( , 5 );


	_getch();
}