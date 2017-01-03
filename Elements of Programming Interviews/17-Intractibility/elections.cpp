/*!
 * \file 
 * \brief  elections.cpp
 *
 * \date   Oct 15, 2013
 * \author Ruben Vereecken
 */

#include "intractability.h"

bool isTiePossible(vector<int> electors) {
	int sum = 0;
	for (int elector : electors) {
		sum += elector;
	}
	if (sum & 1)
		return false;

	vector<vector<int> > combs(electors.size() + 1, vector<int>(sum / 2 + 1));
	combs[0][0] = 1;

	for (int i = 0; i < electors.size(); ++i) {
		for (int j = 0; j <= sum / 2; ++j) {
			combs[i + 1][j] = combs[i][j] + (j >= electors[i] ? combs[i][j - electors[i]] : 0);
		}
	}

	return combs[electors.size()][sum / 2];
}


