/*!
 * \file 
 * \brief  commonAncestor.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

/*
 * Get Lowest Common Ancestor with space O(1) and time O(h).
 * Returns null if nodes do not belong to same BT.
 */
template <typename T>
BTNodePtr<T> BinaryTreeNode<T>::getLCA(BTNodePtr<T> a, BTNodePtr<T> b) {
	int d_a = a->getDepth();
	int d_b = b->getDepth();
	int d_diff = abs(d_a - d_b);

	BTNodePtr<T> deepest = (d_a > d_b) ? a : b;
	BTNodePtr<T> other   = (d_a > d_b) ? b : a;

	while (d_diff) {
		deepest = deepest->parent;
		d_diff--;
	}

	while (deepest && other) {
		if (deepest == other)
			return deepest;
		deepest = deepest->parent;
		other = other->parent;
	}

	return BTNodePtr<T>(nullptr);
}


