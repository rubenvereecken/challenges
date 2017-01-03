/*!
 * \file 
 * \brief  intervals.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"
#include <algorithm>

using namespace std;

int totalOverlap(vector<int> start, vector<int> end) {
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());

	int active = 0;
	int overlap = 0;
	int i = 0;
	int j = 0;

	while (i < start.size() && j < end.size()) {
		if (start[i] < end[j]) {
			i++;
			overlap += active;
			active++;
		}
		else {
			j++;
			active--;
		}
	}

	return overlap;
}

int maxOverlap(vector<pair<int, int> > intervals) {
	vector<int> plot;
	for (auto &interval : intervals) {
		if (interval.second > plot.size())
			plot.resize(interval.second, 0);
		for (int i = interval.first; i < interval.second; i++) {
			plot[i]++;
		}
	}
	int max = 0;
	for (int &val : plot)
		max = (val > max) ? val : max;
	return max;
}

// No hash map alloconst pair<int, int> &intervalwed
int maxOverlap2(vector<int> start, vector<int> end) {
//	std::sort(intervals.begin(), intervals.end(),
//			[](const pair<int, int> &a, const pair<int, int> &b) { return a.first < b.first; });
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());

	int i = 0;
	int j = 0;

	int maxActive = 0;
	int currentActive = 0;

	while (i < start.size() && j < end.size()) {
		if (start[i] < end[j]) {
			currentActive++;
			maxActive = (maxActive > currentActive) ? maxActive : currentActive;
			i++;
		}
		else if (start[i] == end[j]) {
			i++;
			j++;
		}
		else {
			currentActive--;
			j++;
		}
	}

	return maxActive;
}

