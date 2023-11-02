#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>

using namespace std;


bool palindrome_i(string& s)
{
	for (size_t i = 0, size = s.size(); i < size/2; ++i)
		if (s[i] != s[size-1-i])
			return false;
	return true;
}


bool palindrome_r(string &s, size_t from, size_t to)
{
	if (from >= to)
		return true;
	else
		return s[from] == s[to] && palindrome_r(s, from+1, to-1);
}

bool palindrome_r(string& s)
{
	return palindrome_r(s, 0, s.size() ? s.size()-1 : 0);
}


int main ()
{
	string s = "1234321";

	cout << (palindrome_i(s) ? "TRUE" : "FALSE") << endl;
	cout << (palindrome_r(s) ? "TRUE" : "FALSE");

	_getch();
}