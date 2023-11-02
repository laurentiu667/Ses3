#include <iostream>
#include <string>

#include "module.h"

using namespace std;


// 1) EXEMPLES DE D�FINITIONS DE VARIABLES GLOBALES **PUBLIQUES**

// note 1: par d�faut la variable globale est publique donc implicitement "extern"
// note 2: les variables globales (contrairement aux variables locales) sont initialis�es implicitement � z�ro, si l'instruction d'initialisation est omise.

int total;

double moyenne = 85.5;

string cours = "C21";


// 2) EXEMPLES DE D�FINITIONS DE VARIABLES GLOBALES **PRIV�ES** AU MODULE

// note: le mot cl� "static" est requis pour avoir une variable globale priv�e

static bool �chec; // init � z�ro donc false

static float bonus = .25;

static char choix = 'M';


// 3) EXEMPLE DE D�FINITION DE VARIABLE GLOBALE **PRIV�E** � UNE FONCTION DU MODULE

// note 1: le mot cl� "static" est requis ici pour avoir une variable globale priv�e � la fonction
// note 2: la cr�ation et l'initialisation de la variable globale sont effectu�es lors du d�marrage du programme. Cette instruction sera ignor�e par la suite.

void doSomething()
{ 
	static int count = 0; // variable globale et priv�e � doSomething()

	// du code ici

	count++;

	cout << "nombre d'appels \x85 la fonction doSomething(): " << count << endl;
}


// 4) EXEMPLES DE D�FINITIONS DE VARIABLES GLOBALES **PUBLIQUES** AVEC LE MOT CL� EXTERN

// note: Il est possible de mettre explicitement le mot cl� "extern" devant la d�finition d'une variable globale,
//       mais vous devez fournir une valeur d'initialisation sinon le compilateur assumera que c'est une d�claration.

extern int somme = 10;

extern double temperatue = 32.5;

extern string virus = "Covid 19";