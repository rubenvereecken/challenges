/*!
 * \file 
 * \brief  mastermind.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

vector<char> charify(int n)
{
	stringstream ss;
	ss << n;
	string result = ss.str();

	vector<char> charified;

	for (string::const_iterator it = result.begin(); it != result.end(); it++)
		charified.push_back(*it);

	return charified;
}

int decharify(char* chars, int a, int b)
{
	stringstream ss;
	for (int i = a; i < b; i++) {
		ss << chars[i];
	}
	int n;
	ss >> n;
	return n;
}

int decharify(string chars, int a, int b)
{
	stringstream ss;
	for (int i = a; i < b; i++) {
		ss << chars[i];
	}
	int n;
	ss >> n;
	return n;
}

int decharify(char* chars, int size)
{
	stringstream ss;
	for (int i = 0; i < size; i++) {
		ss << chars[i];
	}
	int n;
	ss >> n;
	return n;
}


int main()
{
	int L;
	cin >> L;

	char trash[20];


	for (int i = 0; i < L; i++) {
		int n, k, a;

		cin >> n >> k >> a;

		cout << "n=" << n << " k=" << k << " a=" << a << endl;

		for (int j = 0; j < a; j++) {

			int guess, b, w;
			string atry;
			cin >> atry;

			guess = decharify(atry, 0, n);
			b = decharify(atry, n + 1, n + 2);
			w = decharify(atry, n + 3, n + 4);

			cout << guess << ":" << b << "," << w << endl;
		}


	}
}


