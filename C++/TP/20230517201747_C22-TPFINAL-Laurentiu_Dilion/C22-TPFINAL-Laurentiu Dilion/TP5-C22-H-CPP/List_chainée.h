#pragma once
#include <string>

struct Item_Club
{
	std::string club;
	int nb_club;
};

struct Item
{
	Item_Club club;
	Item* next;
};

struct Liste
{
	Item* first, * last;
	size_t size;
};
std::string find_club_total(Membre& m);
