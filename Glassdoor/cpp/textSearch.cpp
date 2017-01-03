/*!
 * \file 
 * \brief  textSearch.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

// "length of longest prefix of string that is suffix of string[i...j]"
vector<int> failureFunction(string a) {
	if (a.empty())
		return vector<int>();

	vector<int> failure(a.size());
	failure[0] = 0;

	int j = 0;
	for (unsigned int i = 1; i < a.size(); i++) {
		if (a[i] == a[j]) {
			failure[i] = j + 1;
			j++;
		} else {
			j = 0;
			failure[i] = 0;
		}
	}

	return failure;
}

/*
 * returns index of string or -1
 */
int find(const string& text, const string &word) {
	vector<int> failure = failureFunction(word);

	int j = 0;
	int m = word.size();

	for (unsigned int i = 0; i < text.size(); i++) {
		if (text[i] == word[j]) {
			if (j == m - 1)
				return i - m + 1;
			j++;

		}
		else if (j > 0) {
			j = failure[j - 1];
		}

	}

	return -1;
}

