/*!
 * \file 
 * \brief  kthLargestElement.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <random>
#include <stdexcept>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include "searching.h"
#include "helper.h"

using namespace std;

// Partition A according pivot, return its index after partition
template<typename T>
int partition(vector<T> &A, const int &l, const int &r, const int &pivot) {
	T pivot_value = A[pivot];
	int larger_index = l;
	swap(A[pivot], A[r]);

	for (int i = l; i < r; ++i) {
		if (A[i] > pivot_value) {
			swap(A[i], A[larger_index++]);
		}
	}

	swap(A[r], A[larger_index]);

	return larger_index;
}

template<typename T>
T kthLargestElement(vector<T>& A, const int &k) {
	int l = 0, r = A.size() - 1;

	while (l <= r) {
		default_random_engine gen((random_device())());
		uniform_int_distribution<int> dis(l, r); // generate random int in [l, r]
		int p = partition(A, l, r, dis(gen));
		if (p == k - 1) {
			return A[p];
		} else if (p > k - 1) {
			r = p - 1;
		} else {  // p < k - 1
			l = p + 1;
		}
	}
}

template int partition(vector<int> &A, const int &l, const int &r,
		const int &pivot);
