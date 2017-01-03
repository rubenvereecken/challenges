/*!
 * \file 
 * \brief  utils.cpp
 *
 * \date   Feb 11, 2013
 * \author Ruben Vereecken
 */


#include <vector>
#include <sstream>
#include <stack>
using namespace std;

stack<int> digify(int n)
{
	 stack<int> digits;
	 while(n > 0)
	 {
		digits.push(n % 10);
		n = n / 10;
	 }
	 return digits;
}

vector<char> charify(int n)
{
	stringstream ss;
	ss << n;
	string result = ss.str();

	vector<char> charified;

	for (string::const_iterator it = result.begin(); it != result.end(); it++)
		charified.push_back(*it);
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

// decharify [a b)
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

