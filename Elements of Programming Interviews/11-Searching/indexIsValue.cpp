/*!
 * \file 
 * \brief  indexIsValue.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "searching.h"
using namespace std;

/*
 * Returns an index i such that A[i] = i, else returns 1
 * A should be sorted with distinct elements only.
 */
int indexWithSameValue(const vector<int>& array) {
	int lower = 0;
	int upper = array.size() - 1;

	while (lower <= upper) {
		int middle = lower + (upper - lower) / 2;
		if (array[middle] < middle) {
			lower = middle + 1;
		}
		else if (array[middle] == middle) {
			return middle;
		}
		else { // array[middle] > middle
			upper = middle - 1;
		}
	}

	return -1;
}
