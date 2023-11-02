#pragma once

#include <string>

using namespace std;


// Définition (et non déclaration) de la constante MAX

// note1 : La définition de MAX doit être dans le fichier d'en-tête car le compilateur en a besoin pour le tableau dans la "struct Type".
//         Une déclatation de MAX ne serait pas acceptée par le compilateur.

// note2 : Sachant que la définition de MAX va être copiée autant de fois qu'il y a de #include "module_b.h" dans le programme,
//         la constante MAX existera en multiple copies. Il est donc important quelle soit donc privée, c'est-à-dire static.


const int SIZE = 2; // définition implicitement static


struct Type
{
	// ... d'autres membres

	string tableau [SIZE];
};


// prototype

void doSomething(Type var);