/*!
 * \file 
 * \brief  kortstepad.cpp
 *
 * \date   Apr 17, 2013
 * \author Ruben Vereecken
 */

#include <map>
#include <iostream>

using namespace std;

int main() {
	multimap<int, int> total2first;
	int opgaven, nodes, first, second;
	cin >> opgaven;
	for (int i = 0; i < opgaven; ++i) {
		cin >> nodes;
		for (int j = 0; j < nodes; ++j) {
			cin >> first >> second;
			total2first.insert(make_pair(first + second, first));
		}
		auto it = total2first.begin();
		int solution = 200001;
		while (solution > it->first && it != total2first.end()) {
			for (auto it2 = total2first.begin(); it2 != it; ++it2) {
				int diff = it2->second < it->second ? it->second - it2->second : it2->second - it->second;
				int time = it->first + diff;
				if (time < solution) solution = time;
			}
			++it;
		}
		total2first.clear();
		cout << solution << endl;
	}
}
