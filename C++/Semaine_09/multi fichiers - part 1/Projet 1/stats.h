// 1) DIRECTIVE #PRAGMA ONCE - � mettre obligatoirement � la premi�re ligne du fichier d'en-t�te

#pragma once

// 2) D�CLARATIONS DES FONCTIONS PUBLIQUES DU MODULE

double moyenne(double notes[], size_t size);
double variance(double notes[], size_t size);
double ecart_type(double notes[], size_t size);


// note: la d�claration de la fonction somme() n'est pas ajout� ici car c'est une fonction priv�e du module