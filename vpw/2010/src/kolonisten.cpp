/*!
 * \file 
 * \brief  kolonisten.cpp
 *
 * \date   Feb 12, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

double chanceFor (int n)
{
	if (n == 2 || n == 12)
		return 1.0/36.0;
	if (n == 3 || n == 11)
		return 2.0/36.0;
	if (n == 4 || n == 10)
		return 3.0/36.0;
	if (n == 5 || n == 9)
		return 4.0/36.0;
	if (n == 6 || n == 8)
		return 5.0/36.0;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		queue<char> chars;
		set<pair<char, int> > tiles;

		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			chars.push(c);
		}
		for (int j = 0; j < m; j++) {
			int chance;
			cin >> chance;
			tiles.insert(make_pair(chars.front(), chance));
			chars.pop();
		}


		map<char, double> chancemap;
		map<char, int> tilecount;

		for (set<pair<char, int> >::iterator it = tiles.begin(); it != tiles.end(); it++) {
			pair<char, int> tile = *it;
			chancemap[tile.first] += chanceFor(tile.second);
			//cout << "added " <<  chanceFor(tile.second) << " for a total of " << chancemap[tile.first] << endl;
			tilecount[tile.first]++;
		}

		char lowestchar;
		double lowestchance = 1;

		bool changed = true;

		while(changed) {
			changed = false;

			for (map<char,double>::iterator it = chancemap.begin(); it != chancemap.end(); it++) {

				pair<char, double> tile = *it;
				//cout << tile.first << " has chance " << tile.second << endl;
				if (tile.second < lowestchance) {
					lowestchance = tile.second;
					lowestchar = tile.first;
				}
				else if (tile.second > lowestchance) {
					chancemap.erase(tile.first);
					changed = true;
					break;
				}
			}
		}


		if (chancemap.size() == 1) {
			cout << (*chancemap.begin()).first << endl;
		}
		else {
			int lowest = 100000000;
			char lowestch;
			for (map<char,int>::iterator it = tilecount.begin(); it != tilecount.end(); it++) {
				pair<char, int> tile = *it;
				if (tile.second < lowest) {
					lowest = tile.second;
					lowestch = tile.first;
				}
			}
			cout << lowestch << endl;
		}

	}
}
