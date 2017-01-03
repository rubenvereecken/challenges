/*!
 * \file 
 * \brief  checkBST.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "binarySearchTrees.h"

template <typename T>
bool isBST(BTNodePtr<T> root) {
	BTNodePtr<T> current = root;

	if (root->left) {
		if (root->left->data <= root->data)
			return isBST(root->left);
		else
			return false;
	}

	if (root->right) {
		if (root->right->data >= root->data)
			return isBST(root->right);
		else
			return false;
	}

	return true;
}

template bool isBST(BTNodePtr<int>);
