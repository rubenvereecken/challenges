//============================================================================
// Name        : vpw2013.cpp
// Author      : Ruben Vereecken
// Version     :
// Copyright   : 
// Description : Hello World in C, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int p = 0;
		int d = 0;
		int l = 0;
		cin >> p;
		cin >> d;
		cin >> l;

		vector<string> planning(p);

		for (int i = 0; i < p; i++) {
			cin >> planning[i];
		}

		bool finding = false;
		bool success = false;
		int beginday = 0;
		int found = 0;

		for (int i = 0; i < d; i++) {
			bool allgood = true;
			for (int j = 0; j < p; j++) {
				if (planning[j][i] == 'B') {
					allgood = false;
					break;
				}
			}

			if (allgood) {
				found++;
				finding = true;
				if (found == l) {
					success = true;
					beginday = i - l + 2;
					break;
				}
			}
			else {
				if (finding) {
					finding = false;
					found = 0;
				}
			}
		}

		if (success)
			cout << beginday << endl;
		else
			cout << 'X' << endl;
	}

	return 0;
}
