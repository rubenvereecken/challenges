/*!
 * \file 
 * \brief  isBalanced.cpp
 *
 * \date   Sep 11, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"
using namespace std;

inline int abs(int a) {
	return (a < 0) ? -a : a;
}
inline int max(int a, int b) {
	return (a < b) ? b : a;
}

template<typename T>
int balancedHelper(BTNodePtr<T> root) {
	BTNodePtr<T> shorter;
	BTNodePtr<T> longer;

	if (!root) {
		return 0;
	}
	else {
		int heightLeft = balancedHelper(root->left);
		int heightRight = balancedHelper(root->right);
		if (abs(heightLeft - heightRight) > 1 || heightLeft == -1 || heightRight == -1) {
			return -1;
		} else
			return max(heightLeft, heightRight) + 1;
	}

}

template<typename T>
bool isBalanced(BTNodePtr<T> root) {
	return balancedHelper(root) != -1;
}

template<typename T>
int kBalancedHelper(BTNodePtr<T> root, BTNodePtr<T> &u, int k) {
	BTNodePtr<T> shorter;
	BTNodePtr<T> longer;

	if (!root) {
		return 0;
	}
	else {
		int heightLeft = kBalancedHelper(root->left, u, k);
		int heightRight = kBalancedHelper(root->right, u, k);
		if (heightLeft == -1 || heightRight == -1)
			return -1;
		else if (abs(heightLeft - heightRight) > k) {
			if (heightLeft > heightRight)
				u = root->left;
			else
				u = root->right;
			return -1;
		} else
			return max(heightLeft, heightRight) + 1;
	}

}

template<typename T>
BTNodePtr<T> isKBalanced(BTNodePtr<T> root, int k) {
	BTNodePtr<T> u = root;
	kBalancedHelper(root, u, k);
	return u;
}

template bool isBalanced(BTNodePtr<char> root);
template BTNodePtr<char> isKBalanced(BTNodePtr<char> root, int k);
