/*!
 * \file 
 * \brief  cocktails.cpp
 *
 * \date   Apr 17, 2013
 * \author Ruben Vereecken
 */


#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<char> tokenify(string str) {
	vector<char> tokens;
	for (int i = 0; i < str.length(); i++)
		tokens.push_back(str[i]);
	return tokens;
}

bool canBarmanDo(string barman, char cocktail) {
	for (string::iterator bit = barman.begin(); bit != barman.end(); bit++)
		if (*bit == cocktail)
			return true;
	return false;
}

bool check(vector<string> barmen, vector<char> cocks, int n = 0) {
	if (n == cocks.size() - 1) {
		if (canBarmanDo(barmen[0], cocks[n]))
			return true;
	}
	else {
		char currentCocktail = cocks[n];
		for (vector<string>::iterator barIt = barmen.begin(); barIt != barmen.end(); barIt++) {
			string currentBarman = *barIt;
			int NextN = n+1;
			vector<string> copyBars = barmen;
			copyBars.erase(barIt-barmen.begin()+copyBars.begin());
			if (canBarmanDo(currentBarman, currentCocktail) && check(copyBars, cocks, NextN)) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	int n;
	cin >> n;

	for (int a = 0; a < n; a++) {
		int m, k;
		cin >> m;
		vector<string> barmen(m);
		for (int i = 0; i < m; i++)
			cin >> barmen[i];


		cin >> k;
		for (int i = 0; i < k; i++) {
			string cocktailconfig;
			cin >> cocktailconfig;
			if (cocktailconfig.length() > m) {
				cout << cocktailconfig << ' ' << "onmogelijk" << endl;
				continue;
			}
			vector<char> cocktails = tokenify(cocktailconfig);
			cout << cocktailconfig;
			if (check(barmen, cocktails))
				cout << ' ' << "mogelijk" << endl;
			else
				cout << ' ' << "onmogelijk" << endl;

		}


	}

	return 0;
}

