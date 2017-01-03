/*!
 * \file 
 * \brief  searchingTests.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#define BOOST_TEST_MODULE SearchingTests
#include <boost/test/unit_test.hpp>
#include "searching.h"
#include "helper.h"
#include <iostream>
using namespace std;
//____________________________________________________________________________//


BOOST_AUTO_TEST_SUITE( Searching )

//BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES( test1, 1 )
BOOST_AUTO_TEST_CASE( indexIsValue )
{
	static const int arr[] = {16,2,77,29};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
}

BOOST_AUTO_TEST_SUITE_END()

//____________________________________________________________________________//



