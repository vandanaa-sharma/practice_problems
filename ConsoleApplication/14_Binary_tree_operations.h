#pragma once

#include<stack>
#include <queue>
#include <iostream>

using namespace std;



class BinaryTree_Operations {
private:
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	Node* root = nullptr; 

	Node* newNode(int data) {
		Node* newNode = new Node();
		newNode->data = data;
		newNode->left = nullptr;
		newNode->right = nullptr;
	}

public:
	//1. Create a balanced Binary Tree
	//2. Insertion - Binary search Tree
	//3. Print nodes at one level
	//4. Spiral Traversal - binary tree

	Node* insertInBST(Node* currentRoot, int data) {
		if (currentRoot == nullptr) {
			return newNode(data);
		}
		else {
			if (data < currentRoot->data) {
				currentRoot = insertInBST(currentRoot->left, data);
			}
			if (data > currentRoot->data) {
				currentRoot = insertInBST(currentRoot->right, data);
			}
			return currentRoot;
		}
	}

	void insertInBalancedTree(int data) {

	}

	void spiralTraversal() {
		if (root != nullptr) {
			stack<Node*> s1;
			stack<Node*> s2;
			s1.push(root);
			while (!s1.empty() || !s2.empty()) {
				while (!s1.empty()) {
					Node* n = s1.top();
					cout << n->data << " ";
					if(n->left != nullptr)
						s2.push(n->right);
					if(n->right != nullptr)
						s2.push(n->left);
					s1.pop();
				}
				while (!s2.empty()) {
					Node* n = s2.top();
					cout << n->data << " ";
					if (n->left != nullptr)
						s1.push(n->left);
					if (n->right != nullptr)
						s1.push(n->right);
					s2.pop();
				}
			}
		}
	}

	void levelOrderTraversal() {
		queue<Node*> q;
		if (root != nullptr) {
			q.push(root);
			q.push(nullptr);
			while (!q.empty()) {
				if (q.front() == nullptr) {
					cout << endl;
					q.pop();
				}
				else { q.push(nullptr); }
				
				Node* n = q.front();
				cout << n->data << endl;

				if (n->left != nullptr) {
					q.push(n->left);
				}
				if (n->right != nullptr) {
					q.push(n->right);
				}

				q.pop();
				
			}
		}
	}

	void findLowestCommonAncestor() {

	}


};