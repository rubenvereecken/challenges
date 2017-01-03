/*!
 * \file 
 * \brief  BinarySearchTree.h
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include "BinaryTreeNode.h"

template <typename T>
class BinarySearchTree {
public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	BTNodePtr<T> root;
};

#endif /* BINARYSEARCHTREE_H_ */
