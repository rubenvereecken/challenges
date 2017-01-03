/*!
 * \file 
 * \brief  binarySearch.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "searching.h"
using namespace std;

/*
 * Array is expected to be sorted.
 */
int binarySearch (const vector<int>& array, int val) {
	int lower = 0;
	int upper = array.size() - 1;

	while (lower <= upper) {
		int middle = lower + (upper - lower) / 2;
		if (array[middle] < val) {
			lower = middle + 1;
		}
		else if (array[middle] == val) {
			return middle;
		}
		else {
			upper = middle - 1;
		}
	}

	return -1;
}
