/*!
 * \file 
 * \brief  helpTests.cpp
 *
 * \date   Sep 9, 2013
 * \author Ruben Vereecken
 */

#include "gtest/gtest.h"
#include "helper.h"
#include <iostream>
using namespace std;

TEST(HelpTest, Permutation) {
	vector<int> a({1, 2, 3});
	vector<vector<int> > permutated = help::permutate(a);
	vector<vector<int> > expected ({
		{1, 2, 3},
		{1, 3, 2},
		{2, 1, 3},
		{2, 3, 1},
		{3, 1, 2},
		{3, 2, 1}
	});

	vector<vector<int> > variated = help::permutate(a, 2);
	vector<vector<int> > expectedVariation ({
		{1, 2},
		{1, 3},
		{2, 1},
		{2, 3},
		{3, 1},
		{3, 2}
	});


	EXPECT_EQ(permutated, expected);
	EXPECT_EQ(variated, expectedVariation);
}

TEST(HelpTest, Combination) {
	vector<int> a({1, 2, 3});

	vector<vector<int> > combinations = help::combine(a, 2);
	vector<vector<int> > expected ({
		{1, 2},
		{1, 3},
		{2, 3}
	});

	EXPECT_TRUE(combinations == expected);
}
