/*!
 * \file 
 * \brief  skyLine.cpp
 *
 * \date   Sep 10, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

using namespace std;

vector<int> makeSkyline (const vector<triplet> &buildings) {
	int width = 0;
	for (const auto &building : buildings) {
		width = (building[2] > width) ? building[2] : width;
	}

	// If heightAxis[i] = x, it means that [i, i + 1] has height x
	vector<int> heightAxis(width);

	for (const auto &building : buildings) {
		int height = building[1];
		for (int interval = building[0]; interval < building[2]; interval++) {
			if (height > heightAxis[interval])
				heightAxis[interval] = height;
		}
	}


	vector<int> skyline;
	int lastHeight = 0;

	for (int interval = 0; interval < heightAxis.size(); interval++) {
		if (heightAxis[interval] != lastHeight) {
			skyline.push_back(interval);
			skyline.push_back(heightAxis[interval]);
			lastHeight = heightAxis[interval];
		}
	}

	skyline.push_back(width);
	skyline.push_back(0);

	return skyline;
}
