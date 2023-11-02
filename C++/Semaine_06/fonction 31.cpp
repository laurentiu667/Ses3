#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>

using namespace std;

/*

 FONCTION AVEC DES PARAM�TRES DE TYPE TABLEAUX

 1) Une fonction peut avoir un ou des param�tres de type tableau de: (ex: double T[S]  --> "tableau de S double" ).

 2) Un param�tre de type tableau est une variable locale qui contient l'adresse d'un autre tableau. Il s'agit d'un passage par valeur ou la valeur pass�e est une adresse.
    Cette valeur sera connu seulement lors de l'appel � la fonction.

 3) Avec l'adresse, la fonction peut acc�der en lecture et en �criture au contenu du tableau d'origine.

 4) R�gle g�n�rale, on jumelle toujours � un tableau pass� en param�tre, un autre param�tre qui indique sa taille. Avec l'adresse et la taille, la fonction
    peut parcourir le tableau. Si aucune taille n'est donn�e, une valeur butoire doit exister dans le tableau.
 

 Note1: Un tableau n'est jamais copi� lors d'un appel, seule son adresse l'est.

 Note2: Par contre, si un tableau est encapsul� dans une structure, et que celle-ci fait l'objet d'un passage par valeur, alors il est possible que le
        tableau soit copi�.

*/


// EXEMPLES

// A) Fonction somme avec deux param�tres pass�s par valeur : un tableau de double et sa taille

// Note: remarqu� l'absence de valeur entre les crochets "[]" dans la d�finition du param�tre T. M�me si vous mettez une valeur elle sera ignor�e.

// Note: T prendra pour valeur l'adresse du tableau sp�cifi� lors de l'appel � cette fonction.

double somme(double T[], size_t size)
{
	double som = 0.0;
	for (size_t d = 0; d < size; ++d)
		som += T[d];
	return som;
}



// B) Fonction existe cherche l'existance d'une valeur dans un tableau. Retourne vrai ou faux, et dans indice la position trouv�e.
//    Cette fonction a 3 param�tres pass�s par valeur et un par r�f�rence

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



// C-1) Fonction pour encrypter la chaine T de grandeur size. La cl� (key) initialise correctement le g�n�rateur.

void encrypte(char T[], size_t size, int key)
{
	srand(key);
	for (size_t c = 0; c < size; ++c)
		T[c] += rand() % 51;
}

// C-2) Fonction pour decrypter la chaine T avec la cl� (key), pr�alablement encrypt� avec la fonction ci-haut et la m�me cl�

// note: ici, par exemple, la grandeur de la chaine T n'est pas pass�e en param�tre, car on assume que la chaine T poss�de la valeur butoire z�ro au bout.
//       C'est une erreur grave si cette valeur butoire n'est pas pr�sente.

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

	// L'adresse de A est copie dans T, le param�tre d'entr�e de la fonction somme
	som = somme(N, MAX);


	// B) existe()

	string invit�s[MAX] = { "Camille", "Henri", "Delphine", "Louis", "Margaux" };

	size_t i;
	string la_personne = "Louis";

	if (existe(invit�s, MAX, la_personne, i))
		cout << la_personne << " figure dans la liste en position " << i+1;
	else
		cout << la_personne << " n'est pas sur la liste";
	cout << endl << endl;


	// C) encrypte() et decrypte()

	int key = 2020;
	char message[54+1] = "Le vif renard brun saute par-dessus le chien paresseux"; // apr�s le dernier caract�re 'x', il y a la valeur butoire '\0'

	cout << message << endl << endl;

	encrypte(message, 54, key);	cout << message << endl << endl;
	decrypte(message, key);		cout << message << endl << endl;

	_getch();
}