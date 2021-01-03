#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Queue_using_array
{
private:
	int size=-1;
	int MAX_SIZE = 1;
	vector<int> queue;

public:
	Queue_using_array(int maxSize) {
		MAX_SIZE = maxSize;
	}

	void enqueue(int data) {
		if (size + 1 == MAX_SIZE) {
			cout << "Queue reached maximum size, element not enqueued" << endl;
		}
		else {
			queue.push_back(data);
			size++;
		}
	}

	void dequeue() {
		if (!queue.size()) {
			cout << "Queue empty, nothing to dequeue" << endl;
		}
		else {
			size--;
			for (int i = 0; i+1 < queue.size(); i++) {
				queue[i] = queue[i + 1];
			}
			queue.resize(size + 1);
		}
	}

	void display() {
		for (const auto& i : queue) {
			cout << i << " ";
		}
		cout << endl << "--------------------------" << endl;
	}

};

