/*!
 * \file 
 * \brief  reverse.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "primitiveTypes.h"

using namespace std;

bit64 reverse(bit64 num) {
	bit64 r = 0;

	for (int i = 0; i < 64; i++) {
		r |= num & 1;
		r <<= 1;
		num >>= 1;
	}

	return r;
}


