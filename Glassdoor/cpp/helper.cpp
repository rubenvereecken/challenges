/*!
 * \file 
 * \brief  helper.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */
#include "helper.h"
#include <cstdlib>
#include <sstream>
using namespace std;

namespace help {

string itostr(int i) {
	stringstream stream;
	stream << i;
	return stream.str();
}

template<typename T>
vector<vector<T>> combine(vector<T> &array, int r) {
	vector<vector<T> > result;

	if (r == 1) {
		for (T it : array) {
			result.emplace(result.end(), vector<T>({it}));
		}
		return result;
	}

	typename vector<T>::iterator vectorIt;
	typename vector<vector<T>>::iterator nestedVectorIt;

	for (vectorIt = array.begin(); vectorIt != array.end(); ++vectorIt) {
		vector<T> copy;
		copy.insert(copy.end(), vectorIt + 1, array.end());

		vector<vector<T> > results = combine(copy, r - 1);

		for (nestedVectorIt = results.begin(); nestedVectorIt != results.end();
				nestedVectorIt++) {
			vector<T> current;
			current.insert(current.end(), vectorIt, vectorIt + 1);
			current.insert(current.end(), nestedVectorIt->begin(),
					nestedVectorIt->end());
			result.insert(result.end(), current);
		}
	}

	return result;
}

template<typename T>
vector<vector<T>> permutate(vector<T> &array) {
	vector<vector<T> > result;

	if (array.size() == 1) {
		result.emplace(result.end(), array);
		return result;
	}

	typename vector<T>::iterator vectorIt;
	typename vector<vector<T>>::iterator nestedVectorIt;

	for (vectorIt = array.begin(); vectorIt != array.end(); ++vectorIt) {
		vector<T> copy;
		copy.reserve(array.size() - 1);
		copy.insert(copy.end(), array.begin(), vectorIt);
		copy.insert(copy.end(), vectorIt + 1, array.end());

		vector<vector<T> > results = permutate(copy);

		for (nestedVectorIt = results.begin(); nestedVectorIt != results.end();
				nestedVectorIt++) {
			vector<T> current;
			current.insert(current.end(), vectorIt, vectorIt + 1);
			current.insert(current.end(), nestedVectorIt->begin(),
					nestedVectorIt->end());
			result.insert(result.end(), current);
		}
	}

	return result;
}

template<typename T>
void print_set(std::ostream& out, const set<T> &hoop) {
	out << "[";

	typename set<T>::iterator it;
	for (it = hoop.begin(); it != hoop.end(); ++it) {
		out << *it << ' ';
	}
	out << "]\n";
}

void print_array(std::ostream& out, const int * array, int length) {
	out << "[";
	for (int i = 0; i < length; i++) {
		out << array[i];
		if (i != length - 1)
			out << ", ";
	}
	out << "]\n";
}

void print_vector(const vector<int>& array, std::ostream& out) {
	out << "[";
	for (int i = 0; i < array.size(); i++) {
		out << array[i];
		if (i != array.size() - 1)
			out << ", ";
	}
	out << "]\n";
}

string concatenate(vector<string> strings) {
	string result;
	for (auto s : strings)
		result += s;
	return result;
}

vector<string> split(string s) {
	vector<string> result;
	for (auto c = s.begin(); c != s.end(); c++)
		result.push_back(string(c, c + 1));
	return result;
}

vector<string> concatenate(const vector<string>& a, const vector<string>& b) {
	vector<string> ab;
	ab.reserve(a.size() + b.size());
	ab.insert(ab.end(), a.begin(), a.end());
	ab.insert(ab.end(), b.begin(), b.end());
	return ab;
}

template<typename T>
bool equalElements(const vector<T>& a, const vector<T>& b) {
	if (a.size() != b.size())
		return false;
	for (unsigned int i = 0; i < a.size(); i++) {
		if (a[i] != b[i])
			return false;
	}
	return true;
}

template bool equalElements(const vector<int>&, const vector<int>&);
template vector<vector<int> > permutate(vector<int>&);
template vector<vector<int> > combine(vector<int> &array, int r);
template void print_set(std::ostream& out, const set<int> &hoop);
}
