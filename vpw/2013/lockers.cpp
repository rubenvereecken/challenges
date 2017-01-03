#include <vector>
#include <queue>
#include <iostream>
#include <array>
#include <list>
#include <deque>

using namespace std;

int main() {
	int arrival, departure;
	int time = 0;
	int h, m;
	int aL, aP, aB, opgaven;
	list<array<int, 3>> lockers;
	list<array<int, 3>> bagage;
	int a, b, c;
	cin >> opgaven;
	for (int i = 0; i < opgaven; ++i) {
		cin >> aL;
		cin >> aP;
		for (int j = 0; j < aL; ++j) {
			cin >> a >> b >> c;
			lockers.push_back(array<int, 3>{a, b, c});
		}
		for (int j= 0; j < aP; ++j) {
			cin >> aB;
			cin >> h >> m;
			arrival = 60*h + m;
			cin >> h >> m;
			departure = 60*h + m;
			if (arrival > time) time = arrival;
			for (int k = 0; k < aB; ++k) {
				cin >> a >> b >> c;
				bagage.push_back(array<int, 3>{a, b, c});
			}
			for (auto it = lockers.begin(); it != lockers.end() && bagage.size() != 0; ++it) {
				time += 3;
				for (auto it2 = bagage.begin(); it2 != bagage.end(); ++it2) {
					if ((*it)[0] > (*it2)[0] && (*it)[1] > (*it2)[1] && (*it)[2] > (*it2)[2]) {
						auto it3 = it2;
						--it2;
						bagage.erase(it3);
						auto it4 = it;
						--it;
						lockers.erase(it4);
						time += 1;
						continue;
					}
				}
			}
			if (j != 0) cout << " ";
			if (time + 10*bagage.size() <= departure) {
				cout << "JA";
			} else {
				cout << "NEEN";
			}
			bagage.clear();
		}
		cout << endl;
	}
	return 0;
}
