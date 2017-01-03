/*!
 * \file 
 * \brief  MaxStack.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "MaxStack.h"


template <typename T>
MaxStack<T>::MaxStack() {

}

template <typename T>
MaxStack<T>::~MaxStack() {
}

template <typename T>
void MaxStack<T>::push(MSNodePtr<T> node) {
	if (max && top) {
		node->under = top;
		top = node;
		if (max->data < node->data)
			max = node;
	}
	else {
		max = node;
		top = node;
	}
}

template <typename T>
void MaxStack<T>::emplace(T data) {
	MSNodePtr<T> newNodePtr(new MaxStackNode<T>(data));
	push(newNodePtr);
}

template <typename T>
void MaxStack<T>::print(std::ostream& out) const {
	MSNodePtr<T> current = top;
	while (current) {
		out << current->data << " ";
		current = current->under;
	}
	out << std::endl;
}

template <typename T>
MSNodePtr<T> MaxStack<T>::pop() {
	MSNodePtr<T> top = this->top;
	this->top = top->under;
	return top;
}

template <typename T>
MSNodePtr<T> MaxStack<T>::peek() const {
	return this->top;
}

template <typename T>
MSNodePtr<T> MaxStack<T>::getMax() const {
	return this->max;
}

template class MaxStack<int>;
