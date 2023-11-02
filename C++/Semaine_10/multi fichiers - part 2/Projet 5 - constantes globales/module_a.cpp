#include <iostream>
#include <string>

#include "module_a.h"

using namespace std;


// 1) EXEMPLES DE D�FINITIONS DE CONSTANTES GLOBALES **PRIV�ES** AU MODULE

// note: par d�faut la constante globale est priv�e au module donc implicitement "static"

const bool FAIL = false;

const double TAX = .14975;

const int MAX = 100;


// 2) EXEMPLES DE D�FINITIONS DE CONSTANTES GLOBALES **PUBLIQUES**

// note: le mot cl� "extern" est requis pour avoir une constante globale publique

extern const double PI = 3.141592;

extern const char TAB = '\t';

extern const string CEGEP = "CVM";


// 3) EXEMPLE DE D�FINITION DE CONSTANTE GLOBALE **PRIV�E** � UNE FONCTION DU MODULE

// note 1: le mot cl� "static" est requis ici pour avoir une constante globale priv�e � la fonction
// note 2: la cr�ation et l'initialisation de la constante globale sont effectu�es lors du d�marrage du programme. Cette instruction sera ignor�e par la suite.

void doSomething()
{ 
	static const int BATCHSIZE = 100; // constante globale et priv�e � doSomething()

	// du code ici

	// ...

	cout << BATCHSIZE << endl;
}


// 4) EXEMPLES DE D�FINITIONS DE CONSTANTES GLOBALES **PRIV�ES** AVEC LE MOT CL� STATIC

// note: Il est possible de mettre explicitement le mot cl� "static" devant la d�finition d'une constante globale mais cela ne change rien sauf pour le cas 3)

static const int DATE = 2020;

static const double LIGHTSPEED = 300000.0;

static const string CORONA = "Covid 19";