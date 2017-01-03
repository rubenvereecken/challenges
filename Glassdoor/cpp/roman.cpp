/*!
 * \file 
 * \brief  roman.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

int fromRoman(string roman) {
	int result = 0;

	map<char, int> value ({
		{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
	});

	for (string::const_iterator numeral = roman.begin(); numeral != roman.end(); numeral++) {
		if ((numeral + 1 != roman.end()) && value[*(numeral + 1)] > value[*(numeral)]) {
			result -= value[*numeral];
		}
		else
			result += value[*numeral];
	}

	return result;
}


