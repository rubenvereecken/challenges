/*!
 * \file 
 * \brief  intersectArrays.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "sorting.h"
#include <vector>


using namespace std;

// Arrays are expected to be sorted.
// Sizes more or less the same.
template <typename T>
vector<T> intersectArrays(vector<T>& a, vector<T>& b) {
	auto currentA = a.begin();
	auto currentB = b.begin();
	vector<T> intersection;


	while ((currentA != a.end()) && (currentB != b.end())) {
		if (*currentA > *currentB) {
			currentB++;
		}
		else if (*currentB > *currentA) {
			currentA++;
		}
		else {
			intersection.emplace_back(*currentA);
			currentA++;
			currentB++;
		}
	}

	return intersection;
}

template vector<int> intersectArrays(vector<int>& a, vector<int>& b);
