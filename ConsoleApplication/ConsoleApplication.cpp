// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <regex>
#include <string>
#include "vector.h"

using namespace std;
void printSpecialCharacters(string s);

// Problem 04 - template function 
template <class T>
T GetMax(const T &a, const T &b) {
	T result = a < b ? b : a;
	return result;
}


// Problem 03 - Mutable vs const
class TestMutable {
private:
	int i = 0;
	mutable int j = 1;
public:
	void modifyVariables() const
	{
		// i++;               // Compile error because function is const
		j++;
		cout << "Const vs Mutable " << i << " " << j << endl;
	}
};


int main()
{
	// Problem 01 - Print special characters in string
	/*
	string s;
	cin >> s;
	printSpecialCharacters(s);
	*/

	/* -----------------------------------------------------------------------*/

	// Problem 02 - Implementation of vector
	project::vector<int> v;
	for (int i = 0; i < 40; i++)
	{
		v.push_back(i);
	}
	cout << v[23] << endl;

	/* -----------------------------------------------------------------------*/

	// Problem 04 - template function
	cout << GetMax(7, 9) << endl;

	/* -----------------------------------------------------------------------*/

	// Problem 05 - const pointer
	const int* i;
	//*i = 10;              // compile error
	int* const p = new int;
	int j = 9;
	//p = &j;                 // compile error - const after * --> pointer is constant

	/* -----------------------------------------------------------------------*/

	// Problem 06 - Smart Pointer



	/* -----------------------------------------------------------------------*/

	// Problem 07


	/* -----------------------------------------------------------------------*/

	// Problem 08


	/* -----------------------------------------------------------------------*/

	// Problem 09



	/* -----------------------------------------------------------------------*/

	// Problem 10



	/* -----------------------------------------------------------------------*/

	// Problem 11





	/* -----------------------------------------------------------------------*/

	// Problem 12



	/* -----------------------------------------------------------------------*/

	// Problem 13


	/* -----------------------------------------------------------------------*/

	// Problem 14



	/* -----------------------------------------------------------------------*/
	// Problem 15




	/* -----------------------------------------------------------------------*/

	return 0;
}

// Problem 01 - Print special characters in string
void printSpecialCharacters(string s) {
	for (int i = 0; i < s.size(); i++) {
		int c = (int)s[i];
		if ((c <= 65 && c >= 90) && (c >= 122 && c <= 97)) {
			cout << c << endl;
			cout << s[i] << endl;
		}
	}
}



