/*!
 * \file 
 * \brief  primes.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <vector>
#include <cmath>
using namespace std;

/*
Input: an integer n > 1

Let A be an array of Boolean values, indexed by integers 2 to n,
initially all set to true.

for i = 2, 3, 4, ..., √n :
  if A[i] is true:
    for j = i2, i2+i, i2+2i, ..., n:
      A[j] := false

Now all i such that A[i] is true are prime.
 */

void sieve()
{
	int n = 1000;
	vector<bool> boolarray(n, true);

	for (int i = 2; i < sqrt(n); i++) {
		if (boolarray[i])
			for (int j = i * 2; j < n; j += i)
				boolarray[j] = false;
	}

	boolarray[0] = false;
	boolarray[1] = false;
}
