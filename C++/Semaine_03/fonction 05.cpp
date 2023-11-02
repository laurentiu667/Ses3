#include <iostream>
#include <conio.h>

using namespace std;

struct Fract
{
	int64_t num;
	int64_t div;
};

void show(Fract a)
{
	cout << "(" << a.num << "/" << a.div << ")";
}

void show(Fract a, string op, Fract b, string eq, Fract r)
{
	show(a); cout << op; show(b); cout << eq; show(r); cout << endl;
}

Fract inv(Fract a)														// (n/d)  ==>  (d/n)
{
	return { a.div , a.num };
}

Fract sign(Fract a)														// (n/-d)  ==>  (-n/d)
{
	if (a.div < 0) a = { -a.num, -a.div };
	return a;
}

// algorithme d'Euclide
int64_t pgcd(int64_t m, int64_t n)										// pgcd: plus grand commun diviseur
{
	int64_t r;
	m = abs(m); n = abs(n);
	while (n > 0)
	{
		r = m % n;
		m = n;
		n = r;
	}
	return m;
}

int64_t ppcm(int64_t m, int64_t n)										// ppcm: plus petit commun multiple
{ 
	return (m && n) ? m * n / pgcd(m, n) : 0;
}

Fract red(Fract a)														// réduire la fraction
{
	int64_t d = pgcd(a.num, a.div);
	a.num /= d;
	a.div /= d;
	return sign(a);
}

Fract add(Fract a, Fract b)												// a + b  ==>  (an/ad) + (bn/bd)  ==>  (an*bd + ad*bn) / (ad*bd)
{ 
	Fract r = { (a.num * b.div) + (a.div * b.num) , a.div * b.div };
	return red(r);
}

Fract sub(Fract a, Fract b)												// a - b  ==>  (an/ad) - (bn/bd)  ==>  (an/ad) + (-bn/bd)
{ 
	return add(a, { -b.num, b.div });
}

Fract mul(Fract a, Fract b)												// a x b  ==>  (an/ad) * (bn/bd)  ==>  (an*bn) / (ad*bd)
{ 
	Fract r = { a.num * b.num , a.div * b.div };
	return red(r);
}

Fract div(Fract a, Fract b)												// a / b  ==>  a / (bn/bd)  ==>  a * (bd/bn)
{
	return mul(a, inv(b));
}

int main()
{
	Fract a = {4,5}, b = {1,-5};

	show(a, " + ", b, " = ", add(a, b));
	show(a, " - ", b, " = ", sub(a, b));
	show(a, " * ", b, " = ", mul(a, b));
	show(a, " / ", b, " = ", div(a, b));

	_getch();
}