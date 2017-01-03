/*!
 * \file 
 * \brief  sqrt.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"
#include <math.h>

using namespace std;

inline double abs2(double a) { return (a < 0) ? -a : a; }

double sqrt(double x) {
	return pow(10, 2 * log(x));
}

double newtons(double prev, double S) {
	return .5 * (prev + S / prev);
}

double sqrt2(double x) {
	double xi = x;

	for (int i = 0; i < 100; i++) {
		xi = newtons(xi, x);
	}

	return xi;
}

double sqrt2(double x, int precision) {
	double xi = x;

	for (int i = 0; i < 1000; i++) {
		xi = newtons(xi, x);
		if (abs2(xi * xi - x) < precision)
			break;
	}

	return xi;
}
