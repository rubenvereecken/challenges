/*!
 * \file 
 * \brief  sorts.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */

#include <vector>
using namespace std;

template<typename T>
struct myCompare
{
	bool operator() (const T& a, const T& b) { return a < b; }
};

template<typename T, typename U = myCompare<T> >
void bubbleSort (vector<T>& vec, U compare = myCompare<T>())
{
	int n = vec.size() - 1;
	bool changed = true;

	while (changed) {
		changed = false;
		for (int i = 0; i < n; i++) {
			if (!compare(vec[i], vec[i + 1])) {
				changed = true;
				T temp = vec[i + 1];
				vec[i + 1] = vec[i];
				vec[i] = temp;
			}
		}
		--n;
	}
}


