/*!
 * \file 
 * \brief  predecessor.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

using namespace std;

template<typename T>
BTNodePtr<T> findPredecessor(BTNodePtr<T> root) {
	if (!root)
		return nullptr;

	BTNodePtr<T> current = root;
	BTNodePtr<T> prev;

	if (current->left) {
		current = current->left;
		while (current->right) {
			current = current->right;
		}
		return current;
	}
	else {
		if (current->parent) {
			prev = current;
			current = current->parent;
			while (current && prev == current->left) {
				prev = current;
				current = current->parent;
			}
			return current;
		}
		else return nullptr;
	}
}

template BTNodePtr<char> findPredecessor(BTNodePtr<char> root);
