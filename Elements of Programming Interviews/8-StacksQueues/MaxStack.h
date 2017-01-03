/*!
 * \file 
 * \brief  MaxStack.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef MAXSTACK_H_
#define MAXSTACK_H_

#include "MaxStackNode.h"
#include <stdexcept>
#include <string>
#include <iostream>

template <typename T>
class MaxStack {
public:
	MaxStack();
	virtual ~MaxStack();

	// Observers
	MSNodePtr<T> peek() const;
	MSNodePtr<T> getMax() const;
	void print(std::ostream& out = std::cout) const;

	// Modifiers
	MSNodePtr<T> pop();
	void push(MSNodePtr<T>);
	void emplace(T);

private:
	MSNodePtr<T> top;
	MSNodePtr<T> max;
};

class MaxStackException : std::runtime_error {
	MaxStackException(std::string what) : std::runtime_error(what) {};
};

#endif /* MAXSTACK_H_ */
