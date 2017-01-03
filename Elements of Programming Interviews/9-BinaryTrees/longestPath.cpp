/*!
 * \file 
 * \brief  longestPath.cpp
 *
 * \date   Sep 16, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

using namespace std;

template<typename T>
vector<BTNodePtr<T>> longestPath (BTNodePtr<T> root) {
	if (!(root->left || root->right)) {
		return vector<BTNodePtr<T> > ({root});
	}
	else {
		vector<BTNodePtr<T> > left = longestPath(root->left);
		vector<BTNodePtr<T> > right = longestPath(root->right);
		vector<BTNodePtr<T> >& longest = (left.size() > right.size()) ? left : right;

		longest.emplace(longest.begin(), root);

		return longest;
	}
}

