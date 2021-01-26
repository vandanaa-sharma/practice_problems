#pragma once

#include <iostream>
#include <thread>
#include <chrono>
#include <future>

using namespace std;

// Problem 17 - Multithreading
void functionInThread1(int value) {
	// Printing thread id
	cout << "This is a function running in " << this_thread::get_id << endl;
	cout << "Incrementing input " << ++value << endl;
}

void functionInThread2(int& value) {
	// Printing thread id
	cout << "This is a function running in " << this_thread::get_id << endl;
	cout << "Incrementing input value passed by ref " << ++value << endl;
}

// Tempate function with sleep
template< class T>
void functionInThread3(T& value) {
	// Printing thread id
	cout << "This is a function running in " << this_thread::get_id << endl;
	this_thread::sleep_for(chrono::seconds(1));
	cout << "Type of value passed " << typeid(value).name() << endl;
}

// Asynchronous function using future
int asynchronousFunction1(int& a) {
	cout << "Executing async function " << endl;
	return a += 10;
}

//  Function that takes promise and sets value
void setValueOfPromise(promise<int>& p) {
	cout << "Setting value of promise " << endl;
	this_thread::sleep_for(chrono::seconds(1));
	p.set_value(10);
}


void multithreading() {

	/* -----------------------------------------------------------------------*/
	// Problem 17 -  Multithreading examples and features

	int argumentValue = 10;
	thread t1{ functionInThread1, argumentValue };
	t1.join();
	// t1.join(); --> throws an exception, if called twice
	if (t1.joinable()) {
		t1.join();
	}

	// Pass value by reference to a thread
	thread t2(functionInThread2, ref(argumentValue));
	t2.join();

	// Lambda functions
	thread t3([=](int a) noexcept ->int {
		cout << "Inside lamda function " << endl;
		cout << "This is a function running in " << this_thread::get_id << endl;
		a++;
		return a;
		}, argumentValue);
	t3.join();

	thread t4([&]() {
		cout << "Inside lamda function accessing values in local scope" << endl;
		cout << "This is a function running in " << this_thread::get_id << endl;
		argumentValue++;
		});

	t4.join();
	cout << argumentValue << endl;

	// Using template functions and sleep
	int i = 89;
	float f = 7.32;

	thread t5(functionInThread3<int>, ref(i));
	t5.join();

	thread t6(functionInThread3<float>, ref(f));
	t6.join();

	// Asychronous function using future
	future<int> future1 = async(launch::async, asynchronousFunction1, ref(i));
	if (future1.valid()) {
		cout << future1.get() << endl;
	}

	promise<int> promise1;
	// Initialize future with promise
	future<int> future2 = promise1.get_future();
	promise1.set_value(23);
	if (future2.valid()) {
		cout << future2.get() << endl;
	}

	// Passing data between 2 threads using future and promise (C++11)
	promise<int> promise2;
	future<int> future3 = promise2.get_future();
	thread t7(setValueOfPromise, ref(promise2));
	// future3.get() line is not executed until promise2.set_value() is called in t7
	cout << "Value = " << future3.get() << endl; // this value comes to main thread from t7
	t7.join();

	// Race condition

	int count = 0;

	thread t8([&]() {
		for (int p = 0; p < 10; p++)
			this_thread::sleep_for(chrono::milliseconds(10));
			count++;
		}
	);
	thread t9([&]() {
		for (int q = 0; q < 10; q++)
			count++;
		}
	);

	vector<thread> vectThreads;
	vectThreads.push_back(move(t8));
	vectThreads.push_back(move(t9));

	for (thread& t : vectThreads) {
		if (t.joinable()) {
			t.join();
		}
	}

	cout << "Final count " << count << endl;

	// Dead lock

	// live lock


	// Mutex

}
