/*!
 * \file 
 * \brief  VI.XIV_sudoku_checker.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include <map>
#include <vector>
using namespace std;

map<int, int> digitCount;

bool isSudokuValid(int sudoku[9][9]) {
	// Check rows
	for (int i = 0; i < 9; i++) {
		vector<bool> isPresent(9, false);
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] && isPresent[sudoku[i][j]])
				return false;
			else
				isPresent[sudoku[i][j]] = true;
		}
	}

	// Check columns
	for (int i = 0; i < 9; i++) {
		vector<bool> isPresent(9, false);
		for (int j = 0; j < 9; j++) {
			if (sudoku[j][i] && isPresent[sudoku[j][i]])
				return false;
			else
				isPresent[sudoku[j][i]] = true;
		}
	}

	// Check 'regions'
	for (int i = 0; i < 9; i++) {
		vector<vector<bool> > isPresent(9, vector<bool>(9, false));
		for (int j = 0; j < 9; j++) {
			// Map coordinates of a cell to a certain region
			int regionNr = (i / 9) + (j / 9) * 3;
			if (sudoku[i][j] && isPresent[regionNr][sudoku[i][j]])
				return false;
			else
				isPresent[regionNr][sudoku[i][j]] = true;
		}
	}

	return true;
}

