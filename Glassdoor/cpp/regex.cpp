/*!
 * \file 
 * \brief  regex.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

// * is greedy
bool matches(string word, string pattern) {
	string::iterator wordIt = word.begin();
	string::iterator patIt = pattern.begin();

	while (wordIt != word.end() && patIt != pattern.end()) {
		if (*patIt == '.') {
			wordIt++;
			patIt++;
		}
		else if (*patIt == '*') {
			char matchChar = *(patIt - 1);
			patIt++;
			while (*wordIt == matchChar) {
				wordIt++;
			}
		}
		else {
			if (*patIt == *wordIt) {
				wordIt++;
				patIt++;
			}
			else
				return false;
		}
	}

	return (wordIt == word.end() && patIt == pattern.end());
}

