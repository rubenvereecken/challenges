/*!
 * \file 
 * \brief  misc.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef MISC_H_
#define MISC_H_

#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <set>
using namespace std;

namespace help
{
	string itostr(int i);

	void print_array(std::ostream& out, const int * array, int length);
	void print_vector(const vector<int>& array, std::ostream& out=cout);

	string concatenate(vector<string> strings);
	vector<string> split(string s);
	vector<string> concatenate(const vector<string>& a, const vector<string>& b);

	inline int abs (int a) { return (a < 0) ? -a : a; };

	template <typename T>
	bool equalElements(const vector<T>&, const vector<T>&);

	void inline swap (int &a, int &b) {
		a ^= b ^= a ^= b;
	}

	template<typename T>
	vector<vector<T>> permutate(vector<T>&);

	template<typename T>
	vector<vector<T>> combine(vector<T> &array, int r);

	template <typename T>
	void print_set(std::ostream& out, const set<T> &hoop);
}

#endif /* MISC_H_ */
