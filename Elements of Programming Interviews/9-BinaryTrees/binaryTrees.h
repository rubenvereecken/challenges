/*!
 * \file 
 * \brief  binaryTrees.h
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#ifndef BINARYTREES_H_
#define BINARYTREES_H_

#include <vector>
#include "BinaryTreeNode.h"
#include <queue>
#include <stack>
#include <map>

using namespace std;

// 9.1
template <typename T>
bool isBalanced(BTNodePtr<T> root);

// 9.2
template<typename T>
BTNodePtr<T> isKBalanced(BTNodePtr<T> root, int k);

// 9.3
template<typename T>
bool isSymmetric(BTNodePtr<T> root);

// 9.4 can be found in BinaryTreeNode.h

template <typename T>
vector<T> preOrderIterative(BTNodePtr<T> root);

// 9.5
template <typename T>
vector<T> inOrderIterative(BTNodePtr<T> root);
template<typename T>
vector<T> inOrderIterative2(BTNodePtr<T> root);

// 9.6 find next in-order successor
template<typename T>
BTNodePtr<T> findSuccessor(BTNodePtr<T> root);

//
template<typename T>
BTNodePtr<T> findPredecessor(BTNodePtr<T> root);

// 9.7 find k-th in-order successor with heuristic
template<typename T>
BTNodePtr<T> findKSuccessor(BTNodePtr<T> root, int k);

// 9.8 Reconstruct from traversal data
template<typename T>
BTNodePtr<T> reconstructFromPre(vector<T>& pre, vector<T>& in);
template <typename T>
BTNodePtr<T> reconstructFromPost(vector<T>& post, vector<T>& in);

// 9.10 Fetch leaves
template<typename T>
void fetchAllLeaves(BTNodePtr<T> root, vector<T>& leaves);

template <typename T>
vector<T> postOrderIterative(BTNodePtr<T> root);

template<typename T>
void preOrderRecursive(BTNodePtr<T> root, vector<T>& array);

template<typename T>
void inOrderRecursive(BTNodePtr<T> root, vector<T>& array);

template<typename T>
void postOrderRecursive(BTNodePtr<T> root, vector<T>& array);

template <typename T>
vector<T> breadthFirst(BTNodePtr<T> root);
template<typename T>
vector<vector<T>> breadthFirstPerLevel(BTNodePtr<T> root);

template <typename T>
vector<vector<T>> allPaths(BTNodePtr<T> root);

template<typename T>
vector<BTNodePtr<T>> longestPath (BTNodePtr<T> root);

#endif /* BINARYTREES_H_ */
