/*!
 * \file 
 * \brief  hashTableTests.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */


#include "gtest/gtest.h"
#include "hashTables.h"
using namespace std;

TEST(HashTableTest, anonymousLetter) {
	string letter("Sneaky");
	string text("Sneak de fishy goudvis");
	EXPECT_TRUE(letterWritableWithText(letter, text));
}

