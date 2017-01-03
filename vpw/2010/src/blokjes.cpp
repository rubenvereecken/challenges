/*!
 * \file 
 * \brief  blokes.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */


#include <iostream>
#include <vector>
using namespace std;

vector<int> npows(101, 0);

inline int pow3(int n)
{
	return n * n * n;
}

inline int pow3sum(int n)
{
	if (npows[n])
		return npows[n];
	else
		return npows[n] = pow3sum(n - 1) + pow3(n);
}

int main()
{
	npows[1] = 1;

	int n, k;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		cout << pow3sum(k) << endl;
	}
}

