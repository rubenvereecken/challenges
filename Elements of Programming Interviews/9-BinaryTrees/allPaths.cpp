/*!
 * \file 
 * \brief  allPaths.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

using namespace std;

template <typename T>
vector<vector<T>> allPaths(BTNodePtr<T> root) {
	BTNodePtr<T> current = root;

	if (!current->left && !current->right) {
		return vector<vector<T> >({{root->data}});
	}

	else {
		vector<vector<T> > all;
		vector<vector<T> > leftPaths;
		vector<vector<T> > rightPaths;
		if (current->left)
			leftPaths = allPaths(current->left);
		if (current->right)
			rightPaths = allPaths(current->right);

		all.insert(all.end(), leftPaths.begin(), leftPaths.end());
		all.insert(all.end(), rightPaths.begin(), rightPaths.end());

		for (auto &path : all) {
			path.insert(path.begin(), current->data);
		}
		return all;
	}


}

template vector<vector<char>> allPaths(BTNodePtr<char> root);
