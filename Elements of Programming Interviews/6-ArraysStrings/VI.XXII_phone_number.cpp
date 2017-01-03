/*!
 * \file 
 * \brief  VI.XXII_phone_number.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */


#include "VI_arrays_strings.h"
using namespace std;

vector<string> prefix(char c, vector<string> strings) {
	for (auto s = strings.begin(); s != strings.end(); s++) {
		*s = c + *s;
	}
	return strings;
}

vector<string> perm(vector<string>& groups, int d, unordered_map<int, string>& M) {
	vector<string> result;
	if (d < groups.size()) {
		string word = groups[d];
		for (auto c = word.begin(); c != word.end(); c++) {
			vector<string> newOnes = prefix(*c, perm(groups, d + 1, M));
			result = help::concatenate(result, newOnes);
		}
	}
	else
		result.push_back("");
	return result;
}

vector<string> generateMnemonics(string number) {
	unordered_map<int, string> M;
	M.emplace(1, "1");
	M.emplace(2, "ABC");
	M.emplace(3, "DEF");
	M.emplace(4, "GHI");
	M.emplace(5, "JKL");
	M.emplace(6, "MNO");
	M.emplace(7, "PQRS");
	M.emplace(8, "TUV");
	M.emplace(9, "WXYZ");
	M.emplace(0, "0");


	vector<string> letterGroups;
	for (auto c = number.begin(); c != number.end(); c++) {
		string digit(c, c + 1);
		string fix = M[stoi(digit)];
		letterGroups.push_back(fix);
	}

	return perm(letterGroups, 0, M);
}
