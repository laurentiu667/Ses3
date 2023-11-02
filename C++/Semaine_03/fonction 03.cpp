#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

/*

D�FINITION ET APPEL D'UNE FONCTION (AVEC UNE LISTE DE PARAM�TRES)

A) d�finition de la fonction

	void nom_de_la_fonction ( Type param_1 , Type param_2 , .... , Type param_N )
	{
		// instructions utilisant les informations contenues dans les param�tres
		// ...
	}

	notes:
	- les param�tres sont des variables locales sp�ciales (des contenants)
	- les informations contenues dans ces param�tres seront donn�es par la fonction appelante
	- ces informations seront ensuite utilis�es par les instructions de la fonction


	notes dans l'ordre:
	- les param�tres seront cr��s avant l'ex�cution des instructions de la fonction
	- les param�tres seront ensuite initialis�s avec les valeurs donn�es lors de l'appel
	- les param�tres seront alors utilis�s par les instructions de la fonction
	- les param�tres seront d�truits � la fin de la fonction


B) appel � la fonction

	nom_de_la_fonction ( expression_1 , expression_2 , ... , expression_N );

	notes:
	- lors de l'appel, il faut donner, dans l'ordre, une valeur (une expression) pour chaque param�tre de la fonction
	- chaque expression doit �tre du bon type, c'est � dire celui du param�tre

*/

void saluer(string nom)
{
	cout << "Bonjour " << nom << "\n\n";
}

void afficher_facture_ent�te(string nom_du_client, string nom_du_commerce)
{
	saluer(nom_du_client);
	cout << "  merci de faire confiance \x85 " << nom_du_commerce << " !" << endl << endl;
}

void afficher_facture_d�tails(double prix_unitaire, double quantit�, double taxe_1, double taxe_2)
{	
	double montant_brute = prix_unitaire * quantit�;
	double montant_total = montant_brute * (1 + taxe_1 + taxe_2);
	cout
		<< fixed << setprecision(2)
		<< "Votre facture:" << "\n\n" << montant_brute << "$  +taxes: " << montant_brute * (taxe_1 + taxe_2) << "$" << "\n\n"
		<< "Total: " << montant_total << " $" << endl;
}

int main()
{
	const double TVQ = 0.09975, TPS = 0.05;			// taux de taxes
	const double prix = 40;							// ($) par kilo de caf� en grain expresso

	double pes�e_du_sac = 1.25;						// kilo

	afficher_facture_ent�te("Gustavio", "Cafe Olimpico inc");
	afficher_facture_d�tails(prix, pes�e_du_sac, TVQ, TPS);

	_getch(); 
}