#include <iostream>
#include <conio.h>

using namespace std;

/*
 
	 DÉFINITION D'UNE RÉFÉRENCE (UNE VARIABLE SPÉCIALE)
 
		- définir une référence consiste à créer un autre nom, un alias, pour accéder au contenant d'une autre variable

		- le nom de cette référence devient alors une alternative pour lire ou modifier le contenu de cette autre variable

		- il est permit de définir plusieurs références vers la même variable
	
	
		note: en C++, une référence est une variable spéciale qui utilise le contenant d'une autre variable

 
	 SYNTAXE

		Type & variable_référence = variable_référée ;

		- la définition d'une variable référence doit spécifier le 'Type' de la variable référée
	
		- l'usage du symbole '&' ici indique qu'il s'agit d'une référence

		- l'usage du symbole '=' est obligatoire pour indiquer la variable à référer
	

		note: une fois définie, la référence est fixée et ne peut pas changer
	
	
		exemple: 
	
			int var;			// une variable 'var' de type int
	
			int & ref = var ;	// une variable référence 'ref' de type 'int &' sur la variable 'var'
	
			ref = 100;			// 'var' vaut 100 maintenant

*/


int main()
{
	// exemple 1)

	int nombre = 10;
	int & ma_ref = nombre; // la référence ma_ref de type 'int &' permet d'accéder au contenu de nombre, en lecture et en écriture.
	
	ma_ref += 20;
	cout << nombre;

	// exemple 2)

	const double pythagore = 3.1416;
	const double & pi = pythagore; // la référence pi de type 'const double &' permet d'accéder au contenu de pythagore en lecture seulement.

	// exemple 3)

	enum Embrayage { manuel, automatic };

	struct Transmission
	{
		Embrayage emb;
		int vitesses;
	};

	struct Voiture
	{
		string marque;
		string modele;
		Transmission trans;
		int annee;
		double prix;
	};
	
	Voiture	automobile = { "subaru", "wrx", { manuel, 6 }, 2021, 35000 };
	
	Voiture& v = automobile;	// v: une référence de type 'Voiture &' qui permet d'accéder au contenu de 'automobile', en lecture et en écriture
	v.prix = v.prix * 1.14975;	// ajouter les taxes

	// exemple 4)

	Voiture liste[2] = { { "vw", "gti", { manuel, 6 }, 2021, 35000 }, { "audi", "a3", { automatic, 5 }, 2021, 37000 } };
	
	Voiture & vw = liste[0];			// vw: une référence sur la première voiture de la liste
	Voiture & audi = liste[1];			// audi: une référence sur la deuxième voiture de la liste

	audi.modele = "a4";
	audi.annee = 2022;

	if (audi.annee > 2021)
		audi.prix += 2000;

	// exemple 5)

	double& le_prix = liste[0].prix;		// le_prix: une référence sur le prix de la première voiture de la liste

	string& la_marque = vw.marque;			// marque: une référence sur la marque de vw

	int& vit = liste[0].trans.vitesses;		// vit: une référence sur le nombre de vitesse de la première voiture de la liste

	int& année = audi.annee;				// année: une référence sur l'année de audi

	_getch();
}