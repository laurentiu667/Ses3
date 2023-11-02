#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

/*

DÉFINITION ET APPEL D'UNE FONCTION (AVEC UNE LISTE DE PARAMÈTRES)

A) définition de la fonction

	void nom_de_la_fonction ( Type param_1 , Type param_2 , .... , Type param_N )
	{
		// instructions utilisant les informations contenues dans les paramètres
		// ...
	}

	notes:
	- les paramètres sont des variables locales spéciales (des contenants)
	- les informations contenues dans ces paramètres seront données par la fonction appelante
	- ces informations seront ensuite utilisées par les instructions de la fonction


	notes dans l'ordre:
	- les paramètres seront créés avant l'exécution des instructions de la fonction
	- les paramètres seront ensuite initialisés avec les valeurs données lors de l'appel
	- les paramètres seront alors utilisés par les instructions de la fonction
	- les paramètres seront détruits à la fin de la fonction


B) appel à la fonction

	nom_de_la_fonction ( expression_1 , expression_2 , ... , expression_N );

	notes:
	- lors de l'appel, il faut donner, dans l'ordre, une valeur (une expression) pour chaque paramètre de la fonction
	- chaque expression doit être du bon type, c'est à dire celui du paramètre

*/

void saluer(string nom)
{
	cout << "Bonjour " << nom << "\n\n";
}

void afficher_facture_entête(string nom_du_client, string nom_du_commerce)
{
	saluer(nom_du_client);
	cout << "  merci de faire confiance \x85 " << nom_du_commerce << " !" << endl << endl;
}

void afficher_facture_détails(double prix_unitaire, double quantité, double taxe_1, double taxe_2)
{	
	double montant_brute = prix_unitaire * quantité;
	double montant_total = montant_brute * (1 + taxe_1 + taxe_2);
	cout
		<< fixed << setprecision(2)
		<< "Votre facture:" << "\n\n" << montant_brute << "$  +taxes: " << montant_brute * (taxe_1 + taxe_2) << "$" << "\n\n"
		<< "Total: " << montant_total << " $" << endl;
}

int main()
{
	const double TVQ = 0.09975, TPS = 0.05;			// taux de taxes
	const double prix = 40;							// ($) par kilo de café en grain expresso

	double pesée_du_sac = 1.25;						// kilo

	afficher_facture_entête("Gustavio", "Cafe Olimpico inc");
	afficher_facture_détails(prix, pesée_du_sac, TVQ, TPS);

	_getch(); 
}