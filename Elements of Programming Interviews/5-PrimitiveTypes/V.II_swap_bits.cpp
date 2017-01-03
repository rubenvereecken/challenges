/*!
 * \file 
 * \brief  V.II_swap_bits.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "primitiveTypes.h"
using namespace std;

uint_least64_t swapBits(uint_least64_t x, int i, int j) {
	if ((x >> i) ^ (x >> j)) {
		x ^= (1 << i);
		x ^= (1 << j);
	}
	return x;
}
