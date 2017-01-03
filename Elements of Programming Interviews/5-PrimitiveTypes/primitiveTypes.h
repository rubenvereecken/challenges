/*!
 * \file 
 * \brief  5_primitive_types.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef V_PRIMITIVE_TYPES_H_
#define V_PRIMITIVE_TYPES_H_

#include <boost/cstdint.hpp>
#include <bitset>
#include <iostream>

typedef std::bitset<64> bits64;
typedef uint_least64_t bit64;

// 5.1
bool iterativeParity(uint_least64_t);
bool recursiveParity(uint_least64_t);
bool cachedRecursiveParity(uint_least64_t x);

// 5.2
uint_least64_t swapBits(uint_least64_t, int, int);

// 5.3 reverse
bit64 reverse(bit64 num);

// 5.4 closest 64bit int with same weight
// Define weight = #bits=1
bit64 closestSameWeight(bit64 u);

// 5.5
// See combination(set, i) in helper.h, for i = 0 up to set.size()

// 5.6
std::string intToString(int);


#endif /* V_PRIMITIVE_TYPES_H_ */
