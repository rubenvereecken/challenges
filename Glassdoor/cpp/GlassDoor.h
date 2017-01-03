/*!
 * \file 
 * \brief  GlassDoor.h
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#ifndef GLASSDOOR_H_
#define GLASSDOOR_H_

#include <vector>
#include <set>
#include <array>
#include <map>
#include <stack>
#include <iostream>
#include <algorithm>
#include "helper.h"

using namespace std;

typedef array<int, 3> triplet;

/*
 * Skyline problem
 * Online Judge link with description http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=41
 */
vector<int> makeSkyline (const vector<triplet> &buildings);

// Sum two binary numbers (as strings)
string sumBinary(string a, string b);

// Triplets that sum up to 0
vector<triplet> tripletsToZero(const vector<int> &array);

// Look & Say sequence
string nextLookAndSay(string number);

// Failure function & text search
vector<int> failureFunction (string a);
int find(const string& text, const string &word);

// Regex
bool matches(string word, string pattern);

// Roman numerals
int fromRoman(string roman);

// sqrt using logs
double sqrt(double x);

// sqrt without logs
double sqrt2(double x);

// Total amount of overlapping intervals
int totalOverlap(vector<int> start, vector<int> end);
int maxOverlap(vector<pair<int, int> > intervals);

// Different power functions
double powInt(double x, int a);

// All subsets with given sum
vector<vector<int>> subsetsWithSum(vector<int> &array, int sum);

// First found longest substring
string longestCommon(string a, string b);

// Generate all possible strings for a phone number
vector<string> phoneStrings(string number);

// Indices of max subarray
pair<int, int> maxSubArray(const vector<int> & array);

// Solves expression
string inToPost(string infix);
int evaluatePost(string post, int replaceX);
int findX(string equation);

// Dutch Flag problem
void dutchFlag(vector<int> &array);

#endif /* GLASSDOOR_H_ */
