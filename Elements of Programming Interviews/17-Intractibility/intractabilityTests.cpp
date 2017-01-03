/*!
 * \file 
 * \brief  intractabilityTests.cpp
 *
 * \date   Sep 9, 2013
 * \author Ruben Vereecken
 */


#include "gtest/gtest.h"
#include "intractability.h"
#include "helper.h"
#include <iostream>
using namespace std;

void printSudoku(const Sudoku& sudoku, ostream& out=cout) {
	for (int y = 0; y < 9; ++y) {
		for (int x = 0; x < 9; ++x) {
			out << sudoku[x][y] << ' ';
		}
		out << '\n';
	}
}

TEST(IntractabilityTest, Sudoku) {
	Sudoku sudoku{{
		{{0, 0, 5, 0, 0, 7, 0, 4, 3}},
		{{7, 0, 0, 0, 4, 1, 8, 2, 0}},
		{{4, 1, 0, 0, 0, 0, 0, 0, 7}},
		{{0, 0, 0, 0, 2, 0, 9, 0, 8}},
		{{8, 3, 0, 0, 7, 0, 0, 5, 1}},
		{{2, 0, 1, 0, 9, 0, 0, 0, 0}},
		{{3, 0, 0, 0, 0, 0, 0, 6, 9}},
		{{0, 7, 4, 5, 6, 0, 0, 0, 2}},
		{{5, 9, 0, 2, 0, 0, 7, 0, 0}}
	}};
	EXPECT_TRUE(solveSudoku(sudoku));
}

TEST(IntractabilityTest, Collatz) {
	EXPECT_TRUE(checkCollatz(10));
}
