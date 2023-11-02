#include <iostream>
#include <conio.h>

#include "module_a.h"
#include "module_b.h"

using namespace std;


int main()
{
	
	// 1) Utilisation du module_a

	cout << endl;
	cout << "PI"	<< TAB << "= " << PI	<< endl;
	cout << endl;
	cout << "Cegep"	<< TAB << "= " << CEGEP	<< endl;
	cout << endl;

	for (int i = 0; i < 10; ++i) doSomething(); 
	cout << endl;


	// 2) Utilisation du module_b

	Type var = { "data" , "data" };

	doSomething(var);
	   	  
	_getch();
}