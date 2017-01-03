/*!
 * \file 
 * \brief  pow.cpp
 *
 * \date   Sep 12, 2013
 * \author Ruben Vereecken
 */

#include "GlassDoor.h"

double powInt(double x, int a) {
	if (a == 0)
		return 1;
	else if (a == 1)
		return x;
	else if (a == -1)
		return 1. / x;
	else {
		return powInt(x, a / 2) * powInt(x, a / 2) * powInt(x, a % 2);
	}
}

