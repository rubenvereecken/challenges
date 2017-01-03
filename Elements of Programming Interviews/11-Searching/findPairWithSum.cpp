/*!
 * \file 
 * \brief  findPairWithSum.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "searching.h"
using namespace std;

inline int abs(int a) {
	return (a < 0) ? -a : a;
}

// Array is expected to be sorted by ABSOLUTE VALUE
pair<int, int> findPairWithSum(const vector<int> &array, int val) {
	// Both positive
	int highPos = array.size() - 1;
	int lowPos = 0;

	while (lowPos < array.size() && array[lowPos] < 0)
		++lowPos;

	while (highPos >= 0 && array[highPos] < 0)
		--highPos;

	while (lowPos < array.size() && highPos >= 0 && lowPos < highPos) {
		int sum = abs(array[lowPos]) + abs(array[highPos]);
		if (sum < val) {
			do {
				++lowPos;
			} while (lowPos < array.size() && lowPos < 0);
		} else if (sum > val) {
			do {
				--highPos;
			} while (highPos >= 0 && highPos < 0);
		} else
			return make_pair(lowPos, highPos);
	}

	// Both negative
	int highNeg = array.size() - 1;
	int lowNeg = 0;

	while (lowNeg < array.size() && array[lowNeg] > 0)
		++lowNeg;

	while (highNeg >= 0 && array[highNeg] > 0)
		--highNeg;

	while (lowNeg < array.size() && highNeg >= 0 && lowNeg > highNeg) {
		int sum = -abs(array[lowNeg]) - abs(array[highNeg]);
		if (sum < val) {
			do {
				--highNeg;
			} while (highNeg >= 0 && array[highNeg] > 0);
		} else if (sum > val) {
			do {
				++lowNeg;
			} while (lowNeg < array.size() && array[lowNeg] > 0);
		} else
			return make_pair(lowNeg, highNeg);
	}

// Mixed
	int positive = array.size() - 1; // Invariant: always points to positive
	int negative = array.size() - 1;

	while (positive >= 0 && array[positive] < 0)
		positive--;

	while (negative >= 0 && array[negative] >= 0)
		negative--;

	while (positive >= 0 && negative >= 0) {
		if (array[positive] + array[negative] == val) {
			return make_pair(positive, negative);
		} else if (array[positive] + array[negative] > val) {
			do {
				positive--;
			} while (positive >= 0 && array[positive] < 0);
		} else {
			do {
				negative--;
			} while (negative >= 0 && array[negative] >= 0);
		}
	}

	return make_pair(-1, -1);
}

