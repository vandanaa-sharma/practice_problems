#pragma once

#include "01_List.h"
#include <iostream>

using namespace std;

class CircularLinkedList : public List
{
private:
	struct Node {
		Node* next;
		int data;
	};
	Node* head = nullptr;
public:

	void add(int data) {
		if (head == nullptr) {
			head = new Node();
			head->data = data;
			head->next = head;
		}
		else {
			Node* temp = head;
			while (temp->next != head) {
				temp = temp->next;
			}
			Node* newNode = new Node();
			newNode->data = data;
			newNode->next = head;
			temp->next = newNode;
		}
	}

	void remove(int data) {
		Node* currentNode = nullptr;
		// If head needs to be removed
		if (head->data == data) {
			currentNode = head->next;
			Node* tempNode = head;
			while (tempNode->next != head) {
				tempNode = tempNode->next;
			}
			tempNode->next = currentNode;
			delete head;
			head = currentNode;
			return;
		}
		Node* prevNode = head;
		currentNode = head->next;
		while (currentNode->next != head) {
			if (currentNode->data == data) {
				prevNode->next = currentNode->next;
				delete currentNode;
				return;
			}
			prevNode = currentNode;
			currentNode = currentNode->next;
		}
		//last node matches
		if (currentNode->data == data) {
			prevNode->next = head;
			delete currentNode;
		}
	}

	bool find(int data) {
		Node* currentNode = head;
		if (head->data == data) {
			return true;
		}
		while (currentNode->next != head) {
			if (currentNode->data == data) {
				return true;
			}
			currentNode = currentNode->next;
		}
		return false;
	}

	void print() {
		Node* tempNode = head;
		while (tempNode->next != head) {
			cout << tempNode->data << " ";
			tempNode = tempNode->next;
		}
		cout << tempNode->data << endl;
	}

};

