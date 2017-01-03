/*!
 * \file 
 * \brief  sumBinary.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

string sumBinary(string a, string b) {
	string result;
	bool carry = false;

	string::reverse_iterator itA = a.rbegin();
	string::reverse_iterator itB = b.rbegin();

	while (itA != a.rend() || itB != b.rend()) {
		char cA;
		char cB;

		if (itA == a.rend())
			cA = '0';
		else {
			cA = *itA;
			itA++;
		}
		if (itB == b.rend())
			cB = '0';
		else {
			cB = *itB;
			itB++;
		}
		char newChar;

		if (cA == '1' && cB == '1') {
			if (carry) {
				newChar = '1';
			}
			else {
				carry = true;
				newChar = '0';
			}
		}
		else if (cA == '0' && cB == '0') {
			if (carry) {
				newChar = '1';
				carry = false;
			}
			else {
				newChar = '0';
			}
		}
		else {
			if (carry) {
				newChar = '0';
				carry = true;
			}
			else {
				newChar = '1';
			}
		}

		result = newChar + result;
	}

	if (carry)
		result = '1' + result;

	return result;
}


