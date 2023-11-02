#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;


/*
 LES ADRESSES EN M�MOIRE

 1) Chaque information conserv�e en m�moire poss�de une adresse qui est consultable.

 2) Les adresses sont cons�cutives en m�moire, octet par octet.

 3) L'adresse d'une information en m�moire est l'adresse du premier octet utilis� par cette information.

 4) Le nombre d'octets utilis�s par une information est d�termin� par son type { ex: double: sizeof(double) =  8 octets }

 5) Lors de la r�servation d'un bloc d'octets en m�moire (ex: cr�ation d'une variable) c'est le syst�me d'exploitation qui d�cidera de l'emplacement et donc de l'adresse de ce bloc.

 6) Il est possible, et c'est une particularit� importante du langage, de cr�er des variables sp�ciales (on dit aussi des pointeurs) pour conserver l'adresse d'une information
    qui se trouve quelque part en m�moire. Avec l'adresse, il est d�sormais possible de se rendre � ce lieu et consulter ou modifier l'information.
 */

int main()
{
	int v = 25;

	// 1) Utilisation de l'op�rateur unaire '&' (syntaxe en pr�fixe) qui permet d'obtenir l'adresse de l'expression � droite.
	//    note: l'adresse est un entier positif exprim� en hexa ( de 32 bits, si compil� en x86, ou de 64 bits, si compil� en x64 )
	
	cout << "1) l'adresse de v = " << &v << endl;


	// 2) Cr�ation d'une variable p de type (int *). On dit aussi de type adresse d'un int, ou pointeur vers un int.
	//    note: p est une variable pour conserver l'adresse d'un int qui sera quelque part en m�moire.
	
	int * p;

	p = &v; // mettre l'adresse de v dans p

	cout << "2) l'adresse de v = " << p << endl;


	// 3) p a aussi une adresse

	cout << "3) l'adresse de p = " << &p << endl;


	// 4) Utilisation de l'op�rateur unaire '*' (syntaxe en pr�fixe) qui permet d'aller � l'adresse �valu� par l'op�rande de droite.
	//    note: il est possible de retrouver et consulter une information avec son adresse

	cout << "4) la valeur de v = " << *p << endl; // �value p qui contient une adresse, puis on acc�de � cette adresse avec l'op�rateur '*'


	// 5) On peut aussi modifier l'information dont on a l'adresse avec le m�me op�rateur '*'
	//    note: l'op�rateur '*' peut s'utiliser du c�t� gauche de l'affectation "="

	*p = 10; // on acc�de � l'adresse ou p pointe et on lui affecte une nouvelle valeur. La variable v vient donc de changer de valeur.

	*p = *p * *p; // idem que v = v * v;

	cout << "5) la valeur de v = " << v << endl;

	_getch();
}