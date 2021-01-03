#pragma once

#include <iostream>
#include "01_List.h"

using namespace std;

class LinkedList : public List
{
	struct Node {
		Node* next;
		int data;
	};

protected:
	Node* head;

public:

	void add(int data) {
		if (head == nullptr) {
			head = new Node();
			head->data = data;
			head->next = nullptr;
			return;
		}
		Node* currentNode = head;
		while (currentNode->next != nullptr) {
			currentNode = currentNode->next;
		}
		Node* newNode = new Node();
		newNode->data = data;
		newNode->next = nullptr;
		currentNode->next = newNode;
	}

	bool find(int data) {
		Node* currentNode = head;
		while (currentNode->next != nullptr) {
			if (currentNode->data == data) {
				return true;
			}
			currentNode = currentNode->next;
		}
		return false;
	}

	void remove(int data) {
		Node* currentNode = head;
		// If head needs to be removed
		if (currentNode->data == data) {
			head = currentNode->next;
			delete currentNode;
			return;
		}
		Node* prevNode = head;
		currentNode = head->next;
		while (currentNode->next != nullptr) {
			if (currentNode->data == data) {
				prevNode->next = currentNode->next;
				delete currentNode;
				return;
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		//last node matches
		if (currentNode != nullptr && currentNode->data == data) {
			prevNode->next = nullptr;
			delete currentNode;
		}
	}

	void print() {
		Node* currentNode = head;
		while (currentNode->next != nullptr) {
			cout << currentNode->data << " ";
			currentNode = currentNode->next;
		}
		cout << currentNode->data << endl;
	}

	void removeEnd() {
		Node* currentNode = head;
		Node* prevNode = nullptr;
		while (currentNode->next != nullptr) {
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		if (prevNode != nullptr) {
			prevNode->next = nullptr;
		}
		delete currentNode;
	}

	void removeFront() {
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	int getLength() {
		Node* currentNode = head;
		int length = 1;
		if (currentNode->next == nullptr)
		{
			return length;
		}
		while (currentNode->next != nullptr) {
			length++;
			currentNode = currentNode->next;
		}
		return length;
	}

	void exchangeNode(int k) {
		int listSize = getLength();
		Node* currentNode = head;
		Node* prevNode = nullptr;
		if (k == 1) {
			// exchange first node with last
			while (currentNode->next != nullptr) {
				prevNode = currentNode;
				currentNode = currentNode->next;
			}
			currentNode->next = head->next;
			prevNode->next = head;
			head->next = nullptr;
			head = currentNode;
		}
		else {
			//find middle index
			int middleIndex;
			if (k >= listSize / 2) {
				cout << "Invalid index" << endl;
				return;
			}
			Node* ex1 = nullptr, *px1 = nullptr;
			Node* ex2 = nullptr, *px2 = nullptr;
			int count = 1;
			while (currentNode->next != nullptr) {
				count++;
				prevNode = currentNode;
				currentNode = currentNode->next;
				if (count == k ) {
					ex1 = currentNode;
					px1 = prevNode;
				}
				else if (count == (listSize+1 - k)) {
					ex2 = currentNode;
					px2 = prevNode;
					break;
				}
			}
			Node* temp = ex2->next;
			ex2->next = ex1->next;
			ex1->next = temp;
			px1->next = ex2;
			px2->next = ex1;
		}
		print();
	}
};

