#pragma once

struct rectangle
{
	size_t haut, larg;
};

size_t aire(rectangle r);

bool est_un_carr�(rectangle r);

void show(rectangle r, char c);