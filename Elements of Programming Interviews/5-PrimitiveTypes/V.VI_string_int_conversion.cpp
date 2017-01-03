/*!
 * \file 
 * \brief  V.VI_string_int_conversion.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "primitiveTypes.h"
#include <sstream>;
#include <algorithm>

using namespace std;

string intToString(int x) {
	bool isNegative;
	string result;

	if (isNegative = (x < 0))
		x = -x;

	while (x) {
		result += ('0' + x % 10);
		x /= 10;
	}

	if (isNegative)
		result += '-';

	if (result.empty())
		result = '0';

	std::reverse(result.begin(), result.end());
	return result;
}
