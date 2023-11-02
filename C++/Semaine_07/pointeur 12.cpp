#include <iostream>
#include <conio.h>

using namespace std;

/*
	 ALLOCATION DYNAMIQUE

	 1) Il existe deux op�rateurs (unaires et pr�fixe) pour cr�er et detruire un bloc d'octets en m�moire: "new" et "delete"

	 2) L'op�rateur "new" permet de r�server un bloc d'octets et sa taille est d�termin�e par le type sp�cifi� par son op�rande de droite

	 3) L'op�rateur "new" retourne l'adresse du premier octet si l'op�ration a r�ussie. Cette adressse doit �tre conserv�e pr�cieusement.

	 4) L'op�rateur "delete" effectue, � l'aide d'une adresse, l'op�ration inverse qui consiste � retourner au recyclage un bloc d'octets
 */

struct Fract
{
	int num;
	int div;
};

int main()
{
	// 1) d�finition d'un pointeur vers un double et initilis� � l'adresse NULL (ou z�ro). On dit aussi que c'est un pointeur nul.
	//    note: L'adresse 0 (ou NULL, ou nullprt) est une adresse r�serv�e qui signifie: aucune adresse.

	double* p;		// l'adresse contenue dans p est ind�termin�e ici

	p = nullptr;	// depuis C++ 11	--> usage recommand�
	p = NULL;		// depuis C:		--> idem mais utiliser plut�t nullptr
	p = 0;			// entier 0:		--> idem mais non recommand�

	if (p == nullptr)
	{
		// (*p)		// interdit --> violation d'acc�s en lecture
	}


	// 2) allocation en m�moire d'un double (sans nom), � l'aide de l'op�rateur "new" et sauvegarde de l'adresse retourn�e
	// dans le pointeur p.

	p = new double;		// allocation d'un double et copie de son adresse dans p

	*p = 100.25;		// l'acc�s � ce contenant ne peut se faire qu'avec l'adresse
	*p += 45.50;
	*p = *p * 3;

	cout << "2) L'adresse du nouveau double = " << p << "  et sa valeur = " << *p << endl;


	// 3) destruction (ou recyclage) du double avec l'op�rateur delete (important de le faire lorsque le double n'est plus utile)

	// notes: 1) une fois l'op�ration delete termin�e l'adresse du double contenu dans p devient invalide.
	//		  2) une tentative d'acc�s � cette adresse avec l'op�rateur '*' est une erreur de logique et
	//           pourrait provoquer une erreur grave � l'ex�cution (violation d'acc�s!!!)

	delete p;			// recyclage du double point� par p (note: p contient toujours l'adresse)
	
    // *p = 88.45;		// interdit car l'adresse dans p est maintenant invalide

	p = nullptr;		// remettre p � l'adresse nulle (facultatif mais recommand�)


	// 4) r�utilisation du pointeur p pour m�moriser l'adresse d'un autre double

	p = new double {200.45};	// et initilis� avec une valeur
	*p -= 100;
	cout << "4) L'adresse du nouveau double = " << p << "  et sa valeur = " << *p << endl;
	delete p;


	// 5) il est important de ne pas perdre une adresse, car sans l'adresse il est impossible:
	//    1) de retrouver l'information
	//    2) d'�ventuellement la d�truire. On parle ici d'une fuite (leak) m�moire qui se r�sorbera qu'� la fin du programme.

	p = new double;		// p contient l'adresse
	p = new double;		// p contient une nouvelle adresse, le double pr�c�dant est perdu puisqu'on n'a plus son adresse.
	p = nullptr;		// le deuxi�me double vient de subir le m�me sort.


	// 6) Allocation dynamique d'une structure

	Fract* f = new Fract {1,2};	// allocation d'un contenant Fract et initialisation

	*f = {1,4};
	f->div = 5;

	cout <<  "6) " << f->num << "/" << f->div << " = " << double(f->num) / f->div << endl; // convertir en double pour provoquer la dividion sur les doubles
	
	delete f;
	
	_getch();
}