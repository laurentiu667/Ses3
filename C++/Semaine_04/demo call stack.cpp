#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>

using namespace std;


enum class Speed { rapide = 500, lent = 1000 };


void ouvrier(int job, Speed speed)
{
	Sleep(int(speed));									// pour simuler le travail à faire

	cout << "job: " << setw(6) << job << " done " << endl;
}


void directeur_A(int job)
{
	Speed speed = rand() % 2 ? Speed::rapide : Speed::lent;		// vitesse pour faire le travail

	ouvrier(job, speed);
}

void directeur_B(int job)
{
	Speed speed = rand() % 2 ? Speed::rapide : Speed::lent;		// vitesse pour faire le travail

	ouvrier(job, speed);
}


int main()
{
	int job, cnt = 0;

	while(true)
	{
		++cnt;						// compteur
		job = rand();				// choix  du travail à faire

		if (rand() % 2)				// choix au hasard du directeur pour faire le travail  
			directeur_A(job);
		else
			directeur_B(job);
	}
	_getch();
}