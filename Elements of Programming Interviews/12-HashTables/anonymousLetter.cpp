/*!
 * \file 
 * \brief  anonymousLetter.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "hashTables.h"
#include <map>
#include <algorithm>

using namespace std;

/*
 * Checks if text L can be covered with text M. (letter by magazine)
 */
bool letterWritableWithText(string& L, string& M) {
	map<char, int> hash;
	for_each(L.begin(), L.end(), [&] (const char &c) {++hash[c];});

	for (const char& c : M) {
		auto it = hash.find(c);
		if (it != hash.cend()) {
			if (--it->second == 0) {
				hash.erase(it);
				if (hash.empty()) return true;
			}
		}
	}

	return false;
}


