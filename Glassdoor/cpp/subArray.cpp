/*!
 * \file 
 * \brief  maxSub.cpp
 *
 * \date   Sep 13, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

inline int max(int a, int b) {
	return (a > b) ? a : b;
}

pair<int, int> minSubSet(const vector<int> & array, int treshold) {
	int begin = 0;
	int end = 0;

	int sumIncluded = 0;
	int sumCurrent = 0;

	for (int i = 0; i < array.size(); ++i) {
		sumIncluded = sumCurrent + array[i];

	}

	return make_pair(begin, end);
}

pair<int, int> maxSubArray(const vector<int> & array) {
	int begin = 0;
	int end = 0;

	int maxIncluded = 0;
	int maxCurrent = 0;

	for (int i = 0; i < array.size(); ++i) {

		maxIncluded = max(0, maxIncluded + array[i]);
		if (maxIncluded == 0) {
			begin = i + 1;
		}

		int maxPrev = maxCurrent;
		maxCurrent = max(maxIncluded, maxCurrent);

		if (maxCurrent > maxPrev) {
			end = i;
		}
	}

	return make_pair(begin, end);
}

pair<int, int> maxSubCyclicArray(const vector<int> & array) {

}

