#include <iostream>
#include <conio.h>

using namespace std;

/*
 
	 D�FINITION D'UNE R�F�RENCE (UNE VARIABLE SP�CIALE)
 
		- d�finir une r�f�rence consiste � cr�er un autre nom, un alias, pour acc�der au contenant d'une autre variable

		- le nom de cette r�f�rence devient alors une alternative pour lire ou modifier le contenu de cette autre variable

		- il est permit de d�finir plusieurs r�f�rences vers la m�me variable
	
	
		note: en C++, une r�f�rence est une variable sp�ciale qui utilise le contenant d'une autre variable

 
	 SYNTAXE

		Type & variable_r�f�rence = variable_r�f�r�e ;

		- la d�finition d'une variable r�f�rence doit sp�cifier le 'Type' de la variable r�f�r�e
	
		- l'usage du symbole '&' ici indique qu'il s'agit d'une r�f�rence

		- l'usage du symbole '=' est obligatoire pour indiquer la variable � r�f�rer
	

		note: une fois d�finie, la r�f�rence est fix�e et ne peut pas changer
	
	
		exemple: 
	
			int var;			// une variable 'var' de type int
	
			int & ref = var ;	// une variable r�f�rence 'ref' de type 'int &' sur la variable 'var'
	
			ref = 100;			// 'var' vaut 100 maintenant

*/


int main()
{
	// exemple 1)

	int nombre = 10;
	int & ma_ref = nombre; // la r�f�rence ma_ref de type 'int &' permet d'acc�der au contenu de nombre, en lecture et en �criture.
	
	ma_ref += 20;
	cout << nombre;

	// exemple 2)

	const double pythagore = 3.1416;
	const double & pi = pythagore; // la r�f�rence pi de type 'const double &' permet d'acc�der au contenu de pythagore en lecture seulement.

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
	
	Voiture& v = automobile;	// v: une r�f�rence de type 'Voiture &' qui permet d'acc�der au contenu de 'automobile', en lecture et en �criture
	v.prix = v.prix * 1.14975;	// ajouter les taxes

	// exemple 4)

	Voiture liste[2] = { { "vw", "gti", { manuel, 6 }, 2021, 35000 }, { "audi", "a3", { automatic, 5 }, 2021, 37000 } };
	
	Voiture & vw = liste[0];			// vw: une r�f�rence sur la premi�re voiture de la liste
	Voiture & audi = liste[1];			// audi: une r�f�rence sur la deuxi�me voiture de la liste

	audi.modele = "a4";
	audi.annee = 2022;

	if (audi.annee > 2021)
		audi.prix += 2000;

	// exemple 5)

	double& le_prix = liste[0].prix;		// le_prix: une r�f�rence sur le prix de la premi�re voiture de la liste

	string& la_marque = vw.marque;			// marque: une r�f�rence sur la marque de vw

	int& vit = liste[0].trans.vitesses;		// vit: une r�f�rence sur le nombre de vitesse de la premi�re voiture de la liste

	int& ann�e = audi.annee;				// ann�e: une r�f�rence sur l'ann�e de audi

	_getch();
}