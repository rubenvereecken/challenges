/*!
 * \file 
 * \brief  graphs.h
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#ifndef GRAPHS_H_
#define GRAPHS_H_

#include <iostream>
#include <vector>
using namespace std;

struct Coordinate;

// 16.1 Find path in maze
bool hasPath(const vector<vector<bool>> &maze, const Coordinate &start, const Coordinate &goal);


#endif /* GRAPHS_H_ */
