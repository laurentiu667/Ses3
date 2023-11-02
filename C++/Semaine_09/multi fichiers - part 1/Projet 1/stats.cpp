// 1) INCLUDES STANDARDS - � mettre en premier et seulement ceux qui sont n�cessaires pour ce cpp
#include <math.h> // pour pow() et sqrt()

// 2) INCLUDES PARTICULIERS - toujours inclure son propre fichier d'en-t�te
#include "stats.h"


// 3) D�FINITIONS DES FONCTIONS PRIV�ES (static) DU MODULE

static double somme(double notes[], size_t size)  // pour usage exclusif � la fonction moyenne()
{
	double som = 0;
	for (size_t n = 0; n < size; ++n)
		som += notes[n];
	return som;
}

// 4) D�FINITIONS DES FONCTIONS PUBLIQUES DU MODULE 

double moyenne(double notes[], size_t size)
{
	return size ? somme(notes, size) / size : 0; // test de division pas z�ro
}

double variance(double notes[], size_t size)
{
	double
		var = 0,
		moy = moyenne(notes, size);

	for (size_t n = 0; n < size; ++n)
		var += pow(notes[n] - moy, 2);

	return size ? var / size : 0;
}

double ecart_type(double notes[], size_t size)
{
	double var = variance(notes, size);
	return size ? sqrt(var) : 0;
}