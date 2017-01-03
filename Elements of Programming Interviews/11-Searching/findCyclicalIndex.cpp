/*!
 * \file 
 * \brief   findCyclicalIndex.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "searching.h"

using namespace std;

int findCyclicalIndex(const vector<int> &array) {
	int lower = 0;
	int upper = array.size() - 1;
	int last = array[upper];
	int startIndex = 0;

	while (lower <= upper) {
		int middle = lower + (upper - lower) / 2;
		if (array[middle] <= last) {
			startIndex = middle;
			upper = middle - 1;
		}
		else {
			lower = middle + 1;
		}
	}

	return startIndex;
}


