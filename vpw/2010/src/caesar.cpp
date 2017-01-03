/*!
 * \file 
 * \brief  caesar.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <vector>
using namespace std;


int main()
{
	vector<char> alpha(27);
	alpha[0] = ' ';

	char c = 'A';
	for (int i = 1; i < 27; i++)
		alpha[i] = c++;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int k;
		string coded;
		cin >> k;
		cin >> coded;

		while (cin.peek() == ' ') {
			string extra;
			cin >> extra;
			coded += ' ' + extra;
		}

		string decoded;

		for (string::const_iterator ch = coded.begin(); ch != coded.end(); ch++) {
			char charact = *ch;
			//cout << "Working on char \'" << charact << "\'" << endl;
			if (charact > 64 && charact < 91) {
				int factor = (charact - 64 - k) % 27;
				if (factor < 0) factor += 27;
				decoded += alpha[factor];
			}
			else if (charact == ' ') {
				int factor = (0 - k) % 27;
				if (factor < 0) factor += 27;
				decoded += alpha[factor];
			}
			else
				decoded += charact;
		}
		cout << decoded << endl;

	}
}


