/*!
 * \file 
 * \brief  reconstruct.cpp
 *
 * \date   Oct 14, 2013
 * \author Ruben Vereecken
 */

#include "binaryTrees.h"


template <typename T>
BTNodePtr<T> preHelper(vector<T>& pre, int preS, int preE, vector<T>& in, int inS, int inE) {
	if (preS >= preE || inS >= inE)
		return nullptr;

	BTNodePtr<T> root = BTNodePtr<T>(new BTNode<T>(pre[preS]));
	int rootIndex;

	for (int i = inS; i < inE; ++i) {
		if (in[i] == root->data) {
			rootIndex = i;
			break;
		}
	}

	root->left = preHelper(pre, preS + 1, preS + (rootIndex - inS) + 1, in, inS, rootIndex);
	root->right = preHelper(pre, preS + (rootIndex - inS) + 1, preE, in, rootIndex + 1, inE);

	return root;
}

template <typename T>
BTNodePtr<T> postHelper(vector<T>& post, int postS, int postE, vector<T>& in, int inS, int inE) {
	if (postS >= postE || inS >= inE)
		return nullptr;

	BTNodePtr<T> root = BTNodePtr<T>(new BTNode<T>(post[postE - 1]));
	int rootIndex;

	for (int i = inS; i < inE; ++i) {
		if (in[i] == root->data) {
			rootIndex = i;
			break;
		}
	}

	root->left = postHelper(post, postS, postS + (rootIndex - inS), in, inS, rootIndex);
	root->right = postHelper(post, postS + (rootIndex - inS), postE - 1, in, rootIndex + 1, inE);

	return root;
}

template <typename T>
BTNodePtr<T> reconstructFromPre(vector<T>& pre, vector<T>& in) {
	return preHelper(pre, 0, pre.size(), in, 0, in.size());
}

template <typename T>
BTNodePtr<T> reconstructFromPost(vector<T>& post, vector<T>& in) {
	return postHelper(post, 0, post.size(), in, 0, in.size());
}

template BTNodePtr<char> reconstructFromPre(vector<char>& pre, vector<char>& in);
template BTNodePtr<char> reconstructFromPost(vector<char>& post, vector<char>& in);
