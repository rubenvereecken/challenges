/*!
 * \file 
 * \brief  mazePath.cpp
 *
 * \date   Aug 15, 2013
 * \author Ruben Vereecken
 */

#include "graphs.h"
#include <queue>
using namespace std;

struct Coordinate {
	int x, y;

	Coordinate() : x(0), y(0) {}
	Coordinate(int x, int y) : x(x), y(y) {}

	const bool operator== (const Coordinate& that) const {
		return (x == that.x && y == that.y);
	}
};

bool isGood(const Coordinate& coord, const vector<vector<bool>> &maze) {
	return (coord.x >= 0 && coord.x < maze.size()) &&
		   (coord.y >= 0 && coord.y < maze[coord.x].size()) &&
		   maze[coord.x][coord.y];
}

bool hasPath(const vector<vector<bool>> &maze, const Coordinate &start, const Coordinate &goal) {
	int width = maze.size();
	int height = maze[0].size();

	vector<vector<bool> > explored(width, vector<bool>(height, false));
	queue<Coordinate> toDo;
	toDo.push(start);

	Coordinate current;

	while (!toDo.empty()) {
		current = toDo.front();
		toDo.pop();

		if (current == goal) return true;

		if (!isGood(current, maze) || explored[current.x][current.y])
			continue;
		else
			explored[current.x][current.y] = true;

		toDo.push(Coordinate(current.x - 1, current.y - 1)); // left down
		toDo.push(Coordinate(current.x + 1, current.y - 1)); // right down
		toDo.push(Coordinate(current.x + 1, current.y + 1)); // right up
		toDo.push(Coordinate(current.x - 1, current.y + 1)); // left up
	}

	return false;
}
