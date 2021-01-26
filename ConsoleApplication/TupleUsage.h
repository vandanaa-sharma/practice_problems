#pragma once
#include <iostream>
#include <tuple>

using namespace std;

void tuple_usage() {

	// Initialization
	tuple<int, string, float> tuple1 = { 5, "Tuple1", 9.89 };
	tuple<int, float, string> tuple2;
	tuple2 = make_tuple(7, 2.54, "Tuple2");

	// Get values
	cout << get<0>(tuple1) << endl;
	cout << get<1>(tuple1) << endl;
	cout << get<2>(tuple1) << endl;

	// tie --> unpack into variables
	int i1, i2;
	float f1, f2;
	string s1, s2;
	tie(i1, s1, f1) = tuple1;
	cout << i1 << " " << s1 << " " << f1 << endl;
	tie(i2, f2, s2) = tuple2;
	cout << i2 << " " << s2 << " " << f2 << endl;

	// swap
	tuple<int, string, float> tuple3 = { 6, "Tuple3", 6.09 };
	tuple1.swap(tuple3);

	// tuple_cat --> join two tuples
	auto tuple4 = tuple_cat(tuple1, tuple2);
	cout << get<0>(tuple1) << endl;
	cout << get<1>(tuple1) << endl;
	cout << get<2>(tuple1) << endl;
	cout << get<3>(tuple4) << endl;
	cout << get<4>(tuple4) << endl;
	cout << get<5>(tuple4) << endl;

	// size
	int size = tuple_size<decltype(tuple4)>::value;
	cout << "Tuple size " << size << endl;


}