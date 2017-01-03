/*!
 * \file 
 * \brief  intractibility.h
 *
 * \date   Sep 9, 2013
 * \author Ruben Vereecken
 */

#ifndef INTRACTIBILITY_H_
#define INTRACTIBILITY_H_

#include <vector>
#include <map>
#include <array>

using namespace std;

// 17.2 Knapsack
typedef pair<int, int> Item;
typedef vector<Item> ItemList;
int knapsack(int w, const ItemList& items);

// 17.8 Sudoku
typedef array<array<int, 9>, 9> Sudoku;
bool solveSudoku(Sudoku& sudoku);

// 17.2 Collatz
bool checkCollatz (int n);

#endif /* INTRACTIBILITY_H_ */
