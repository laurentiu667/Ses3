#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>

#include <sstream> // pour le type stringstream et ses outils

using namespace std;

/*

LE TYPE STRINGSTREAM ET SES OUTILS

	stringstream est un type de contenant qui permet de g�rer un flux (stream) de caract�res (i.e. une liste de caract�res) dans une m�moire tampon

		a) le flux peut servire pour extraire des caract�res	(� la mani�re d'un cin)

		b) le flux peut servire pour accumuler des caract�res	(� la mani�re d'un cout)

		c) le flux peut servire pour faire (a) et (b) en m�me temps

	Att: le flux de caract�res n'est pas li� au clavier (comme le cin) ou � la fen�tre de la console (comme le cout)

*/


int main()
{
	// EXEMPLE #1 -- d�finition et initialisation d'un stringstream
	{		
		string texte = "ceci est mon texte";
		
		stringstream ss(texte);												// d�fini ss et initialise son tampon de caract�res avec la string texte

		ss.str("");															// r�initialise le tampon de ss avec la chaine vide

		ss << "voici " << 2 << " nombres: " << 10 << " et " << 1.5;			// ajoute successivement les expressions � la fin du tampon de ss

		ss.str(texte);														// r�initialise ss avec texte
	}

	// EXEMPLE #2 -- le stringstream pour faire de l'extraction
	{
		int i;
		double d;

		stringstream ss;

		ss << "  125   10.85  ";

		ss >> i >> d ;

		if (ss.fail())				// v�rifier si l'extraction n'a pas fonctionn�e
		{
			ss.clear();				// remettre le stream ss en �tat de marche
			ss.str("");				// r�initialise le tampon de ss avec la chaine vide
		}
		else
		{
			cout << "i = " << i << endl << "d = " << d << endl << endl;
		}
	}

	// EXEMPLE #3 -- construction d'un texte (string) avec des valeurs num�riques ins�r�es dans celui-ci
	{	
		const double TPS = 0.05, TVQ = 0.09975;
		double montant = 0, total;

		string texte;
		stringstream ss;

		cout << "Montant ($) avant taxe ? : ";
		cin >> montant;

		total = montant * (1 + TPS + TVQ);

		ss << fixed << setprecision(2);
		ss << "Un montant de " << montant << " $ " << "donne " << total << " $" << " avec les taxes !" << endl;
		
		texte = ss.str();		// obtenir le contenu du stream ss sous forme de string et l'affecter � texte;

		cout << endl << texte;
	}

	_getch();
}