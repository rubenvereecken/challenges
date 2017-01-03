/*!
 * \file 
 * \brief  combination.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

static map<char, string> mapping({
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jkl"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"},
	{'1', ""},
	{'0', ""}
});

vector<string> phoneHelper(vector<string>& groups) {
	vector<string> result;

 	if (groups.size() == 1) {
 		for (auto c = groups[0].begin(); c != groups[0].end(); c++) {
 			result.push_back(*c);
 		}
 		return result;
 	}

	vector<string> copy(groups.begin()+1, groups.end());
	vector<string> future = phoneHelper(copy);
 	for (auto &c : groups[0]) {

 		for (const auto &str : future) {
 			result.emplace_back(c + str);
 		}
 	}

 	return result;
}

vector<string> phoneStrings(string number) {

	vector<string> chars;
	for (auto c = number.begin(); c != number.end(); c++) {
		if (*c != '1' && *c != '0')
			chars.push_back(mapping[*c]);
	}

	vector<string> result = phoneHelper(chars);

	return result;
}

vector<vector<int>> subsetsWithSum(vector<int> &array, int sum) {
	vector<vector<int> > result;

	if (array.size() == 1) {
		for (int it : array) {
			if (it == sum)
				result.emplace(result.end(), vector<int>({it}));
		}
		return result;
	}

	typename vector<int>::iterator vectorIt;
	typename vector<vector<int>>::iterator nestedVectorIt;

	for (vectorIt = array.begin(); vectorIt != array.end(); ++vectorIt) {
		vector<int> copy;
		copy.insert(copy.end(), vectorIt + 1, array.end());

		vector<vector<int> > results;

		if (sum - *vectorIt)
			results = subsetsWithSum(copy, sum - *vectorIt);
		else
			results.emplace({});

		for (nestedVectorIt = results.begin(); nestedVectorIt != results.end();
				nestedVectorIt++) {
			vector<int> current;
			current.insert(current.end(), vectorIt, vectorIt + 1);
			current.insert(current.end(), nestedVectorIt->begin(),
					nestedVectorIt->end());
			result.insert(result.end(), current);
		}
	}

	return result;
}

