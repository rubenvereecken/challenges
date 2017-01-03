/*!
 * \file
 * \brief  stacks_queues_tests.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#define BOOST_TEST_MODULE Stacks_Queues

#include <boost/test/unit_test.hpp>
#include "MaxStack.h"
#include <iostream>
//____________________________________________________________________________//

int init_unit_test_suite(int argc, char** argv) {
	std::cout << "waddup" << std::endl;
	return 0;
}

BOOST_AUTO_TEST_SUITE( StacksQueues )

BOOST_AUTO_TEST_CASE_EXPECTED_FAILURES( test1, 1 )
BOOST_AUTO_TEST_CASE( PrintTest )
{
    MaxStack<int> stack;
    stack.emplace(1);
    stack.emplace(2);
    stack.emplace(3);
    stack.pop();
    stack.emplace(6);
    std::cout << stack.getMax()->data << std::endl;
    stack.print();
}

BOOST_AUTO_TEST_SUITE_END()

//____________________________________________________________________________//

// EOF
