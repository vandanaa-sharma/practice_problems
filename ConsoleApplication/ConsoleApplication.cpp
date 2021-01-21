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
#include "10_BinaryTree_linkedlist.h"
#include "11_Minimum_Heap_Using_Array.h"
#include "12_MaxHeap_PriorityQueue.h"
#include "14_Binary_tree_operations.h"

using namespace std;

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

void functionPointer(int i) {
	cout << "Square = " << i * i << endl;
}

void funcPointerAsArgument(void (*f)(int), int j) {
	cout << "Calling f -";
	(*f)(j);
}

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

/* ------------------- Insertion Sort --------------------------- */

void insertionSort(int arr[], int size) {
	int i, j;
	int key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}


/* End ----------------------- Insertion Sort ------------------- */

int main()
{
	// Problem 01 - Print special characters in string	
	string s;
	cin >> s;
	printSpecialCharacters(s);
	
	/* -----------------------------------------------------------------------*/
	// Problem 02 - Implementation of vector

	project::vector<int> v;
	for (int i = 0; i < 40; i++)
	{
		v.push_back(i);
	}
	cout << v[39] << endl;

	/* -----------------------------------------------------------------------*/
	// Problem 04 - template function

	cout << GetMax(7, 9) << endl;

	/* -----------------------------------------------------------------------*/

	// Problem 05 - const pointer
	const int* i = nullptr;
	//*i = 10;                // compile error - value at memory cannot be modified
	int* const p = new int;
	int j = 9;
	//p = &j;                 // compile error - const after * --> pointer is constant,
	                          // pointer cannot be modified

	delete p;
	delete i;

	/* -----------------------------------------------------------------------*/

	// Problem 06 - Smart Pointer
	SmartPointer<int> sp(new int);
	*sp = 10;
	cout << "pointer value - " << *sp << endl;

	/* -----------------------------------------------------------------------*/

	// Problem 07 - Virtual Inheritance
	D objectD;
	objectD.printA();

	/* -----------------------------------------------------------------------*/

	// Problem 08 - exchange kth node of linked list from both ends
	LinkedList list =  LinkedList();
	list.add(0);
	list.add(1);
	list.add(2);
	list.add(3);
	list.add(4);
	list.add(5);
	list.add(6);
	list.add(7);
	list.add(8);
	list.add(9);
	list.add(10);

	list.print();
	int k;
	cout << "Enter index to swap in list " << endl;
	cin >> k;
	list.exchangeNode(k);

	/* -----------------------------------------------------------------------*/

	// Problem 09
	BinarySearchTree tree;
	tree.add(15);
	tree.add(32);
	tree.add(30);
	tree.add(37);
	tree.add(11);
	tree.add(9);
	tree.add(13);
	tree.add(7);
	tree.add(8);


	tree.printPretty();
	cout << endl << "Tree Height - " << tree.getHeight() << endl;
	

	/* -----------------------------------------------------------------------*/

	// Problem 10 - level order traversal

	tree.printLevels();

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

	// 04 - Insertion sort

	int iArray[] = { 5, 4, 7, 8, 1, 2, 9, 0 };
	int isize = sizeof(iArray) / sizeof(iArray[0]);
	insertionSort(iArray, isize);

	// 05 - Quick Sort


	// 06 - Heap sort

	int hArray[] = { 6, 5, 7, 3, 11, 1 };
	int hsize = sizeof(hArray) / sizeof(hArray[0]);
	// heapSort(hArray, bsize);

	//cout << "Sorted Array - ";
	//for (int y = 0; y < hsize; y++) {
	//	cout << hArray[y] << " ";
	//}
	//cout << endl;


	/* -----------------------------------------------------------------------*/
	// Problem  - Padding and Packing
	
	struct A {
		char p;
		char q;
		int i;
	};
	cout << "Size of structure A " << sizeof(A) << endl;
	// | p | q | - | - | i | i | i | i |------------------- 32 bit (4 bytes) processor

	#pragma pack(1) // ------------------ This prevents padding
	struct B {
		char p;
		char q;
		int i;
	};
	cout << "Size of structure B " << sizeof(B) << endl;
	// | p | q | i | i | i | i |------------------- no padding

	/* -----------------------------------------------------------------------*/

	// Problem 13 - Function Pointers
	// store, call, pass as argument, return type, use in quick sort
	void (*pf)(int) = functionPointer;
	(*pf)(9);
	funcPointerAsArgument(functionPointer, 10);

	/* -----------------------------------------------------------------------*/

	// Problem 14 - Check if your system is Big Endian or Little Endian
	unsigned int i = 1;
	char* c = (char*)&i;

	if (*c) {
		cout << "Little Endain " << endl;
	}
	else {
		cout << "Big Endain " << endl;
	}

	/* -----------------------------------------------------------------------*/

	// Problem 15 - Binary heap (minimum heap)
	MinHeap heap;
	heap.insert(3);
	heap.insert(2);
	heap.insert(1);
	heap.insert(8);
	heap.insert(4);
	heap.insert(0);

	heap.printHeap();

	heap.removeMinimum();
	heap.printHeap();

	heap.removeMinimum();
	heap.printHeap();

	/* -----------------------------------------------------------------------*/
	// Problem 16 - Priority Queue - Max Heap

	MH_PriorityQueue pQ;
	pQ.enqueue(3);
	pQ.enqueue(19);
	pQ.enqueue(9);
	pQ.enqueue(11);
	pQ.enqueue(4);

	pQ.printQueue();

	pQ.dequeue();
	pQ.printQueue();

	/* -----------------------------------------------------------------------*/
	// Problem 17 - Find least common ancestor for given node in binary tree



	/* -----------------------------------------------------------------------*/
	// Problem 18 - Find all nodes smaller than given node in binary heap



	/* -----------------------------------------------------------------------*/
	// Problem 19 - Print levels of binary tree



	/* -----------------------------------------------------------------------*/
	// Problem 20 - Find mirror of Binary Tree



	/* -----------------------------------------------------------------------*/
	// Problem 21 - Spiral Traveral Binary Tree


	/* -----------------------------------------------------------------------*/
	// Problem 22 - Priority queue using insertion sort



	/* -----------------------------------------------------------------------*/
	// Problem 22 - Fibonacci using dynamic programming



	/* -----------------------------------------------------------------------*/
	// Problem 23 - Convert a number to binary



	/* -----------------------------------------------------------------------*/
	// Problem 24 - Create integer from string


	/* -----------------------------------------------------------------------*/
	// Problem 25 - Find all factors of a given number


	/* -----------------------------------------------------------------------*/
	// Problem 26 - Find a random number in given range


	/* -----------------------------------------------------------------------*/
	// Problem 27 - Implement your own unordered - set class using hashmap
	// O(1) for insert and remove, unique elements
    


	/* -----------------------------------------------------------------------*/
	// Problem 28 - Implement your own unordered - map class using hashmap
	// O(1) for insert and remove, unique elements



	/* -----------------------------------------------------------------------*/
	// Problem 29 - C++ 11 features
	 /*
	 1. Lamba functions in C++
	 2. auto keyword
     3. Unordered sets and maps : stl
     4. = delete, = default, explicit
	 5. range based for loops
	 6. smart pointers
	 7. nullptr keyword
	 8. thread class
	 */



	 /* -----------------------------------------------------------------------*/
	 // Problem 30 - Multithreading examples and features
	 // Semaphore vs mutex

	/* -----------------------------------------------------------------------*/
	// Problem 31 - Find cycle in a linked list


	/* -----------------------------------------------------------------------*/
	// Problem 32 - Remove all elements that occur more than once in sorted linked list



	/* -----------------------------------------------------------------------*/
	// Problem 33 - Find median of an infinite list



	/* -----------------------------------------------------------------------*/
	// Problem 34 - Find median of an infinite list


	/* -----------------------------------------------------------------------*/
	// Problem 35 - STL -> set, vector, map, multimap, tuple
	// insert, sort, iterate, value at index, find, remove (front and back)


	/* -----------------------------------------------------------------------*/
	// Problem 36 - Static and dynamic librariers



	/* -----------------------------------------------------------------------*/
	// Problem 37 - contst, static, dynamic and reinterpret casts


	/* -----------------------------------------------------------------------*/
	// Problem -- - Design Patterns 


	_CrtDumpMemoryLeaks();
	return 0;
}



