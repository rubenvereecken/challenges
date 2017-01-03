/*!
 * \file 
 * \brief  kthSmallest.cpp
 *
 * \date   Sep 16, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

inline void swap(int &a, int &b) { a ^= b ^= a ^= b; }

int partition(vector<int>& array, int l, int u, int p) {
	int pivotVal = array[p];

	int newPivot = u;
	swap(array[p], array[l]);

	for (int i = u; i > l; --i) {
		if (array[i] > pivotVal) {
			swap(array[i], array[newPivot]);
			newPivot--;
		}
	}

	swap(array[p], array[newPivot]);

	return newPivot;
}

int kthSmallest(vector<int> array, int k) {
	int l = 0;
	int u = array.size() - 1;

	while (l <= u) {
		int p = (l + u) / 2;

		p = partition(array, l, u, p);
		if (p == k - 1) {
			return array[p];
		}
		else if (p < k - 1) {
			l = p + 1;
		}
		else {
			u = p - 1;
		}
	}
}
