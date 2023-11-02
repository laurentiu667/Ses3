#pragma once

#include <string>

using namespace std;


// D�finition (et non d�claration) de la constante MAX

// note1 : La d�finition de MAX doit �tre dans le fichier d'en-t�te car le compilateur en a besoin pour le tableau dans la "struct Type".
//         Une d�clatation de MAX ne serait pas accept�e par le compilateur.

// note2 : Sachant que la d�finition de MAX va �tre copi�e autant de fois qu'il y a de #include "module_b.h" dans le programme,
//         la constante MAX existera en multiple copies. Il est donc important quelle soit donc priv�e, c'est-�-dire static.


const int SIZE = 2; // d�finition implicitement static


struct Type
{
	// ... d'autres membres

	string tableau [SIZE];
};


// prototype

void doSomething(Type var);