/*!
 * \file 
 * \brief  sortingTests.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */


#include "gtest/gtest.h"
#include "sorting.h"
#include "helper.h"
using namespace std;

TEST(SortingTest, intersection) {
	vector<int> a({1, 2, 3, 6, 9});
	vector<int> b({3, 5, 6, 8, 10});
	vector<int> c({2, 3, 6, 9, 10, 11});
	vector<int> intersectionAB({3, 6});
	vector<int> intersectionAC({2, 3, 6, 9});

	vector<int> resultAB = intersectArrays(a, b);
	vector<int> resultAC = intersectArrays(a, c);

	EXPECT_TRUE(help::equalElements(intersectionAB, resultAB));
	EXPECT_TRUE(help::equalElements(intersectionAC, resultAC));
}


