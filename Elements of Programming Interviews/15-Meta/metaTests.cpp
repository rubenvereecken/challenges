/*!
 * \file 
 * \brief  metaTests.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "gtest/gtest.h"
#include "meta.h"
#include "helper.h"
using namespace std;

TEST(MetaTest, Levenshtein) {
	string a("snavels");
	string b("navel");

	EXPECT_TRUE(levenshteinDistance(a, b) == 2);
}
