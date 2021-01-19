#pragma once

#include <vector>
using namespace std;

class MinHeap {
private:
	vector<int> heap;

	void swap(int one, int two) {
		int temp = heap[one];
		heap[one] = heap[two];
		heap[two] = temp;
	}

public:
	MinHeap() {};
	virtual ~MinHeap() {};

	void insert(int data) {
		heap.push_back(data);
		int size = heap.size();
		if (heap.size() > 1) {
			heapifyUp(size-1);
		}
	}

	void heapifyUp(int node) {
		int parent = getParent(node);
		if (parent >= 0) {
			if (heap[parent] > heap[node]) {
				swap(node, parent);
				heapifyUp(parent);
			}
		}
	}

	void heapifyDown(int node) {
		if (heap.size() > 1) {
			if (node >= 0 && node < heap.size()) {
				int left = getLeftChildIndex(node);
				int right = getRightChildIndex(node);
				int smallest = node;
				if (left < heap.size() && heap[node] > heap[left])
				{
					smallest = left;
				}
				if (right < heap.size() && heap[smallest] > heap[right]) {
					smallest = right;
				}

				if (smallest != node) {
					swap(node, smallest);
					heapifyDown(smallest);
				}
			}
		}
	}
	
	int getLeftChildIndex(int parent) {
		int index = 2 * parent + 1;
		if (index >= heap.size())
			return -1;
		return index;
	}

	int getRightChildIndex(int parent) {
		int index = 2 * parent + 2;
		if (index >= heap.size())
			return -1;
		return index;
	}

	int getParent(int child) {
		int index = (child - 1)/2;
		if (index < 0)
			return -1;
		return index;
	}

	void removeMinimum() {

		// replace first element with last 
		// pop last element
		// heapify it down

		if (heap.size() && heap.size() == 1) {
			heap.pop_back();
			return;
		}

		else if (heap.size() > 1) {
			swap(heap.size() - 1, 0);
			heap.pop_back();
			heapifyDown(0);
		}

	}

	int getMinimumValue() {
		if (heap.size() > 0) {
			return heap[0];
		}
		return -1;
	}

	void printHeap() {
		for (int i : heap) {
			cout << i << " ";
		}
		cout << endl;
	}

	int nodesSmallerThanGivenValue(int data) {
		int count = 0;
		return count;
	}
};
