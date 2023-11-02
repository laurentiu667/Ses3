#pragma once
#include <string>
#include <sstream>
#include "db.h"
using namespace std;

// A J O U T E R 
void cmd_ajouter();

// A F F I C H E R

void cmd_afficher();
void afficher_clubs(size_t no, Membre& m, string phrase, bool modif_true);
void afficher(size_t no, string phrase, Membre& m, bool trueORfalse);

// A J O U T E R  || R E T I R E R 

void ajouter_club(size_t no, Membre& m, char c, int newX, int newY);
void retirer_club(size_t no, Membre& m, char c);
void cmd_modifier();

// S T A T S

void afficher_stats();
void cmd_stats();

// L I S T 

void afficher_list();
void cmd_list();

// E X P O R T E R

void _write(fstream& file, Membre& m);
void save(string fname, bool erase, Membre& m);
void cmd_xport();

// I M P O R T E R 

void cmd_import();

// E F F A C E R  -- CLUB OU MEMBRE

void cmd_effacer();

// Q U I T T E R

void cmd_quitter(void);