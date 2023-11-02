#include <iostream>
#include <conio.h>

using namespace std;

/*

 FONCTION SURCHARGÉE

	 1) Une fonction F est dite surchargée (overloaded) lorsqu'il existe plus d'une définition avec le même nom

	 2) Il est possible de réutiliser le nom d'une fonction pour en définir d'autres pourvu qu'elles puissent être multuellement
		 différenciées les unes des autres, par le compilateur, à l'aide de leurs paramètres respectifs

		critères de différenciations:

			a) le nombre de paramètres
			b) les types de ces paramètres

		Note1: On dit aussi qu'elles doivent avoir une signature différente, la signature étant le nom et les paramètres
		Note2: La signature n'inclut pas le type de retour de la fonction

	 3) Le compilateur doit pouvoir, lors de l'analyse, associer chaque appel de fonction à une et une seule définition de fonction
		C'est une erreur si:
			a) la définition n'existe pas
			b) de multiple définitions concordent pour un appel

		Note3: il s'agit d'erreur de lien (link error)

 */

const double évaluation = 0.0; // constante bidon


struct Habitation
{
	// membres quelconques
};

struct Véhicule
{
	// membres quelconques
};

struct Examen
{
	// membres quelconques
};


// EXEMPLES

// 1) Première définition de la fonction évaluer
double évaluer(Habitation h)
{	
	// instructions
	return évaluation;
}


// 2) surcharge de la fonction évaluer
double évaluer(Habitation h, double taxes, double loyers)
{	
	// instructions
	return évaluation;
}


// 3) surcharge de la fonction évaluer
double évaluer(Véhicule v, int km)
{	
	// instructions
	return évaluation;
}

// 4) surcharge de la fonction évaluer
double évaluer(Examen e)
{	
	// instructions
	return évaluation;
}

/*

	// 5) surcharge ambiguë non autorisé car même signature que 4): le type de retour ne change pas la signature

	char évaluer(Examen e)
	{	
		// instructions
	}


	// 6) surcharge ambiguë non autorisé car même signature que 4): une référence ne change pas la signature

	double évaluer(Examen &e)
	{	
		// instructions
	}


	// 7) surcharge ambiguë non autorisé car même signature que 2): mêmes listes de types de paramètres

	double évaluer(Habitation h, double cotation_du_cartier, double assurances)
	{
		// instructions
	}


*/

int main()
{
	Examen mon_exam;
	Véhicule la_gti;
	Habitation le_tipi, le_triplex;

	// exemples d'appels

	cout << évaluer(le_tipi);

	cout << évaluer(le_triplex, 0.15, 28800.50);

	cout << évaluer(la_gti, 37500);

	cout << évaluer(mon_exam);

	_getch();
}