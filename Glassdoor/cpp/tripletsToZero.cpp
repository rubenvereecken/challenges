/*!
 * \file 
 * \brief  tripletsToZero.cpp
 *
 * \date   Sep 11, 2013
 * \author Ruben Vereecken
 */


#include "GlassDoor.h"

using namespace std;

vector<triplet> tripletsToZero(const vector<int> &array) {
	vector<triplet> results;
	vector<int> copy(array);
	sort(copy.begin(), copy.end());

	for (int i = 0; i < copy.size() - 2; i++) {
		if (copy[i] > 0) break;
		int j = i + 1;
		int k = copy.size() - 1;
		while (j < k) {
			int sum = copy[i] + copy[j] + copy[k];
			if (sum < 0) {
				++j;
			}
			else if (sum > 0) {
				--k;
			}
			else {
				results.push_back({{copy[i], copy[j], copy[k]}});
				++j;
				--k;
			}
		}
	}

	return results;
}
