#include <iostream>
#include <conio.h>

using namespace std;

/*
	 ALLOCATION DYNAMIQUE

	 1) Il existe deux opérateurs (unaires et préfixe) pour créer et detruire un bloc d'octets en mémoire: "new" et "delete"

	 2) L'opérateur "new" permet de réserver un bloc d'octets et sa taille est déterminée par le type spécifié par son opérande de droite

	 3) L'opérateur "new" retourne l'adresse du premier octet si l'opération a réussie. Cette adressse doit être conservée précieusement.

	 4) L'opérateur "delete" effectue, à l'aide d'une adresse, l'opération inverse qui consiste à retourner au recyclage un bloc d'octets
 */

struct Fract
{
	int num;
	int div;
};

int main()
{
	// 1) définition d'un pointeur vers un double et initilisé à l'adresse NULL (ou zéro). On dit aussi que c'est un pointeur nul.
	//    note: L'adresse 0 (ou NULL, ou nullprt) est une adresse réservée qui signifie: aucune adresse.

	double* p;		// l'adresse contenue dans p est indéterminée ici

	p = nullptr;	// depuis C++ 11	--> usage recommandé
	p = NULL;		// depuis C:		--> idem mais utiliser plutôt nullptr
	p = 0;			// entier 0:		--> idem mais non recommandé

	if (p == nullptr)
	{
		// (*p)		// interdit --> violation d'accès en lecture
	}


	// 2) allocation en mémoire d'un double (sans nom), à l'aide de l'opérateur "new" et sauvegarde de l'adresse retournée
	// dans le pointeur p.

	p = new double;		// allocation d'un double et copie de son adresse dans p

	*p = 100.25;		// l'accès à ce contenant ne peut se faire qu'avec l'adresse
	*p += 45.50;
	*p = *p * 3;

	cout << "2) L'adresse du nouveau double = " << p << "  et sa valeur = " << *p << endl;


	// 3) destruction (ou recyclage) du double avec l'opérateur delete (important de le faire lorsque le double n'est plus utile)

	// notes: 1) une fois l'opération delete terminée l'adresse du double contenu dans p devient invalide.
	//		  2) une tentative d'accès à cette adresse avec l'opérateur '*' est une erreur de logique et
	//           pourrait provoquer une erreur grave à l'exécution (violation d'accès!!!)

	delete p;			// recyclage du double pointé par p (note: p contient toujours l'adresse)
	
    // *p = 88.45;		// interdit car l'adresse dans p est maintenant invalide

	p = nullptr;		// remettre p à l'adresse nulle (facultatif mais recommandé)


	// 4) réutilisation du pointeur p pour mémoriser l'adresse d'un autre double

	p = new double {200.45};	// et initilisé avec une valeur
	*p -= 100;
	cout << "4) L'adresse du nouveau double = " << p << "  et sa valeur = " << *p << endl;
	delete p;


	// 5) il est important de ne pas perdre une adresse, car sans l'adresse il est impossible:
	//    1) de retrouver l'information
	//    2) d'éventuellement la détruire. On parle ici d'une fuite (leak) mémoire qui se résorbera qu'à la fin du programme.

	p = new double;		// p contient l'adresse
	p = new double;		// p contient une nouvelle adresse, le double précèdant est perdu puisqu'on n'a plus son adresse.
	p = nullptr;		// le deuxième double vient de subir le même sort.


	// 6) Allocation dynamique d'une structure

	Fract* f = new Fract {1,2};	// allocation d'un contenant Fract et initialisation

	*f = {1,4};
	f->div = 5;

	cout <<  "6) " << f->num << "/" << f->div << " = " << double(f->num) / f->div << endl; // convertir en double pour provoquer la dividion sur les doubles
	
	delete f;
	
	_getch();
}