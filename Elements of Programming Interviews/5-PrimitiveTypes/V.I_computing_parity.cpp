/*!
 * \file 
 * \brief  5.1_computing_parity.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */


#include "primitiveTypes.h"
#include <map>
using namespace std;

map<uint_least64_t, char> parityCache;


bool iterativeParity(uint_least64_t x)
{
	bool parity;

	for (parity = false; x != 0; x >>= 1)
		parity ^= (x & 1);

	return parity;
}

bool recursiveParity(uint_least64_t x)
{
	bool parity;
	if (x) {
		parity = (x & 1);
		return parity ^ recursiveParity(x >> 1);
	}
	else
		return 0;

	return parity;
}

bool cachedRecursiveParity(uint_least64_t x)
{
	bool parity;

	if (x) {
		if (parityCache.count(x))
			return parityCache[x];
		else {
			bits64 bs(x);
			bool parity = (x & 1);
			return (parityCache[x] = (parity ^ cachedRecursiveParity(x >> 1)));
		}
	}
	else
		return 0;

	return parity;
}
