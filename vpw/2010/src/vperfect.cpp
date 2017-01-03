/*!
 * \file 
 * \brief  vperfect.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */


#include <iostream>
#include <vector>
using namespace std;

int sum(const vector<int>& vec)
{
	int sum = 0;
	for (unsigned int i = 0; i < vec.size(); i++)
		sum += vec[i];
	return sum;
}

vector<int> factorize(int n)
{
	vector<int> vec;
	for (int i = 1; i <= n / 2; i++)
		if (!(n % i))
			vec.push_back(i);
	vec.push_back(n);
	return vec;
}


int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, vperf, factor;
		cin >> x >> y;
		bool found = false;

		for (int a = x; a <= y; a++) {
			int s = sum(factorize(a));
			if (!(s % a)) {
				vperf = a;
				factor = s / a;
				found = true;
				break;
			}
		}
		if (found)
			cout << vperf << ' ' << factor << endl;
		else
			cout << "GEEN" << endl;
	}


}

