// 1) DIRECTIVE #PRAGMA ONCE - à mettre obligatoirement à la première ligne du fichier d'en-tête

#pragma once

// 2) DÉCLARATIONS DES FONCTIONS PUBLIQUES DU MODULE

double moyenne(double notes[], size_t size);
double variance(double notes[], size_t size);
double ecart_type(double notes[], size_t size);


// note: la déclaration de la fonction somme() n'est pas ajouté ici car c'est une fonction privée du module