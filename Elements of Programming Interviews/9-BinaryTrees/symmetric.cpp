/*!
 * \file 
 * \brief  symmetric.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

using namespace std;

template<typename T>
bool symmetricHelper(BTNodePtr<T> first, BTNodePtr<T> second) {
	if (!(first || second))
		return true;
	else if (first && second && first->data == second->data) {
		return symmetricHelper(first->left, second->right)
				&& symmetricHelper(first->right, second->left);
	}
	else
		return false;
}

template<typename T>
bool isSymmetric(BTNodePtr<T> root) {
	return symmetricHelper(root->left, root->right);
}

template bool isSymmetric(BTNodePtr<char> root);
