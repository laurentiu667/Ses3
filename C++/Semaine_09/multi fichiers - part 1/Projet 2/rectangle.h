#pragma once

struct rectangle
{
	size_t haut, larg;
};

size_t aire(rectangle r);

bool est_un_carré(rectangle r);

void show(rectangle r, char c);