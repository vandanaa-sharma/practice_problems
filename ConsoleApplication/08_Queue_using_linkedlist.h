#include <iostream>
#include "02_LinkedList.h"
using namespace std;

#pragma once
class Queue_using_linkedlist
{
private:
	LinkedList list = LinkedList();
	int size = -1;
	int MAX_SIZE = 1;
public:
	Queue_using_linkedlist(int maxSize) {
		MAX_SIZE = maxSize;
	}

	void enqueue(int data) {
		if (size + 1 == MAX_SIZE) {
			cout << "Queue is full, element not enqueued" << endl;
		}
		else {
			list.add(data);
			size++;
		}
	}

	void dequeue() {
		if (size == -1) {
			cout << "List is empty, nothing to dequeue" << endl;
		}
		else {
			list.removeFront();
			size--;
		}
	}

	void display() {
		list.print();
		cout << endl << "--------------------------" << endl;
	}
};

