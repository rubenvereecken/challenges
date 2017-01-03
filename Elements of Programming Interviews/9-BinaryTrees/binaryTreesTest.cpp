/*!
 * \file 
 * \brief  binaryTreesTest.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "gtest/gtest.h"
#include "binaryTrees.h"
#include "helper.h"
#include <iostream>
using namespace std;

class BinaryTreeTest: public ::testing::Test {
protected:

	BTNodePtr<char> f;

	// Per-test-case set-up.
	// Called before the first test in this test case.
	// Can be omitted if not needed.
	static void SetUpTestCase() {
	}

	// Per-test-case tear-down.
	// Called after the last test in this test case.
	// Can be omitted if not needed.
	static void TearDownTestCase() {
	}

	// You can define per-test set-up and tear-down logic as usual.
	virtual void SetUp() {
		f.reset(new BTNode<char>('F'));

		BTNodePtr<char> a(new BTNode<char>('A'));
		BTNodePtr<char> b(new BTNode<char>('B'));
		BTNodePtr<char> c(new BTNode<char>('C'));
		BTNodePtr<char> d(new BTNode<char>('D'));
		BTNodePtr<char> e(new BTNode<char>('E'));
		BTNodePtr<char> g(new BTNode<char>('G'));
		BTNodePtr<char> h(new BTNode<char>('H'));
		BTNodePtr<char> i(new BTNode<char>('I'));

		f->left = b;
		f->right = g;
		b->parent = f;
		g->parent = f;

		b->left = a;
		b->right = d;
		a->parent = b;
		d->parent = b;

		d->left = c;
		d->right = e;
		c->parent = d;
		e->parent = d;

		g->right = i;
		i->parent = g;

		i->left = h;
		h->parent = i;
	}
	virtual void TearDown() {
	}

	// Some expensive resource shared by all tests.
//	static T* shared_resource_;
};

TEST_F(BinaryTreeTest, balancedTest) {
	BTNodePtr<char> s(new BTNode<char>('S'));
	f->right->left = s;

	EXPECT_TRUE(isBalanced(f));

	f->right->right->left->right = BTNodePtr<char>(new BTNode<char>('T'));

	EXPECT_FALSE(isBalanced(f));
}

TEST_F(BinaryTreeTest, kBalancedTest) {
	BTNodePtr<char> s(new BTNode<char>('S'));

	BTNodePtr<char> newRoot = isKBalanced(f, 2);

	EXPECT_FALSE(isBalanced(f));
}

TEST_F(BinaryTreeTest, iterativeTraversalTest) {
	vector<char> postorder = postOrderIterative(f);
	vector<char> inorder = inOrderIterative(f);
	vector<char> inorder2 = inOrderIterative(f);
	vector<char> preorder = preOrderIterative(f);

	vector<char> expectedPre( { 'F', 'B', 'A', 'D', 'C', 'E', 'G', 'I', 'H' });
	vector<char> expectedIn( { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' });
	vector<char> expectedPost( { 'A', 'C', 'E', 'D', 'B', 'H', 'I', 'G', 'F' });

	EXPECT_EQ(postorder, expectedPost);
	EXPECT_EQ(inorder, expectedIn);
	EXPECT_EQ(inorder2, expectedIn);
	EXPECT_EQ(preorder, expectedPre);
}

TEST_F(BinaryTreeTest, recursiveTraversalTest) {

	vector<char> preorder;
	preOrderRecursive(f, preorder);
	vector<char> inorder;
	inOrderRecursive(f, inorder);
	vector<char> postorder;
	postOrderRecursive(f, postorder);

	vector<char> expectedPre( { 'F', 'B', 'A', 'D', 'C', 'E', 'G', 'I', 'H' });
	vector<char> expectedIn( { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I' });
	vector<char> expectedPost( { 'A', 'C', 'E', 'D', 'B', 'H', 'I', 'G', 'F' });

	EXPECT_EQ(preorder, expectedPre);
	EXPECT_EQ(inorder, expectedIn);
	EXPECT_EQ(postorder, expectedPost);
}

TEST_F(BinaryTreeTest, breadFirstTest) {
	vector<char> result = breadthFirst(f);
	vector<char> expected = { 'F', 'B', 'G', 'A', 'D', 'I', 'C', 'E', 'H' };

	EXPECT_EQ(result, expected);

	vector<vector<char> > perLevel = breadthFirstPerLevel(f);
	vector<vector<char>> expectedPerLevel({
		{'F'},
		{'B', 'G'},
		{'A', 'D', 'I'},
		{'C', 'E', 'H'}
	});

	EXPECT_EQ(perLevel, expectedPerLevel);
}

TEST_F(BinaryTreeTest, symmetricTest) {
	BTNodePtr<char> a(new BTNode<char>('a'));
	BTNodePtr<char> b(new BTNode<char>('b'));
	BTNodePtr<char> e(new BTNode<char>('b'));
	BTNodePtr<char> c(new BTNode<char>('c'));
	BTNodePtr<char> f(new BTNode<char>('c'));
	BTNodePtr<char> d(new BTNode<char>('d'));
	BTNodePtr<char> g(new BTNode<char>('d'));

	a->left = b;
	a->right = e;

	b->right = c;
	c->right = d;

	e->left = f;
	f->left = g;

	EXPECT_TRUE(isSymmetric(a));
}

TEST_F(BinaryTreeTest, successorTest) {
	BTNodePtr<char> g = findSuccessor(f);
	BTNodePtr<char> c = findSuccessor(f->left);

	EXPECT_EQ(g->data, 'G');
	EXPECT_EQ(c->data, 'C');
}

TEST_F(BinaryTreeTest, predecessorTest) {
	BTNodePtr<char> e = findPredecessor(f);
	BTNodePtr<char> h = findPredecessor(f->right->right);
	BTNodePtr<char> b = findPredecessor(f->left->right->left);

	EXPECT_EQ(e->data, 'E');
	EXPECT_EQ(h->data, 'H');
	EXPECT_EQ(b->data, 'B');
}

TEST_F(BinaryTreeTest, allPathsTest) {
	vector<vector<char> > all = allPaths(f);

	vector<vector<char> > expected = {
		{'F', 'B', 'A'},
		{'F', 'B', 'D', 'C'},
		{'F', 'B', 'D', 'E'},
		{'F', 'G', 'I', 'H'}
	};

	EXPECT_EQ(all, expected);
}

TEST_F(BinaryTreeTest, reconstructionTest) {
	vector<char> inorder;
	vector<char> preorder;
	vector<char> postorder;
	inOrderRecursive(f, inorder);
	preOrderRecursive(f, preorder);
	postOrderRecursive(f, postorder);

	BTNodePtr<char> root1 = reconstructFromPre(preorder, inorder);
	BTNodePtr<char> root2 = reconstructFromPost(postorder, inorder);

	vector<char> inorderResult;
	vector<char> preorderResult;
	vector<char> postorderResult;
	inOrderRecursive(root1, inorderResult);
	preOrderRecursive(root1, preorderResult);
	postOrderRecursive(root2, postorderResult);

	EXPECT_EQ(inorder, inorderResult);
	EXPECT_EQ(preorder, preorderResult);
	EXPECT_EQ(postorder, postorderResult);
}
