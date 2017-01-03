/*!
 * \file 
 * \brief  knapsack.cpp
 *
 * \date   Sep 9, 2013
 * \author Ruben Vereecken
 */

#include "intractability.h"

using namespace std;

// Based on the following:
// V[i, w] = max(V[i-1, w], V[i-1, w-wi] + vi)
// "Either you leave out item i, or you put it in your knapsack

int knapsack(int w, const ItemList& items) {
	vector<int> V(w + 1, 0);
	for (int i = 0; i < items.size(); ++i) {
		for (int j = w; j >= items[i].first; --j)
			V[j] = max(V[j], V[j - items[i].first] + items[i].second);
	}
	return V[w];
}

