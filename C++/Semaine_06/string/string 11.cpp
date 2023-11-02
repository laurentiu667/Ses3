#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

LE TYPE STRING ET SES UTILITAIRES

    rechercher, effacer, remplacer, extraire, c-string

    RAPPEL: la position du premier caract�re d'une string est � l'indice 0

*/

int main()
{
    // EXEMPLE #1 -- Rechercher une sous string dans une string, � partir du d�but avec find() ou de la fin avec rfind()
    {
        size_t f, r, n;             // pour les positions
        string s = "12ab3333ab21";

        f = s.find("ab");	// f = 2    --> trouv� � l'indice 2
        r = s.rfind("ab");	// r = 8    --> trouv� � l'indice 8

        n = s.find("z");	// n = string::npos   --> n'a pas �t� trouv�e --> vaut SIZE_MAX
    

        cout << f << ", " << r << ", " << n << endl; // affiche: "2, 8, SIZE_MAX"

        if (s.find("z") == string::npos)
            cout << "inexistante" << endl << endl;
    }


    // EXEMPLE #2 -- Effacer des caract�res dans une string
    {
        string s = "123reste456";

        s.erase(0, 3);              // effacer 3 caract�res � partir de l'indice 0  --> efface "123" --> s == "reste456"

        s.erase(5, 3);              // effacer 3 caract�res � partir de l'indice 5  --> efface "456" --> s == "reste"

        cout << s << endl << endl;  // affiche: "reste"
    }


    // EXEMPLE #3 -- Remplacer des caract�res par d'autres
    {
        string s = "mot1 mot2 mot3 mot4";

        s.replace(5, 9, "motx");    // remplacer les 9 caract�res � partir de l'indice 5 avec "motx"  --> s == "mot1 motx mot4"

        cout << s << endl << endl;	// affiche: "mot1 motx mot4"
    }


    // EXEMPLE #4 -- Extraire une sous-chaine
    {
        string s = "123sous456chaine", sub1, sub2;

        sub1 = s.substr(3, 4);      // extraire 4  caract�res � partir de l'indice 3  --> sub1 == "sous"
        sub2 = s.substr(10);        // extraire 10 caract�res � partir de l'indice 0  --> sub2 == "chaine"

        cout << s << ", " << sub1 << ", " << sub2 << endl << endl;  // affiche: "123sous456chaine, sous, chaine"
    }


    // EXEMPLE #5 -- Obtenir une c-string (un tableau de char termin� par \0) � partir d'une string
    {
        string s = "1024";

        const char* cs;             // c-string

        cs = s.c_str();             // cs pointe sur une c-string (un tableau de char termin� par \0) non modifiable

        int n = atoi(cs);		    // exemple d'une fonction de conversion manipulant une C string

        cout << n + 1 << endl;	    // affiche: "1025"
    }

	_getch();
}