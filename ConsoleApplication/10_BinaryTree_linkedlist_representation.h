#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

class BinarySearchTree
{
	struct Node {
		int data;
		Node* left;
		Node* right;
	};

	Node* root = nullptr;
	int dataToAdd, count = 0;
	map<int, vector<Node*>> levelMap;

public:

	BinarySearchTree() {

	}

	void add(int data) {
		dataToAdd = data;
		if (root == nullptr) {
			root = new Node();
			root->data = data;
			root->left = nullptr;
			root->right = nullptr;
		}
		else
		{
			Node* newNode = new Node();
			newNode->data = dataToAdd;
			newNode->left = nullptr;
			newNode->right = nullptr;
			
			Node* insertAt = recurseThis(root);
			cout << "Node found to insert at " << insertAt->data << endl;
			if (dataToAdd < insertAt->data) {
				insertAt->left = newNode;
			}
			else if (dataToAdd > insertAt->data) {
				insertAt->right = newNode;
			}

		}
	}

	Node* recurseThis(Node* node) {
		if (dataToAdd < node->data) {
			if (node->left == nullptr) {
				return node;
			}
			recurseThis(node->left);
		}
		else if (dataToAdd > node->data)
		{
			if (node->right == nullptr) {
				return node;
			}
			recurseThis(node->right);
		}
	}

	void addLeftNode(Node* root) {

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
		//using power of 2 logic
		count = 0;
		if (root != nullptr) {
			count = recurseHeight(root);
			int powerOfTwo = 0;
			while (pow(2, powerOfTwo) <= count) {
				powerOfTwo++;
			}
			return powerOfTwo;
		}
		return 0;
	}
	
	void printLevels() {
		queue<Node*> queue;
		int level = 0;
		map<int, vector<int>> levels;
		if (root != nullptr) {
			queue.push(root);
			vector<int> nodes;

			while (queue.size() > 0) {
				Node* firstNode = queue.front();

				levels[level].push_back(firstNode->data);

				if (pow(2, level) == levels[level].size()) {
					nodes.clear();
					level++;
					if (!(firstNode->left == nullptr && firstNode->right == nullptr))
						levels.emplace(level, nodes);
				}

				queue.pop();

				if (firstNode->left != nullptr) {
					queue.push(firstNode->left);
				}
				if (firstNode->right != nullptr) {
					queue.push(firstNode->right);
				}
			}

			for (auto level : levels) {
				cout << "Level - " << level.first << endl << "Nodes - ";
				vector<int> nodes = level.second;
				for (int i : nodes) {
					cout << i << " ";
				}
				cout << endl;
			}
		}
	}

private:

	int recurseHeight(Node* node) {
		if (node != nullptr) {
			count++;
			recurseHeight(node->left);
			recurseHeight(node->right);
		}
		return count;
	}


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
			preOrder(root->left);
			cout << root->data << endl;
			preOrder(root->right);
		}
	}

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



