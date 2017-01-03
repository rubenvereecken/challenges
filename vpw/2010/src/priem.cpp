/*!
 * \file 
 * \brief  priem.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <iostream>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

double log102 = log10(2);

double log2(int n)
{
	return (log10(n) / log102);
}

int abs(int r)
{
	return (r < 0) ? -r : r;
}

int main()
{

	int o = 1000000;
	vector<bool> primes(o + 1, true);
	vector<bool> powers(o + 1, false);

	for (int i = 2; i < sqrt(o); i++) {
		if (primes[i])
			for (int j = i * 2; j < o; j += i)
				primes[j] = false;
	}

	primes[0] = false;
	primes[1] = false;

	for (int i = 1; i <= o; i *= 2) {
		powers[i] = true;
	}



	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n, m;
		cin >> m >> n;

		// hack mode
		if (m <= 2 && 2 <= n) {
			cout << 2 << endl;
			continue;
		}


		vector<int> localPrimes;
		vector<int> localPowers;
		vector<pair<int, int> > primesWithDistance;

		//cout << pow(2, floor(log2(m))) << endl;
		//cout << pow(2, ceil(log2(m))) << endl;

		localPowers.push_back(pow(2, floor(log2(m) - 1)));
		localPowers.push_back(pow(2, floor(log2(m))));
		localPowers.push_back(pow(2, ceil(log2(m))));
		localPowers.push_back(pow(2, ceil(log2(m) + 1)));

		for (int j = m; j <= n; j++) {
			if (primes[j])
				localPrimes.push_back(j);
			if (powers[j])
				localPowers.push_back(j);
		}


		for (int j = 0; j < localPrimes.size(); j++) {
			int prime = localPrimes[j];
			int distance = o;

			for (int k = 0; k < localPowers.size(); k++) {
				int power = localPowers[k];
				int tryDist = abs(prime - power);
				if (tryDist < distance) distance = tryDist;
			}

			primesWithDistance.push_back(make_pair(prime, distance));
		}

		int distance = o;

		bool changed = true;
		while(changed) {
			changed = false;
			for (int j = 0; j < primesWithDistance.size(); j++) {
				int curdis = primesWithDistance[j].second;
				if (!curdis) continue;
				if (curdis < distance) {
					distance = curdis;
					changed = true;
				}
				else if (curdis > distance) {
					primesWithDistance[j].second = 0;
					changed = true;
				}
			}
		}

		if (primesWithDistance.empty())
			cout << "geen priemgetal gevonden" << endl;
		else {
			int lowestprime = o;
			for (int j = 0; j < primesWithDistance.size(); j++) {
				int curdis = primesWithDistance[j].second;
				int prime = primesWithDistance[j].first;
				if (curdis && prime < lowestprime) {
					lowestprime = prime;
				}
			}
			cout << lowestprime << endl;
		}
	}
}


