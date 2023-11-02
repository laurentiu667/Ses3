#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;


/*
 LES ADRESSES EN MÉMOIRE

 1) Chaque information conservée en mémoire possède une adresse qui est consultable.

 2) Les adresses sont consécutives en mémoire, octet par octet.

 3) L'adresse d'une information en mémoire est l'adresse du premier octet utilisé par cette information.

 4) Le nombre d'octets utilisés par une information est déterminé par son type { ex: double: sizeof(double) =  8 octets }

 5) Lors de la réservation d'un bloc d'octets en mémoire (ex: création d'une variable) c'est le système d'exploitation qui décidera de l'emplacement et donc de l'adresse de ce bloc.

 6) Il est possible, et c'est une particularité importante du langage, de créer des variables spéciales (on dit aussi des pointeurs) pour conserver l'adresse d'une information
    qui se trouve quelque part en mémoire. Avec l'adresse, il est désormais possible de se rendre à ce lieu et consulter ou modifier l'information.
 */

int main()
{
	int v = 25;

	// 1) Utilisation de l'opérateur unaire '&' (syntaxe en préfixe) qui permet d'obtenir l'adresse de l'expression à droite.
	//    note: l'adresse est un entier positif exprimé en hexa ( de 32 bits, si compilé en x86, ou de 64 bits, si compilé en x64 )
	
	cout << "1) l'adresse de v = " << &v << endl;


	// 2) Création d'une variable p de type (int *). On dit aussi de type adresse d'un int, ou pointeur vers un int.
	//    note: p est une variable pour conserver l'adresse d'un int qui sera quelque part en mémoire.
	
	int * p;

	p = &v; // mettre l'adresse de v dans p

	cout << "2) l'adresse de v = " << p << endl;


	// 3) p a aussi une adresse

	cout << "3) l'adresse de p = " << &p << endl;


	// 4) Utilisation de l'opérateur unaire '*' (syntaxe en préfixe) qui permet d'aller à l'adresse évalué par l'opérande de droite.
	//    note: il est possible de retrouver et consulter une information avec son adresse

	cout << "4) la valeur de v = " << *p << endl; // évalue p qui contient une adresse, puis on accède à cette adresse avec l'opérateur '*'


	// 5) On peut aussi modifier l'information dont on a l'adresse avec le même opérateur '*'
	//    note: l'opérateur '*' peut s'utiliser du côté gauche de l'affectation "="

	*p = 10; // on accède à l'adresse ou p pointe et on lui affecte une nouvelle valeur. La variable v vient donc de changer de valeur.

	*p = *p * *p; // idem que v = v * v;

	cout << "5) la valeur de v = " << v << endl;

	_getch();
}