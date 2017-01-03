/*!
 * \file 
 * \brief  firstGreaterThan.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "searching.h"
using namespace std;

int firstGreaterThan(const vector<int>& array, int val) {
	int lower = 0;
	int upper = array.size() - 1;
	int found = -1;



	bool valFound = false;

	while (lower <= upper) {
		int middle = lower + (upper - lower) / 2;
		if (array[middle] <= val) {
			lower = middle + 1;
		} else {
			found = middle;
			upper = middle - 1;
		}
	}


	return found;
}

