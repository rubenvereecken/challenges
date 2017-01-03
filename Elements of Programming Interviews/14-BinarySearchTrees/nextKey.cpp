/*!
 * \file 
 * \brief  nextKey.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "binarySearchTrees.h"

// Returns first encounter only;
// Returns null if not found.
template<typename T>
BTNodePtr<T> findNodeByKey(BTNodePtr<T> root, T key) {
	if (!root)
		return nullptr;

	if (key > root->data) {
		return findNodeByKey(root->right, key);
	} else if (key < root->data) {
		return findNodeByKey(root->left, key);
	} else
		return root;
}

template<typename T>
BTNodePtr<T> findSuccessor(BTNodePtr<T> root) {
	BTNodePtr<T> current = nullptr;

	if (current = root->right) {
		while (current) {
			if (current->left)
				current = current->left;
			else
				break;
		}
	} else {
		current = root;
		while (current) {
			if (current->parent->left == current) {
				return current->parent;
			}
			else {
				current = current->parent;
			}
		}
	}

	return current;
}

template<typename T>
T nextKey(BTNodePtr<T> root, T key) {
	return findSuccessor(findNodeByKey(root, key))->data;
}

template BTNodePtr<int> findNodeByKey(BTNodePtr<int> root, int key);
template BTNodePtr<int> findSuccessor(BTNodePtr<int> root);
template int nextKey(BTNodePtr<int> root, int key);
