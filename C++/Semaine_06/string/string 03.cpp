#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

/*

LE TYPE STRING ET L'OP�RATEUR []

    - L'op�rateur [] permet d'acc�der aux caract�res de la string comme un tableau

    - Attention:
        - l'indice doit �tre entre [ 0 .. size() - 1 ] 

*/

int main()
{
    // EXEMPLE #1 -- lecture des caract�res d'une string avec l'op�rateur []

    string s;
    char c;

    s = "Bonjour";
    for (int i = 0; i < s.size(); ++i)
    {
        c = s[i];
        cout << c;
    }
    cout << endl;


    // EXEMPLE #2 -- remplacement des caract�res d'une string avec l'op�rateur []

    s = "informatique";
    for (int i = 0; i < s.size(); ++i)
    {
        s[i] = toupper(s[i]);
    }
    cout << s << endl;


    // EXEMPLE #3 -- Attention: acc�s interdit

    s = "01234";

    // s[i] = 'A';  // erreur si:  i >= s.size()  ou  i < 0


	_getch();
}