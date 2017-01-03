/*!
 * \file 
 * \brief  lookAndSay.cpp
 *
 * \date   Sep 11, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

string nextLookAndSay(string number) {
	string newNumber;

	int currentCount = 0;
	char currentDigit = number[0];

	for (const auto &digit : number) {
		if (digit == currentDigit)
			currentCount++;
		else {
			newNumber += help::itostr(currentCount);
			newNumber += currentDigit;

			currentDigit = digit;
			currentCount = 1;
		}
	}

	newNumber += help::itostr(currentCount);
	newNumber += currentDigit;

	return newNumber;
}

