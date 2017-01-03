/*!
 * \file
 * \brief  GlassDoorTests.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "gtest/gtest.h"
#include "GlassDoor.h"
#include <iostream>
using namespace std;

TEST(GlassDoorTest, skylineTest) {
	vector<triplet> triplets ({
		{{1, 11, 5}},
		{{2, 6, 7}},
		{{3, 13, 9}},
		{{12, 7, 16}},
		{{14, 3, 25}},
		{{19, 18, 22}},
		{{23, 13, 29}},
		{{24, 4, 28}}
	});

	vector<int> skyline = makeSkyline(triplets);
	vector<int> expected = {1, 11, 3, 13, 9, 0, 12, 7, 16, 3, 19, 18, 22, 3, 23, 13, 29, 0};

	EXPECT_EQ(skyline, expected);
}

TEST(GlassDoorTest, sumBinaryTest) {
	string a = "111";
	string b = "101";
	string c = "10000";
	string resultAB = sumBinary(a, b);
	string resultBC = sumBinary(b, c);

	EXPECT_EQ(resultAB, "1100");
	EXPECT_EQ(resultBC, "10101");
}

TEST(GlassDoorTest, tripletsSumTest) {
	vector<int> S = {-1, 0, 1, 2, -1, -4};
	vector<triplet> result = tripletsToZero(S);
}

TEST(GlassDoorTest, lookAndSayTest) {
	string looksay1 = nextLookAndSay("11");
	string looksay2 = nextLookAndSay("1211");

	EXPECT_EQ(looksay1, "21");
	EXPECT_EQ(looksay2, "111221");
}

TEST(GlassDoorTest, textSearchTest) {
	// First of all, check failure function
	vector<int> failure = failureFunction("abacab");
	vector<int> expected = {0, 0, 1, 0, 1, 2};

	EXPECT_EQ(failure, expected);

	string text("Alice went on an lonelong adventure in the chocolate factory");

	EXPECT_EQ(find(text, "horror"), -1);
	EXPECT_EQ(find(text, "lonelong"), 17);
	EXPECT_EQ(find(text, "lonelongs"), -1);
}

TEST(GlassDoorTest, regexTest) {
	EXPECT_TRUE(matches("aaabc", "aaabc"));
	EXPECT_TRUE(matches("aanbc", "aa.bc"));
	EXPECT_TRUE(matches("aaabc", "a*bc"));
	EXPECT_FALSE(matches("oranje", "oranj*"));
}

TEST(GlassDoorTest, romanTest) {
	EXPECT_EQ(17, fromRoman("XVII"));
	EXPECT_EQ(19, fromRoman("XIX"));
	EXPECT_EQ(1910, fromRoman("MCMX"));
}

TEST(GlassDoorTest, sqrtTest) {
	EXPECT_DOUBLE_EQ(11, sqrt(121));
	EXPECT_DOUBLE_EQ(11, sqrt2(121));
}

TEST(GlassDoorTest, powerTest) {
	EXPECT_DOUBLE_EQ(131072, powInt(2, 17));
	EXPECT_DOUBLE_EQ(0.125, powInt(2, -3));
}

TEST(GlassDoorTest, combinationTest) {
	vector<int> array ({1, 2, 3, -6, -5, 4, 2, -2});
	vector<vector<int> > result = subsetsWithSum(array, 1);

	vector<vector<int> > expected ({
		{1},
		{2, 3, -6, 4, -2},
		{2, 3, -6, 2},
		{2, -5, 4},
		{3, -6, 4},
		{3, -2},
		{-5, 4, 2}
	});

	vector<string> possible = phoneStrings("234");

	EXPECT_EQ(result, expected);
}

TEST(GlassDoorTest, subStringTest) {
	EXPECT_EQ(longestCommon("banana", "nana"), "nana");
	EXPECT_EQ(longestCommon("ali baba", "banana"), "ba");
}

TEST(GlassDoorTest, maxSubTest) {
	vector<int> a ({3, 5, -2, 51});
	vector<int> b ({1, -1, 2, 3, 4});

	EXPECT_EQ(maxSubArray(a), make_pair(0, 3));
	EXPECT_EQ(maxSubArray(b), make_pair(2, 4));
}

TEST(GlassDoorTest, expressionTest) {
	string infix1 = "12 + 5 * (1 - 3)";
	string postfix1 = inToPost(infix1);

	EXPECT_EQ(evaluatePost(postfix1, 0), 2);

	string equation = "5*x = 4*x - 1";
	EXPECT_EQ(findX(equation), -1);
}

TEST(GlassDoorTest, dutchFlagTest) {
	vector<int> a({ 2, 1, 0, 0, 2, 1, 1, 0, 2 });
	dutchFlag(a);
	vector<int> expected({0, 0, 0, 1, 1, 1, 2, 2, 2});

	EXPECT_EQ(a, expected);
}
