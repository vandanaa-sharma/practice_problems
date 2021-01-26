#pragma once
#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>

using namespace std;

class BinarySearchTree
{
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	Node* root = nullptr;


public:

	BinarySearchTree() {

	}

	void add(int data) {

	}

	void printPreOrder() {
		preOrder(root);
	}

	void printPostOrder() {
		postOrder(root);
	}

	void printInOrder() {
		inOrder(root);
	}

	void printPretty() {
		printBT(root);
	}

	int getHeight() {
		int h = 0;
		return h;
	}

	void printLevels() {

	}

private:
	void preOrder(Node* root) {
		if (root != nullptr) {
			cout << root->data << endl;
			preOrder(root->left);
			preOrder(root->right);
		}
	}

	void postOrder(Node* root) {
		if (root != nullptr) {
			postOrder(root->left);
			postOrder(root->right);
			cout << root->data << endl;
		}
	}

	void inOrder(Node* root) {
		if (root != nullptr) {
			inOrder(root->left);
			cout << root->data << endl;
			inOrder(root->right);
		}
	}


	/* Copied utility funcitons */
	void printBT(const std::string& prefix, const Node* node, bool isLeft)
	{
		if (node != nullptr)
		{
			std::cout << prefix;

			std::cout << (isLeft ? "|---" : "|---");

			// print the value of the node
			std::cout << node->data << std::endl;

			// enter the next tree level - left and right branch
			printBT(prefix + (isLeft ? "|    " : "    "), node->left, true);
			printBT(prefix + (isLeft ? "|    " : "    "), node->right, false);
		}
	}

	void printBT(const Node* node)
	{
		printBT("", node, false);
	}

	// pass the root node of your binary tree

};

