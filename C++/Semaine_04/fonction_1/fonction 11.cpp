#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

/*

	FONCTION

	PARAM�TRE PASS� PAR VALEUR

		- une fonction peut avoir plusieurs param�tres de type diff�rents

			Type nom_fonction (Type param, ...)
			{

			}


		- la valeur d'un param�tre provient de l'expression fournie lors de l'appel � la fonction

			nom_fonction(expression, ...);


		- suite � l'�valuation de l'expression, la valeur est implicitement affect�e au param�tre

			param = expression;  // implicite et transparent, � ne pas faire


		- cette fa�on d'initialiser le param�tre est d�sign�e comme �tant un "passage par valeur" (de l'information)
	

		- note: le passage par r�f�rence et le passage par adresse sont aussi possibles. � suivre ...

*/

const double TPS = 0.05;
const double TVQ = 0.09975;

double lireMontant(string clientNom)
{
	double montant = 0;
	cout << clientNom << ", quel est le montant de votre facture ? ";
	cin >> montant;
	return montant;
}

double calculerTaxes(double montant)
{
	double taxes;
	taxes = montant * (TPS+TVQ);
	return taxes;
}

double calculerPourboire(double montant, double taux)
{
	double pourboire;
	pourboire = montant * taux;
	return pourboire;
}

void afficheMontant(string titre, double montant)
{
	cout << fixed << setprecision(2);
	cout << left << setw(10) << titre << " : " << right << setw(7) << montant << " $" << endl;
}

void afficherFacture(double montant, double pourboire, double taxes)
{
	cout << endl;
	afficheMontant("montant", montant);
	afficheMontant("pourboire", pourboire);
	afficheMontant("taxes", taxes);
	cout << endl;
	afficheMontant("TOTAL", montant + pourboire + taxes);
}

int main()
{
	double facture = lireMontant("Ariane");
	afficherFacture(facture, calculerPourboire(facture, 0.15), calculerTaxes(facture));
	_getch();
}