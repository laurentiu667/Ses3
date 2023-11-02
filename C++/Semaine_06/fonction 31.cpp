#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

/*

 FONCTION AVEC DES PARAMÈTRES DE TYPE TABLEAUX

 1) Une fonction peut avoir un ou des paramètres de type tableau de: (ex: double T[S]  --> "tableau de S double" ).

 2) Un paramètre de type tableau est une variable locale qui contient l'adresse d'un autre tableau. Il s'agit d'un passage par valeur ou la valeur passée est une adresse.
    Cette valeur sera connu seulement lors de l'appel à la fonction.

 3) Avec l'adresse, la fonction peut accéder en lecture et en écriture au contenu du tableau d'origine.

 4) Règle générale, on jumelle toujours à un tableau passé en paramètre, un autre paramètre qui indique sa taille. Avec l'adresse et la taille, la fonction
    peut parcourir le tableau. Si aucune taille n'est donnée, une valeur butoire doit exister dans le tableau.
 

 Note1: Un tableau n'est jamais copié lors d'un appel, seule son adresse l'est.

 Note2: Par contre, si un tableau est encapsulé dans une structure, et que celle-ci fait l'objet d'un passage par valeur, alors il est possible que le
        tableau soit copié.

*/


// EXEMPLES

// A) Fonction somme avec deux paramètres passés par valeur : un tableau de double et sa taille

// Note: remarqué l'absence de valeur entre les crochets "[]" dans la définition du paramètre T. Même si vous mettez une valeur elle sera ignorée.

// Note: T prendra pour valeur l'adresse du tableau spécifié lors de l'appel à cette fonction.

double somme(double T[], size_t size)
{
	double som = 0.0;
	for (size_t d = 0; d < size; ++d)
		som += T[d];
	return som;
}



// B) Fonction existe cherche l'existance d'une valeur dans un tableau. Retourne vrai ou faux, et dans indice la position trouvée.
//    Cette fonction a 3 paramètres passés par valeur et un par référence

bool existe(string noms[], size_t size, string nom, size_t & indice)
{
	for (size_t n = 0; n < size; ++n)
		if (noms[n] == nom)
		{
			indice = n;
			return true;
		}
	return false;
}



// C-1) Fonction pour encrypter la chaine T de grandeur size. La clé (key) initialise correctement le générateur.

void encrypte(char T[], size_t size, int key)
{
	srand(key);
	for (size_t c = 0; c < size; ++c)
		T[c] += rand() % 51;
}

// C-2) Fonction pour decrypter la chaine T avec la clé (key), préalablement encrypté avec la fonction ci-haut et la même clé

// note: ici, par exemple, la grandeur de la chaine T n'est pas passée en paramètre, car on assume que la chaine T possède la valeur butoire zéro au bout.
//       C'est une erreur grave si cette valeur butoire n'est pas présente.

void decrypte(char T[], int key)
{
	size_t c = 0;
	srand(key);
	while (T[c] != 0)
		T[c++] -= rand() % 51;
}

int main()
{
	const int MAX = 5;

	// A) somme()

	double N[MAX] = { 88.5, 75.5, 63.0, 94.5, 79.0 }, som;

	// L'adresse de A est copie dans T, le paramètre d'entrée de la fonction somme
	som = somme(N, MAX);


	// B) existe()

	string invités[MAX] = { "Camille", "Henri", "Delphine", "Louis", "Margaux" };

	size_t i;
	string la_personne = "Louis";

	if (existe(invités, MAX, la_personne, i))
		cout << la_personne << " figure dans la liste en position " << i+1;
	else
		cout << la_personne << " n'est pas sur la liste";
	cout << endl << endl;


	// C) encrypte() et decrypte()

	int key = 2020;
	char message[54+1] = "Le vif renard brun saute par-dessus le chien paresseux"; // après le dernier caractère 'x', il y a la valeur butoire '\0'

	cout << message << endl << endl;

	encrypte(message, 54, key);	cout << message << endl << endl;
	decrypte(message, key);		cout << message << endl << endl;

	_getch();
}