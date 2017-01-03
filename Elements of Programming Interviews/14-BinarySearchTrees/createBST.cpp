/*!
 * \file 
 * \brief  createBST.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "binarySearchTrees.h"


// Conserves the BST requirements
template <typename T>
void insert(BTNodePtr<T> root, BTNodePtr<T> newNode) {
	if (newNode->data < root->data) {
		if (newNode->left)
			insert(root->left, newNode);
		else
			root->left = newNode;
	}
	else {
		if (newNode->right)
			insert(root->right, newNode);
		else
			root->right = newNode;
	}
}

// Creates BST from an array of unique numbers
// Returns the root
// Optimisations can be made if the median is picked to be root
template <typename T>
BTNodePtr<T> createBST(const vector<T>& array) {
	if (array.empty())
		return nullptr;

	auto currentIt = array.begin();
	BTNodePtr<T> root = BTNodePtr<T>(new BTNode<T>(*currentIt++));

	for (; currentIt != array.end(); currentIt++) {
		insert(root, BTNodePtr<T>(new BTNode<T>(*currentIt)));
	}

	return root;
}


