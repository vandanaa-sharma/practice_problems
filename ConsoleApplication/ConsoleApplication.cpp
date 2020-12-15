// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <regex>
#include <string>
#include "vector.h"

using namespace std;
void printSpecialCharacters(string s);

int main()
{
	// Problem 01 - Print special characters in string
    /*std::cout << "Hello World!\n";
	string s;
	cin >> s;
	printSpecialCharacters(s);*/

	// Problem 02 - Implementation of vector
	project::vector<int> v;
	for (int i = 0; i < 40; i++)
	{
		v.push_back(i);
	}
	
	cout << v[23] << endl;
	return 0;
}


void printSpecialCharacters(string s) {
	for (int i = 0; i < s.size(); i++) {
		int c = (int) s[i];
		if ((c <= 65 && c >= 90) && (c >= 122 && c <= 97)) {
			cout << c << endl;
			cout << s[i] << endl;
		}
	}
}


// Problem 02 - Print special characters in string
