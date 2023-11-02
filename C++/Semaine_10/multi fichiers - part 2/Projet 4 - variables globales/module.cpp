#include <iostream>
#include <string>

#include "module.h"

using namespace std;


// 1) EXEMPLES DE DÉFINITIONS DE VARIABLES GLOBALES **PUBLIQUES**

// note 1: par défaut la variable globale est publique donc implicitement "extern"
// note 2: les variables globales (contrairement aux variables locales) sont initialisées implicitement à zéro, si l'instruction d'initialisation est omise.

int total;

double moyenne = 85.5;

string cours = "C21";


// 2) EXEMPLES DE DÉFINITIONS DE VARIABLES GLOBALES **PRIVÉES** AU MODULE

// note: le mot clé "static" est requis pour avoir une variable globale privée

static bool échec; // init à zéro donc false

static float bonus = .25;

static char choix = 'M';


// 3) EXEMPLE DE DÉFINITION DE VARIABLE GLOBALE **PRIVÉE** À UNE FONCTION DU MODULE

// note 1: le mot clé "static" est requis ici pour avoir une variable globale privée à la fonction
// note 2: la création et l'initialisation de la variable globale sont effectuées lors du démarrage du programme. Cette instruction sera ignorée par la suite.

void doSomething()
{ 
	static int count = 0; // variable globale et privée à doSomething()

	// du code ici

	count++;

	cout << "nombre d'appels \x85 la fonction doSomething(): " << count << endl;
}


// 4) EXEMPLES DE DÉFINITIONS DE VARIABLES GLOBALES **PUBLIQUES** AVEC LE MOT CLÉ EXTERN

// note: Il est possible de mettre explicitement le mot clé "extern" devant la définition d'une variable globale,
//       mais vous devez fournir une valeur d'initialisation sinon le compilateur assumera que c'est une déclaration.

extern int somme = 10;

extern double temperatue = 32.5;

extern string virus = "Covid 19";