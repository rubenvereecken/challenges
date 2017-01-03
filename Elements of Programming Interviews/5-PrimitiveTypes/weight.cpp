/*!
 * \file 
 * \brief  weight.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "primitiveTypes.h"

using namespace std;

bit64 closestSameWeight(bit64 u) {
	bit64 c = u;

	int offsetFirst = 0;

	while (u && u ^ 1) {
		offsetFirst++;
		u >>= 1;
	}

	int offsetSecond = offsetFirst;

	while (u && u ^ 0) {
		offsetSecond++;
		u >>= 1;
	}

	c ^= 1 << offsetFirst;
	c |= 1 << offsetSecond;

	return c;
}

