/*!
 * \file 
 * \brief  VI_arrays_strings.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef VI_ARRAYS_STRINGS_H_
#define VI_ARRAYS_STRINGS_H_

#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include "helper.h"

// 6.1
void dutchFlag(int array[], int size, int index);

// 6.14
bool isSudokuValid(int sudoku[][9]);

// 6.22
vector<string> generateMnemonics(string number);

#endif /* VI_ARRAYS_STRINGS_H_ */
