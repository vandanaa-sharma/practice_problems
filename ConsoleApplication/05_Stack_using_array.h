#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Stack_using_array
{
private:
	int MAX_SIZE = 1;
	int size = -1;
	vector<int> stack;
public:
	Stack_using_array(int maxSize) {
		MAX_SIZE = maxSize;
	}
	void pop() {
		if (size == -1) {
			cout << "Stack is empty, nothing to pop" << endl;
		}
		else {
			size--;
			stack.resize(size+1);
		}
	}

	void push(int data) {
		if (size + 1 == MAX_SIZE) {
			cout << "Stack in full, element not added!" << endl;
			return;
		}
		stack.push_back(data);
		size++;
	}

	void print() {
		for (int i = size - 1; i > -1; i--) {
			cout << stack[i] << endl;
		}
		cout << "----------------" << endl;
	}
};

