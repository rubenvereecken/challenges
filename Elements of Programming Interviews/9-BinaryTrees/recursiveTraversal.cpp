/*!
 * \file 
 * \brief  recursiveTraversal.cpp
 *
 * \date   Sep 11, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include "binaryTrees.h"

using namespace std;

template<typename T>
void inOrderRecursive(BTNodePtr<T> root, vector<T>& array) {
	if (root->left) {
		inOrderRecursive(root->left, array);
	}
	array.push_back(root->data);
	if (root->right) {
		inOrderRecursive(root->right, array);
	}
}

template<typename T>
void postOrderRecursive(BTNodePtr<T> root, vector<T>& array) {
	if (root->left) {
		postOrderRecursive(root->left, array);
	}
	if (root->right) {
		postOrderRecursive(root->right, array);
	}
	array.push_back(root->data);
}

template<typename T>
void preOrderRecursive(BTNodePtr<T> root, vector<T>& array) {
	array.push_back(root->data);
	if (root->left) {
		preOrderRecursive(root->left, array);
	}
	if (root->right) {
		preOrderRecursive(root->right, array);
	}
}

template void preOrderRecursive(BTNodePtr<char> root, vector<char>& array);
template void inOrderRecursive(BTNodePtr<char> root, vector<char>& array);
template void postOrderRecursive(BTNodePtr<char> root, vector<char>& array);
