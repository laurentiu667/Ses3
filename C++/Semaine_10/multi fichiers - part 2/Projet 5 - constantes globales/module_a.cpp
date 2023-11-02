#include <iostream>
#include <string>

#include "module_a.h"

using namespace std;


// 1) EXEMPLES DE DÉFINITIONS DE CONSTANTES GLOBALES **PRIVÉES** AU MODULE

// note: par défaut la constante globale est privée au module donc implicitement "static"

const bool FAIL = false;

const double TAX = .14975;

const int MAX = 100;


// 2) EXEMPLES DE DÉFINITIONS DE CONSTANTES GLOBALES **PUBLIQUES**

// note: le mot clé "extern" est requis pour avoir une constante globale publique

extern const double PI = 3.141592;

extern const char TAB = '\t';

extern const string CEGEP = "CVM";


// 3) EXEMPLE DE DÉFINITION DE CONSTANTE GLOBALE **PRIVÉE** À UNE FONCTION DU MODULE

// note 1: le mot clé "static" est requis ici pour avoir une constante globale privée à la fonction
// note 2: la création et l'initialisation de la constante globale sont effectuées lors du démarrage du programme. Cette instruction sera ignorée par la suite.

void doSomething()
{ 
	static const int BATCHSIZE = 100; // constante globale et privée à doSomething()

	// du code ici

	// ...

	cout << BATCHSIZE << endl;
}


// 4) EXEMPLES DE DÉFINITIONS DE CONSTANTES GLOBALES **PRIVÉES** AVEC LE MOT CLÉ STATIC

// note: Il est possible de mettre explicitement le mot clé "static" devant la définition d'une constante globale mais cela ne change rien sauf pour le cas 3)

static const int DATE = 2020;

static const double LIGHTSPEED = 300000.0;

static const string CORONA = "Covid 19";