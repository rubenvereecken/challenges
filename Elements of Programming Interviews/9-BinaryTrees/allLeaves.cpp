/*!
 * \file 
 * \brief  allLeaves.cpp
 *
 * \date   Oct 14, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

template<typename T>
void fetchAllLeaves(BTNodePtr<T> root, vector<T>& leaves) {
	if (!root) return;
	if (!(root->left || root->right)) {
		leaves.push_back(root->data);
		return;
	}
	else {
		fetchAllLeaves(root->left, leaves);
		fetchAllLeaves(root->right, leaves);
	}
}


