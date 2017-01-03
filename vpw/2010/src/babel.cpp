/*!
 * \file 
 * \brief  2010_1.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <map>

using namespace std;

int main()
{
	int n, k;
	map<string, string> dict;

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		string giaduk, nederlands;
		cin >> giaduk >> nederlands;
		dict[giaduk] = nederlands;
	}

	for (int i = 0; i < k; i++) {

		string asked;
		cin >> asked;
		if (dict[asked] == "")
			cout << "???";
		else
			cout << dict[asked];

		cout << endl;
	}
}


