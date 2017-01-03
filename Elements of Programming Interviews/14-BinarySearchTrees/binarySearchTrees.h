/*!
 * \file 
 * \brief  binarySearchTrees.h
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#ifndef BINARYSEARCHTREES_H_
#define BINARYSEARCHTREES_H_

#include "BinarySearchTree.h"
#include <vector>

using namespace std;

// 14.1
template<typename T>
bool isBST(BTNodePtr<T> root);

// 14.5
template<typename T>
BTNodePtr<T> findNodeByKey(BTNodePtr<T> root, T key);
template<typename T>
BTNodePtr<T> findSuccessor(BTNodePtr<T> root);
template<typename T>
T nextKey(BTNodePtr<T> root, T key);

// 14.12
template<typename T>
BTNodePtr<T> createBST(const vector<T>&);

#endif /* BINARYSEARCHTREES_H_ */
