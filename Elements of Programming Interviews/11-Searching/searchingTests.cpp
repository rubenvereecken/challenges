/*!
 * \file 
 * \brief  searchingTests.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "gtest/gtest.h"
#include "searching.h"

using namespace std;

TEST(SearchingTest, indexIsValue) {
	static const int arr[] = { -5, 0, 2, 33, 44, 45, 66 };
	vector<int> vec1(arr, arr + sizeof(arr) / sizeof(arr[0]));

	int index = indexWithSameValue(vec1);

	EXPECT_EQ(index, 2);
}

TEST(SearchingTest, firstGreaterThan) {
	vector<int> a = {-14, -10, 2, 108, 108, 243, 285, 285, 401};

	int greaterThan101 = firstGreaterThan(a, 101);
	int greaterThan401 = firstGreaterThan(a, 401);

	EXPECT_EQ(greaterThan101, 3);
	EXPECT_EQ(greaterThan401, -1);
}

TEST(SearchingTest, findPairWithSum) {
	vector<int> a = { -49, 75, 103, -147, 164, -197, -238, 314, 348, -422 };

	pair<int, int> summing178 = findPairWithSum(a, 178);
	pair<int, int> summing100 = findPairWithSum(a, 100);
	pair<int, int> summing_108 = findPairWithSum(a, -108);

	EXPECT_EQ(summing178, make_pair(1, 2));
	EXPECT_EQ(summing100, make_pair(-1, -1));
	EXPECT_EQ(summing_108, make_pair(7, 9));
}

TEST(SearchingTest, findCyclicalIndex) {
	vector<int> a = { 378, 478, 550, 631, 103, 203, 220, 234, 279, 368 };
	vector<int> b = {-14, -10, 2, 108, 108, 243, 285, 285, 401};

	int indexA = findCyclicalIndex(a);
	int indexB = findCyclicalIndex(b);

	EXPECT_EQ(indexA, 4);
	EXPECT_EQ(indexB, 0);
}

TEST(SearchingTest, kthLargestElement) {
	static const int arr[] = { 5, 44, 2, 0, 46, 45, 66 };
	vector<int> vec1(arr, arr + sizeof(arr) / sizeof(arr[0]));

	int index = partition(vec1, 0, 6, 1);

	EXPECT_EQ(index, 3);
}


