/*!
 * \file 
 * \brief  successor.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

using namespace std;

template<typename T>
BTNodePtr<T> findSuccessor(BTNodePtr<T> root) {
	BTNodePtr<T> current;
	BTNodePtr<T> prev;

	if (!root)
		return nullptr;

	if (!root->left && !root->right) {
		current = root;

		do {
			prev = current;
			current = current->parent;
		} while (current && prev == current->right);

		return current;
	} else if (root->right) {
		current = root->right;
		while (current->left) {
			current = current->left;
		}
		return current;
	} else
		return nullptr;
}

template<typename T>
BTNodePtr<T> findKSuccessor(BTNodePtr<T> root, int k) {
	BTNodePtr<T> current;
	BTNodePtr<T> prev;

	if (k == 0 || !root)
		return root;

	if (!root->left && !root->right) {
		current = root;

		if (current->parent && current->parent->size >= k) {
			do {
				prev = current;
				current = current->parent;
			} while (current && prev == current->right);
			return findKSuccessor(current, k - 1);
		} else
			return nullptr;
	} else if (root->right) {
		if (current->right && current->right->size >= k) {
			current = root->right;

			if (current->left && current->left->size <= k - 1)
				return findKSuccessor(current, k - current->left->size - 1);

			while (current->left) {
				current = current->left;
			}
			return findKSuccessor(current, k - 1);
		}
		else
			return nullptr;
	} else
		return nullptr;
}

template BTNodePtr<char> findSuccessor(BTNodePtr<char> root);
template BTNodePtr<char> findKSuccessor(BTNodePtr<char> root, int);
