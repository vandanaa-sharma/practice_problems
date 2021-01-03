#pragma once

#include "02_LinkedList.h"

class Stack_using_linkedlist
{
private:
	LinkedList list = LinkedList();
	int size= -1;
	int MAX_SIZE = 1;

public:
	Stack_using_linkedlist(int maxSize) {
		MAX_SIZE = maxSize;
	}

	void pop() {
		if (size == -1) {
			cout << "Stack is empty, nothing to pop" << endl;
		}
		list.removeEnd();
		size--;
	}

	void push(int data) {
		if (size + 1 == MAX_SIZE) {
			cout << "Stack in full, element not added!" << endl;
			return;
		}
		list.add(data);
		size++;
	}

	void print() {
		list.print();
		cout << "----------------" << endl;
	}
};

