#pragma once

#include "01_List.h"

class DoublyLinkedList : public List
{
	struct Node {
		Node* prev;
		Node* next;
		int data;
	};

protected:
	Node* head;

public:

	void add(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		if (head != nullptr) {
			newNode->next = head;
			head->prev = newNode;
		}
		else {
			newNode->next = nullptr;
		}
		newNode->prev = nullptr;
		head = newNode;
	}

	void remove(int data) {
		Node* currentNode = head;
		// If head needs to be removed
		if (currentNode->data == data) {
			head = currentNode->next;
			head->prev = nullptr;
			delete currentNode;
			return;
		}
		currentNode = head->next;
		while (currentNode->next != nullptr) {
			if (currentNode->data == data) {
				currentNode->prev->next = currentNode->next;
				currentNode->next->prev = currentNode->prev;
				delete currentNode;
				return;
			}
		}
		//last node matches
		if (currentNode->data == data) {
			currentNode->prev->next = nullptr;
			delete currentNode;
		}
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

	void print() {
		Node* currentNode = head;
		while (currentNode->next != nullptr) {
			cout << currentNode->data << endl;
			currentNode = currentNode->next;
		}
		cout << currentNode->data << endl;
	}

};

