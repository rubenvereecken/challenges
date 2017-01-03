/*!
 * \file 
 * \brief  substring.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

// O(nm) because suffix trees are a weird bunch
string longestCommon(string a, string b) {
	vector<vector<int> > matrix(a.size() + 1, vector<int>(b.size() + 1));

	int maxSize = 0;
	string maxString;

	for (unsigned int i = 1; i <= a.size(); ++i) {
		for (unsigned int j = 1; j <= b.size(); ++j) {
			if (a[i - 1] == b[j - 1]) {
				matrix[i][j] = matrix[i-1][j-1] + 1;

				if (matrix[i][j] > maxSize) {
					maxSize = matrix[i][j];
					maxString = a.substr(i - maxSize, maxSize);
				}
			}
		}
	}

	return maxString;
}

