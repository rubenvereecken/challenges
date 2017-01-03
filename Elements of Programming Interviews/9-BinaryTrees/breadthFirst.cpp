/*!
 * \file 
 * \brief  breathFirst.cpp
 *
 * \date   Sep 11, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"

using namespace std;

template<typename T>
vector<T> breadthFirst(BTNodePtr<T> root) {
	queue<BTNodePtr<T>> Q;
	vector<T> result;
	Q.push(root);

	while (!Q.empty()) {
		BTNodePtr<T> current = Q.front();
		Q.pop();
		result.push_back(current->data);

		if (current->left)
			Q.push(current->left);
		if (current->right)
			Q.push(current->right);
	}

	return result;
}

template<typename T>
vector<vector<T>> breadthFirstPerLevel(BTNodePtr<T> root) {
	queue<pair<BTNodePtr<T>, int>> Q;
	vector<vector<T> > result;
	Q.push(make_pair(root, 0));

	while (!Q.empty()) {
		pair<BTNodePtr<T>, int> currentNode = Q.front();
		BTNodePtr<T> current = currentNode.first;
		int level = currentNode.second;
		Q.pop();

		if (level >= result.size()) {
			vector<T> row( { current->data });
			result.push_back(row);
		} else {
			result[level].push_back(current->data);
		}

		if (current->left)
			Q.push(make_pair(current->left, level + 1));
		if (current->right)
			Q.push(make_pair(current->right, level + 1));
	}

	return result;
}

template vector<char> breadthFirst(BTNodePtr<char> root);
template vector<vector<char>> breadthFirstPerLevel(BTNodePtr<char> root);
