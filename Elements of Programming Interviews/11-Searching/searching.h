/*!
 * \file 
 * \brief  searching.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef SEARCHING_H_
#define SEARCHING_H_

#include <vector>
#include "helper.h"
#include <map>
using namespace std;

int binarySearch (const vector<int>& array, int val);

// 11.1
int firstOccurence (const vector<int>& array, int val);

// 11.2 first element greater than a given value
int firstGreaterThan (const vector<int>& array, int val);

// 11.3
int indexWithSameValue(const vector<int>& array);

// 11.4 Find pair that sums up to value
pair<int, int> findPairWithSum(const vector<int> &array, int val);

// 11.5 Given cyclically sorted array, find index in O(logn)
int findCyclicalIndex(const vector<int> &array);

// 11.13
template <typename T>
T kthLargestElement(vector<T>& A, const int &k);
template <typename T>
int partition(vector<T> &A, const int &l, const int &r, const int &pivot);

#endif /* SEARCHING_H_ */
