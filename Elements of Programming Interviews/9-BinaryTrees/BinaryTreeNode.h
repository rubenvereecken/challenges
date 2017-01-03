/*!
 * \file 
 * \brief  BinaryTreeNode.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef BINARYTREENODE_H_
#define BINARYTREENODE_H_

#include <memory>
#include <iostream>
#include "helper.h"
using namespace std;

template <typename T>
class BinaryTreeNode;

template <typename T>
using BTNode = BinaryTreeNode<T>;

template <typename T>
using BTNodePtr = std::shared_ptr<BTNode<T> >;

template <typename T>
class BinaryTreeNode {
public:
	BinaryTreeNode();
	BinaryTreeNode(T);
	virtual ~BinaryTreeNode();

	int getHeight();

	// 9.4
	bool isLocked();
	bool lock();
	void unlock();

	// 9.12
	int getDepth();
	BTNodePtr<T> getLCA(BTNodePtr<T>, BTNodePtr<T>);

	T data;
	BTNodePtr<T> left;
	BTNodePtr<T> right;

	BTNodePtr<T> parent;

	// Used for finding the k-th successor in-order
	// Size of subtree rooted at this, including this
	int size;

private:
	// Used for locking
	bool _lock;
};

template <typename T>
ostream& operator<<(ostream& out, BTNodePtr<T> ptr) {
	out << ptr->data;
	return out;
}

#endif /* BINARYTREENODE_H_ */
