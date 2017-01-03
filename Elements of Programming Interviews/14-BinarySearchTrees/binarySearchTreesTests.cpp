/*!
 * \file 
 * \brief  binarySearchTreesTests.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */


#include "gtest/gtest.h"
#include "binarySearchTrees.h"
#include "helper.h"
using namespace std;

TEST(BSTTest, isBST) {
	BTNodePtr<int> root(new BTNode<int>(10));
	BTNodePtr<int> a(new BTNode<int>(5));
	BTNodePtr<int> b(new BTNode<int>(15));
	root->left = a;
	root->right = b;

	EXPECT_TRUE(isBST(root));

	BTNodePtr<int> c(new BTNode<int>(7));
	BTNodePtr<int> d(new BTNode<int>(13));
	a->right = c;
	b->left = d;

	EXPECT_TRUE(isBST(root));
}

TEST(BSTTest, findNodeByKey) {
	BTNodePtr<int> root(new BTNode<int>(10));
	BTNodePtr<int> a(new BTNode<int>(5));
	BTNodePtr<int> b(new BTNode<int>(15));
	root->left = a;
	root->right = b;

	EXPECT_TRUE(findNodeByKey(root, 17) == nullptr);
	EXPECT_TRUE(findNodeByKey(root, 0) == nullptr);
	EXPECT_TRUE(findNodeByKey(root, 15) == b);
}

TEST(BSTTest, findSuccessor) {
	BTNodePtr<int> root(new BTNode<int>(10));
	BTNodePtr<int> a(new BTNode<int>(5));
	BTNodePtr<int> b(new BTNode<int>(15));
	BTNodePtr<int> c(new BTNode<int>(20));
	BTNodePtr<int> d(new BTNode<int>(25));
	root->left = a;
	root->right = b;
	b->right = c;
	c->right = d;

	EXPECT_TRUE(findSuccessor(root) == a);
	EXPECT_TRUE(findSuccessor(c) == d);
	EXPECT_TRUE(findSuccessor(d) == nullptr);
}

TEST(BSTTest, createBST) {
	vector<int> a({1, 2});
	auto it = a.begin();
}

