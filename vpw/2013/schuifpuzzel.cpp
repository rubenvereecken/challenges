/*!
 * \file 
 * \brief  kortstepad.cpp
 *
 * \date   Apr 17, 2013
 * \author Ruben Vereecken
 */

#include <algorithm>
#include <map>
#include <iostream>
#include <sstream>

using namespace std;

//typedef vector< vector< char> > puzzle;
//
//puzzle strToPuzzle(string puzzleStr, unsigned int w, unsigned int h)
//{
//	puzzle field(w, vector<string>(h));
//	for(unsigned int x=0; x<w; x++)
//		for (unsigned int y=0; y<h; y++)
//			field[x][y] = puzzleStr.at(y*h+x);
//	return field;
//}

unsigned int recursive(unsigned int iteration, string init, string final, unsigned int w, unsigned int h, unsigned int emptyX, unsigned int emptyY)
{
	for (int dx=-1; dx<2; dx++)
		for (int dy=-1; dy<2; dy++)
		{
			if ( abs(dx+dy) != 1)
				continue;
			unsigned newEmptyX = emptyX + dx;
			unsigned newEmptyY = emptyY + dy;
			if(newEmptyX < 0 || newEmptyX >= w)
				continue;
			if(newEmptyY < 0 || newEmptyY >= h)
				continue;

			string tempRes = init;
			tempRes[emptyY*w + emptyX] = final[newEmptyY*w + newEmptyX];
			final[newEmptyY*w + newEmptyX] = ' ';
			if (tempRes == final)
				return iteration+1;
			else
			{
				unsigned int res = recursive(iteration+1, tempRes, final, w, h, newEmptyX, newEmptyY);
				if (res > 0)
					return res;
			}
		}
	return -1;
}

int main() {
	unsigned int opgaven;
	cin >> opgaven;
	for (unsigned int i = 0; i < opgaven; ++i) {
		unsigned int w, h;
		string puzzleInitStr, puzzleInitStr2;
		string puzzleFinalStr, puzzleFinalStr2;
		cin >> h >> w;
		cin >> puzzleInitStr;
		unsigned pos = puzzleInitStr.length();
		if (puzzleInitStr.length() == w*h-1)
		{
			puzzleInitStr += string(" ");
		} else {
			cin >> puzzleInitStr2;
			puzzleInitStr += string(" ") + puzzleInitStr2;
		}

		cin >> puzzleFinalStr;
		if (puzzleFinalStr.length() == w*h-1)
		{
			puzzleFinalStr += string(" ");
		} else {
			cin >> puzzleFinalStr2;
			puzzleFinalStr += string(" ") + puzzleFinalStr2;
		}

//		cout << pos << endl;

//		unsigned int pos = space - puzzleInitStr.begin();
		unsigned int res = recursive(0, puzzleInitStr, puzzleFinalStr, w, h, pos%w, pos/w);
		std::cout << res << std::endl;
	}
}
