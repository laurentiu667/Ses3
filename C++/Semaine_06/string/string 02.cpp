#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

LA CONCAT�NATION DE STRING

    - L'op�rateur '+' permet de concat�ner (on dit aussi juxtaposer) une string � une autre. L'op�rande de gauche
      doit absolument �tre de type string.

    - Attention:
        - "une chaine" n'est pas une string en C++
        - Comme nous le verrons plus tard, il s'agit d'un tableau de char (ou quelque fois appel� c-string)

*/

int main()
{
    // EXEMPLE #1 -- op�rateur +
    string s;

    s = "La";
    s = s + " " + "concat\x82nation";
    s = s + ' ' + "!!!";

    cout << s << endl;	// affiche --> "La concat�nation !!!"


    // EXEMPLE #2 -- 
    char c;

    cout << "input:  ";

    s = "";
    for (int i = 1; i <= 4; ++i)
    {
        c = _getch();
        cout << c;
        s = s + c;
    }
    cout << endl << "output: " << s << endl;


    // EXEMPLE #3 -- Attention
    s = "";
    s = s + "ying" + "yang";	// ok
	
	// s = "ying" + "yang"  	// erreur ne fonctionne pas car l'op�rande de gauche de '+' ==> "ying" n'est pas une string 

	_getch();
}