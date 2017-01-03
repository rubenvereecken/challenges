/*!
 * \file 
 * \brief  collatzConjecture.cpp
 *
 * \date   Sep 9, 2013
 * \author Ruben Vereecken
 */

#include "intractability.h"
#include <iostream>
using namespace std;

bool checkCollatzNumber(int x, vector<bool> &cache) {
	if (cache[x / 2]) {
		return true;
	}
	else {
		if (x % 2 == 0) {
			return checkCollatzNumber(x / 2, cache);
		}
		else {
			return (cache[x / 2] = checkCollatzNumber(3 * x + 1, cache));
		}
	}
}

// Checks the Collatz conjecture for all numbers up until n
bool checkCollatz (int n) {
	// Hold only odds to save space
	// To recompute the number, perform x * 2  + 1
	// To hash onto the cache, perform x / 2
	// E.g. 501 is stored at 250
	vector<bool> oddCache(n / 2 + 1, false);
	oddCache[0] = true;

	for (int i = 1; i <= n; ++i) {
		checkCollatzNumber(i, oddCache);
	}

	for (bool isCollatz : oddCache) {
		if (!isCollatz)
			return false;
	}
	return true;
}
