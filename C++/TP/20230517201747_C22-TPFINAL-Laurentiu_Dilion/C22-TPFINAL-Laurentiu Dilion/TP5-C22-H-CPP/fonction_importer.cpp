#include "fonction_importer.h"
#include <fstream>
#include <iostream>
#include "db.h"
#include "cvm 21.h"
#include <conio.h>

void clean(string& v)
{
    string w;
    stringstream ss(v);
    ss >> (v = {});
    while (ss >> w) v += " " + w;
}
void read_val(stringstream& ss, char v[NOMBRE_CHAR_MAX])
{
    ss.ignore(1);
    ss.getline(v, NOMBRE_CHAR_MAX);
}
void read_val(stringstream& ss, int& v)
{
    ss >> v;
}

void read_key(stringstream& ss, string& k)
{
    getline(ss, k, '=');
    clean(k);
}
bool read_kv(string& line, Membre& m)
{
    string key;
    stringstream ss(line);

    read_key(ss, key);

    if (key == ";") return true;

    else if (key == "PRENOM")
        read_val(ss, m.prenom);
    else if (key == "NOM")
        read_val(ss, m.nom);
    else if (key == "VILLE")
        read_val(ss, m.ville);
    else if (key == "AGE")
        read_val(ss, m.age);
    else if (key == "CLUB")
        read_val(ss, m.clubs[m.nb_clubs++].nom_Club);

    return false;
}
void read_rec(fstream& f)
{
    string line;
    Membre m = {};
    bool eorf = false;
    do
    {
        getline(f, line);
        eorf = read_kv(line, m);
    } while (!f.fail() && !eorf);

    if (eorf)
    {
        db_write(db_size() + 1, &m);
    }
}
void load_db(fstream& f, Membre* m)
{
    int numero = 1;
    while (!f.fail() && !f.eof())
    {
        read_rec(f);
    }
}
void load_db(const string& name, Membre* m)
{
    fstream f(name, ios::in);
    if (f.is_open())
    {
        load_db(f, m);
        f.close();
        gotoxy(4, 26);
        setcolor(Color::_yel);
        cout << '"' << name << '"' << " --> importation réussie ... ";
        setcolor(Color::wht);
        _getch();
    }
}