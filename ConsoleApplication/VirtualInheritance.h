#pragma once
#pragma once

#include <iostream>
using namespace std;

class A
{
public:
	A() {};
	void printA() {
		cout << "A :: printA()" << endl;
	}
	virtual ~A() {};
};

class B : public virtual A {
public:
	B() {};
	virtual ~B() {};
};

class C : public virtual A {
public:
	C() {};
	virtual ~C() {};
};

class D : public B, public C {
public:
	D() {};
	virtual ~D() {};
};