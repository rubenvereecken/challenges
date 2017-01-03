/*!
 * \file 
 * \brief  IX.V_inorder_traversal.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

// 9.5
// O(1) extra space required
// parent pointers allowed
#include <iostream>
#include "binaryTrees.h"

using namespace std;

template<typename T>
vector<T> postOrderIterative(BTNodePtr<T> root) {
	BTNodePtr<T> current = root;
	BTNodePtr<T> prev = nullptr;
	vector<T> inorder;

	while (current) {
		if (current->left && prev != current->left && prev != current->right) {
			prev = current;
			current = current->left;
		} else if (current->right && prev != current->right) {
			prev = current;
			current = current->right;
		} else {
			prev = current;
			inorder.push_back(current->data);
			current = current->parent;
		}

	}

	return inorder;
}

template<typename T>
vector<T> postOrderIterative2(BTNodePtr<T> root) {
	BTNodePtr<T> current = nullptr;
	BTNodePtr<T> prev = nullptr;
	stack<BTNodePtr<T>> S;
	vector<T> postorder;

	S.push(root);

	while (current = S.top()) {
		if (!prev || prev->left == current || prev->right == current) {
			prev = current;
			if (current->left) {
				S.push(current->left);
			}
			else if (current->right) {
				S.push(current->right);
			}
			else {
				postorder.push_back(current);
				S.pop();
			}
		}
		else if (prev == current->left) {
			prev = current;
			if (current->right) {
				S.push(current->right);
			}
			else {
				postorder.push_back(current);
				S.pop();
			}
		}
		else if (prev == current->right) {
			prev = current;
			postorder.push_back(current);
			S.pop();
		}
	}
}

// 9.5
template<typename T>
vector<T> inOrderIterative(BTNodePtr<T> root) {
	BTNodePtr<T> current = root;
	BTNodePtr<T> prev = nullptr;
	vector<T> inorder;

	while (current) {
		if (current->left && prev == current->left ||
			!(current->left || current->right) ||
			(prev == current->parent && !current->left && current->right)) {
			inorder.push_back(current->data);
		}

		if (current->left && prev != current->left && prev != current->right) {
			prev = current;
			current = current->left;
		} else if (current->right && prev != current->right) {
			prev = current;
			current = current->right;
		} else {
			prev = current;
			current = current->parent;
		}

	}

	return inorder;
}

template<typename T>
vector<T> inOrderIterative2(BTNodePtr<T> root) {
	BTNodePtr<T> current = root;
	stack<BTNodePtr<T>> S;
	vector<T> inorder;

	bool done = false;

	while (!done) {
		if (current) {
			S.push(current);
			current = current->left;
		}
		else {
			if (S.empty()) done = true;
			else {
				current = S.top();
				S.pop();
				inorder.push_back(current->data);
				current = current->right;
			}
		}
	}

	return inorder;
}

template<typename T>
vector<T> preOrderIterative(BTNodePtr<T> root) {
	BTNodePtr<T> current = root;
	BTNodePtr<T> prev = nullptr;
	vector<T> inorder;

	while (current) {
		if (!(prev == current->left || prev == current->right)) {
			inorder.push_back(current->data);
		}

		if (current->left && prev != current->left && prev != current->right) {
			prev = current;
			current = current->left;
		} else if (current->right && prev != current->right) {
			prev = current;
			current = current->right;
		} else {
			prev = current;
			current = current->parent;
		}

	}

	return inorder;
}

template<typename T>
vector<T> preOrderIterative2(BTNodePtr<T> root) {
	BTNodePtr<T> current = root;
	stack<BTNodePtr<T>> S;
	vector<T> result;

	S.push_back(current);

	while (!S.empty()) {
		current = S.top();
		S.pop();
		result.push_back(current);
		S.push_back(current->right);
		S.push_back(current->left);
	}

	return result;
}

template vector<char> postOrderIterative(
		BTNodePtr<char> root);
template vector<char> preOrderIterative(BTNodePtr<char> root);
template vector<char> inOrderIterative(BTNodePtr<char> root);
template vector<char> inOrderIterative2(BTNodePtr<char> root);
