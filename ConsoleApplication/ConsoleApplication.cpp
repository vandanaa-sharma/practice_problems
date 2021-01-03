// ConsoleApplication.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <regex>
#include <string>
#include <stack>
#include "vector.h"
#include "SmartPointer.h"
#include <crtdbg.h>
#include "VirtualInheritance.h"
#include "02_LinkedList.h"
#include "10_BinaryTree_linkedlist_representation.h"

using namespace std;
void printSpecialCharacters(string s);

// Problem 04 - template function 
template <class T>
T GetMax(const T &a, const T &b) {
	T result = a < b ? b : a;
	return result;
}


// Problem 03 - Mutable vs const
class TestMutable {
private:
	int i = 0;
	mutable int j = 1;
public:
	void modifyVariables() const
	{
		// i++;               // Compile error because function is const
		j++;
		cout << "Const vs Mutable " << i << " " << j << endl;
	}
};

/* ------------------- Merge Sort --------------------------- */

/* End ----------------------- Merge Sort ------------------- */


/* -------------------- Selection Sort -------------------------- */

void selectionSort(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		int min = arr[i];
		int index = i;
		for (int j = i; j < size; j++) {
			if (arr[j] < min) {
				min = arr[j];
				index = j;
			}
		}
		if (arr[i] != min) {
			int temp = arr[i];
			arr[i] = min;
			arr[index] = temp;
		}
	}
}

/* End ----------------------- Selection Sort -------------------- */

/* ------------------ Bubble Sort -------------------------- */
void bubbleSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j+1]) {
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

/* End ----------------------- Bubble Sort------------------- */

int main()
{
	// Problem 01 - Print special characters in string
	/*
	string s;
	cin >> s;
	printSpecialCharacters(s);
	*/

	/* -----------------------------------------------------------------------*/

	// Problem 02 - Implementation of vector
	//project::vector<int> v;
	//for (int i = 0; i < 40; i++)
	//{
	//	v.push_back(i);
	//}
	//cout << v[39] << endl;

	///* -----------------------------------------------------------------------*/

	// Problem 04 - template function
	//cout << GetMax(7, 9) << endl;

	/* -----------------------------------------------------------------------*/

	// Problem 05 - const pointer
	//const int* i = nullptr;
	////*i = 10;                // compile error
	//int* const p = new int;
	//int j = 9;
	////p = &j;                 // compile error - const after * --> pointer is constant

	//delete p;
	//delete i;

	/* -----------------------------------------------------------------------*/

	// Problem 06 - Smart Pointer
	//SmartPointer<int> sp(new int);
	//*sp = 10;
	//cout << "pointer value - " << *sp << endl;


	/* -----------------------------------------------------------------------*/

	// Problem 07 - Virtual Inheritance
	//D objectD;
	//objectD.printA();


	/* -----------------------------------------------------------------------*/

	// Problem 08 - exchange kth node of linked list from both ends
	//LinkedList list =  LinkedList();
	//list.add(0);
	//list.add(1);
	//list.add(2);
	//list.add(3);
	//list.add(4);
	//list.add(5);
	//list.add(6);
	//list.add(7);
	//list.add(8);
	//list.add(9);
	//list.add(10);

	//list.print();
	//int k;
	//cout << "Enter index to swap in list " << endl;
	//cin >> k;
	//list.exchangeNode(k);

	/* -----------------------------------------------------------------------*/

	// Problem 09
	//BinarySearchTree tree;
	//tree.add(15);
	//tree.add(32);
	//tree.add(30);
	//tree.add(37);
	//tree.add(11);
	//tree.add(9);
	//tree.add(13);

	/*
	tree.printPretty();
	cout << endl << "Tree Height - " << tree.getHeight() << endl;
	*/

	/* -----------------------------------------------------------------------*/

	// Problem 10 - level order traversal

	//tree.printLevels();

	/* -----------------------------------------------------------------------*/

	// Problem 11 - Sorting algorithms


	// 01 - Merge Sort
	//vector<int> mArray = { 6,5,7,3 };
	//mergeSort(array, 0, array.size());

	// 02 - Selection sort

	int sArray[] = { 6, 5, 7, 3, 11, 1 };
	int size = sizeof(sArray) / sizeof(sArray[0]);
	selectionSort(sArray, size);

	// 03 - Bubble sort

	int bArray[] = { 6, 5, 7, 3, 11, 1 };
	int bsize = sizeof(bArray) / sizeof(bArray[0]);
	bubbleSort(bArray, bsize);

	cout << "Sorted Array - ";
	for (int y = 0; y < bsize; y++) {
		cout << bArray[y] << " ";
	}
	cout << endl;

	// 04 - Quick Sort

	// 05 - Heap sort






	/* -----------------------------------------------------------------------*/

	// Problem 12



	/* -----------------------------------------------------------------------*/

	// Problem 13


	/* -----------------------------------------------------------------------*/

	// Problem 14



	/* -----------------------------------------------------------------------*/
	// Problem 15




	/* -----------------------------------------------------------------------*/

	_CrtDumpMemoryLeaks();
	return 0;
}

// Problem 01 - Print special characters in string
void printSpecialCharacters(string s) {
	for (int i = 0; i < s.size(); i++) {
		int c = (int)s[i];
		if ((c <= 65 && c >= 90) && (c >= 122 && c <= 97)) {
			cout << c << endl;
			cout << s[i] << endl;
		}
	}
}



