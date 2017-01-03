/*!
 * \file 
 * \brief  sudoku.cpp
 *
 * \date   Sep 9, 2013
 * \author Ruben Vereecken
 */

#include "intractability.h"
#include <iostream>

using namespace std;

bool solveSudoku(Sudoku& sudoku) {
	bool edited = false;

	for (unsigned int x = 0; x < sudoku.size(); ++x) {
		for (unsigned int y = 0; y < sudoku.size(); ++y) {
			if (!sudoku[x][y]) {
				vector<bool> found(10, false);

				// Check current 3x3 square
				int topLeftX = (x / 3) * 3;
				int topLeftY = (y / 3) * 3;
				for (int i = topLeftX; i < topLeftX + 3; ++i) {
					for (int j = topLeftY; j < topLeftY + 3; ++j) {
						if (sudoku[i][j])
							found[sudoku[i][j]] = true;
					}
				}

				// Check current row
				for (unsigned int i = 0; i < sudoku.size(); ++i) {
					if (sudoku[i][y])
						found[sudoku[i][y]] = true;
				}
				// Check current column
				for (unsigned int j = 0; j < sudoku.size(); ++j) {
					if (sudoku[x][j])
						found[sudoku[x][j]] = true;
				}

//				std::cout << '(' << x << ", " << y << ") : ";
//				for (auto bleh : found)
//					std::cout << bleh << ' ';
//				std::cout << '\n';

				short unique = 0;

				for (int i = 1; i <= 9; ++i) {
					if (!unique && !found[i]) unique = i;
					else if (unique && !found[i]) {
						unique = 0;
						break;
					}
				}

				if (unique) {
					sudoku[x][y] = unique;
					edited = true;
				}
			}
		}
	}

	bool completed = true;
	for (unsigned int x  = 0; x < sudoku.size(); ++x) {
		for (unsigned int y = 0; y < sudoku.size(); ++y) {
			if (!sudoku[x][y]) {
				completed = false;
				break;
			}
		}
		if (!completed) break;
	}

	if (!completed && !edited) // If not completed and nothing changed, it's impossible
		return false;
	else if (!completed && edited) // If not completed but changed, recurse
		return solveSudoku(sudoku);
	else // If completed
		return true;
}

