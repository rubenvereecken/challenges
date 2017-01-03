/*!
 * \file 
 * \brief  dutchFlag.cpp
 *
 * \date   Sep 17, 2013
 * \author Ruben Vereecken
 */


#include "GlassDoor.h"

using namespace std;

inline void swap(int& a, int& b) {
	a ^= b ^= a ^= b;
}


/*
 * Given an array of 0's, 1's and 2's, sort
 */

void dutchFlag(vector<int> &array) {
	int zeroesIndex = 0;
	int twosIndex = array.size() - 1;

	for (int current = 0; current <= twosIndex; current++) {
		if (array[current] == 0) {
			while (array[current] == 0) {
				swap(array[current], array[zeroesIndex]);
				zeroesIndex++;
			}
		}
		else if (array[current] == 2) {
			while (array[current] == 2) {
				swap(array[current], array[twosIndex]);
				twosIndex--;
			}
		}
	}
}
