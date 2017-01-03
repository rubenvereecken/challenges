/*!
 * \file 
 * \brief  VI.I_dutch_national_flag.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
using namespace std;

inline void swap(int& a, int& b) {
	std::cout << "swapping " << a << " and " + b << std::endl;
	a ^= b ^= a ^= b;
}

void print_array(const int * array, int length, std::ostream& out=std::cout) {
	out << "[";
	for (int i = 0; i < length; i++) {
		out << array[i];
		if (i != length - 1)
			out << ", ";
	}
	out << "]\n";
}


void dutchFlag(int array[], int size, int index) {
	int lowerCount = 0;
	int equalCount = 0;
	int higherCount = 0;

	int pivot = array[index];
	cout << "pivot: " << pivot << endl;

	// O(n)
	for (int i = 0; i < size; i++) {
		if (array[i] < pivot)
			lowerCount++;
		else if (array[i] > pivot)
			higherCount++;
		else
			equalCount++;
	}


	int lowerIndex = 0;
	int equalIndex = lowerCount;
	int higherIndex = equalCount;
/*
	for (int i = 0; i < size; i++) {
		print_array(array, 5);
		cout << "low: " << lowerIndex << endl;
		if (array[i] < pivot && (i < lowerCount)) {
			if (i != lowerIndex++)
				swap(array[i], array[lowerIndex]);
		}
		else if (array[i] > pivot) {
			while (array[higherIndex++] )
			swap(array[i], array[higherIndex++]);
		}
		else
			swap(array[i], array[equalIndex++]);
	}*/
}
