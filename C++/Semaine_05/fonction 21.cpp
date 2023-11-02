#include <iostream>
#include <conio.h>

using namespace std;

/*

 FONCTION SURCHARG�E

	 1) Une fonction F est dite surcharg�e (overloaded) lorsqu'il existe plus d'une d�finition avec le m�me nom

	 2) Il est possible de r�utiliser le nom d'une fonction pour en d�finir d'autres pourvu qu'elles puissent �tre multuellement
		 diff�renci�es les unes des autres, par le compilateur, � l'aide de leurs param�tres respectifs

		crit�res de diff�renciations:

			a) le nombre de param�tres
			b) les types de ces param�tres

		Note1: On dit aussi qu'elles doivent avoir une signature diff�rente, la signature �tant le nom et les param�tres
		Note2: La signature n'inclut pas le type de retour de la fonction

	 3) Le compilateur doit pouvoir, lors de l'analyse, associer chaque appel de fonction � une et une seule d�finition de fonction
		C'est une erreur si:
			a) la d�finition n'existe pas
			b) de multiple d�finitions concordent pour un appel

		Note3: il s'agit d'erreur de lien (link error)

 */

const double �valuation = 0.0; // constante bidon


struct Habitation
{
	// membres quelconques
};

struct V�hicule
{
	// membres quelconques
};

struct Examen
{
	// membres quelconques
};


// EXEMPLES

// 1) Premi�re d�finition de la fonction �valuer
double �valuer(Habitation h)
{	
	// instructions
	return �valuation;
}


// 2) surcharge de la fonction �valuer
double �valuer(Habitation h, double taxes, double loyers)
{	
	// instructions
	return �valuation;
}


// 3) surcharge de la fonction �valuer
double �valuer(V�hicule v, int km)
{	
	// instructions
	return �valuation;
}

// 4) surcharge de la fonction �valuer
double �valuer(Examen e)
{	
	// instructions
	return �valuation;
}

/*

	// 5) surcharge ambigu� non autoris� car m�me signature que 4): le type de retour ne change pas la signature

	char �valuer(Examen e)
	{	
		// instructions
	}


	// 6) surcharge ambigu� non autoris� car m�me signature que 4): une r�f�rence ne change pas la signature

	double �valuer(Examen &e)
	{	
		// instructions
	}


	// 7) surcharge ambigu� non autoris� car m�me signature que 2): m�mes listes de types de param�tres

	double �valuer(Habitation h, double cotation_du_cartier, double assurances)
	{
		// instructions
	}


*/

int main()
{
	Examen mon_exam;
	V�hicule la_gti;
	Habitation le_tipi, le_triplex;

	// exemples d'appels

	cout << �valuer(le_tipi);

	cout << �valuer(le_triplex, 0.15, 28800.50);

	cout << �valuer(la_gti, 37500);

	cout << �valuer(mon_exam);

	_getch();
}