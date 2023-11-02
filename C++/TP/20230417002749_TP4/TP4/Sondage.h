#pragma once
#include <string>
using namespace std;

const size_t REPONDANTS_MAX = 500; // nombre maximun de r�pondants du sondage
extern size_t nb_repondants;

struct Protection
{
	int  r2[REPONDANTS_MAX];
	char r3[REPONDANTS_MAX];
	char r4[REPONDANTS_MAX];
	char r5[REPONDANTS_MAX];
	char r6[REPONDANTS_MAX];
};

struct Infection
{
	bool r7;
	int	r8, r9, r10;
};

struct Repondant
{
	string ville;
	int age;
	int scolarite;
};

size_t lireLesDonn�esDuSondage(bool r1[], Protection* pro, Infection inf[], Repondant rep[]);

extern string name;