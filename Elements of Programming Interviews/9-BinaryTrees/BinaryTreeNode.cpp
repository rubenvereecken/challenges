/*!
 * \file 
 * \brief  BinaryTreeNode.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "BinaryTreeNode.h"
#include <queue>

using namespace std;

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode() {

}

template<typename T>
BinaryTreeNode<T>::BinaryTreeNode(T data) :
		data(data) {
}

template<typename T>
bool BinaryTreeNode<T>::isLocked() {
	return _lock;
}

template<typename T>
bool BinaryTreeNode<T>::lock() {
	bool adjacentLock = false;
	BTNodePtr<T> current;

	// Check ancestors
	current = parent;
	while (!adjacentLock && current) {
		adjacentLock = current->isLocked();
		current = current->parent;
	}

	queue<BTNodePtr<T>> Q;
	Q.push(BTNodePtr<T>(this));
	// Check descendants
	while (!adjacentLock && !Q.empty()) {
		current = Q.front();
		Q.pop();
		if (current) {
			Q.push(current->left);
			Q.push(current->right);
			adjacentLock = current->isLocked();
		}
	}

	if (adjacentLock)
		return false;
	else {
		return _lock = true;
	}
}

template<typename T>
void BinaryTreeNode<T>::unlock() {
	_lock = false;
}

template<typename T>
int BinaryTreeNode<T>::getDepth() {
	int depth = 0;
	BTNodePtr<T> current = BTNodePtr<T>(this);
	while (current) {
		depth++;
		current = current->parent;
	}
	return depth;
}

template<typename T>
BinaryTreeNode<T>::~BinaryTreeNode() {
}

template class BinaryTreeNode<int> ;
template class BinaryTreeNode<char> ;
