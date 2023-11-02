#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*
	LES POINTEURS SUITES

		pointeur				variable
		-------------			-------------
		|  adresse  |	--->	|  valeur   |
		-------------			-------------

	1) Le pointeur est une variable pour contenir l'adresse d'une autre variable (contenant)

	2) Lors de la définition d'un pointeur, il est obligatoire de spécifier le type d'information pointé par l'adresse
	   ( ex: int*, double*, string*, ma_struct*, ... ) 

	3) C'est une erreur de compilation si l'adresse affecté dans un pointeur n'est pas du bon type
 
	4) La valeur du pointeur (i.e. une adresse) peut être remplacé par une autre valeur en tout temps
 */

struct Produit
{
	int no;
	double prix;
	string description;
};

int main()
{
	Produit lait = { 1023, 3.25, "lait 2%" };
	Produit pain = { 1024, 2.25, "baguette" };

	// 1) Création d'un pointeur vers un produit.

	Produit* p;
	
	p = &lait; // copie l'adresse de lait dans p. On dit aussi que p pointe vers le produit lait


	// 2) Afficher le no produit à partir du pointeur p
	//    note: les parenthèses sont obligatoires ici car l'opérateur '.' a priorité sur l'opérateur '*'
	
	cout << "produit no: " << (*p).no << endl; // (*p) est une expression de type Produit alors que p est de type Produit*


	// 3) Modifier le prix du produit

	(*p).prix *= 1.05;

	cout << "Prix: " << (*p).prix << endl;


	// 4) Syntaxe alternative: utilisation de l'opérateur binaire '->' pour accéder à un membre d'une structure à partir d'un pointeur.
	//    l'opérande de gauche doit être un pointeur et l'opérande de droite un membre d'une structure.

	cout << "Description: " << p->description << endl; // idem que (*p).description


	// 5) Il est possible de faire pointer le pointeur p vers un autre produit

	p = &pain;	// p pointe maintenant vers le produit pain

	cout << "Description: " << p->description << endl;

	_getch();
}