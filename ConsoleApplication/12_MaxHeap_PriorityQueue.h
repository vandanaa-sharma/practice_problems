#pragma once

#include <vector>
using namespace std;

class MH_PriorityQueue {
private:
	vector<int> maxHeap;

	void swap(int first, int second) {
		int temp = maxHeap[first];
		maxHeap[first] = maxHeap[second];
		maxHeap[second] = temp;
	}

public:
	void enqueue(int data) {
		maxHeap.push_back(data);
		int size = maxHeap.size();
		if (size > 1) {
			heapifyUp(size - 1);
		}
	}

	void heapifyDown(int node) {
		int size = maxHeap.size();
		if (size > 1 && node < size) {
			int left = getLeftChild(node);
			int right = getRightChild(node);

			int greatest = node;

			if (left >= 0 && left < size && maxHeap[left] > maxHeap[greatest])
				greatest = left;

			if (right >= 0 && right < size && maxHeap[right] > maxHeap[greatest])
				greatest = right;

			if (greatest != node) {
				swap(greatest, node);
				heapifyDown(greatest);
			}
		}
	}

	void heapifyUp(int node) {
		int parent = getParent(node);
		if (parent >= 0) {
			if (maxHeap[node] > maxHeap[parent]) {
				swap(node, parent);
				heapifyUp(parent);
			}
		}
	}

	void dequeue() {
		int size = maxHeap.size();
		if (size == 1) {
			maxHeap.pop_back();
			return;
		}
		else if (size > 1) {
			swap(size - 1, 0);
			maxHeap.pop_back();
			heapifyDown(0);
		}
	}

	int getParent(int node) {
		int parent = (node - 1) / 2;
		return parent >= 0 ? parent : -1;
	}

	int getLeftChild(int node) {
		int child = (2*node + 1);
		return child < maxHeap.size() ? child : -1;
	}

	int getRightChild(int node) {
		int child = (2 * node + 2);
		return child < maxHeap.size() ? child : -1;
	}

	void printQueue() {
		for (int i : maxHeap) {
			cout << i << " ";
		}
		cout << endl;
	}
};