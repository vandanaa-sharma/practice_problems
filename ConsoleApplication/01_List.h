#pragma once

#include <iostream>
using namespace std;

class List
{
public:
	virtual void add(int data) = 0;
	virtual void remove(int data) = 0;
	virtual bool find(int data) = 0;
	virtual void print() = 0;
};

