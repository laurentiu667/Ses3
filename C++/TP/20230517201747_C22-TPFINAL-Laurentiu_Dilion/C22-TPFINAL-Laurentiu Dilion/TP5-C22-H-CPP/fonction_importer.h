#pragma once
#include <sstream>
#include <string>
#include "db.h"
using namespace std;

//void clean(string& v);
void read_val(stringstream& ss, char v[NOMBRE_CHAR_MAX]);
void read_val(stringstream& ss, int& v);
void read_val(stringstream& ss, double& v);
void read_key(stringstream& ss, string& k);
bool read_kv(string& line, Membre& m);
void read_rec(fstream& f, Membre* m);
void load_db(fstream& f, Membre* m);
void load_db(const string& name, Membre* m);
void save_db(const string& fname, const Membre* m);