/*!
 * \file 
 * \brief  LinkedList.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "LinkedList.h"
#include <iostream>

template <typename T>
LinkedList<T>::LinkedList() {

}

template <typename T>
LinkedList<T>::LinkedList(ListNodePtr<T> head) : head(head)
{}

template <typename T>
LinkedList<T>::~LinkedList() {
}

template <typename T>
void LinkedList<T>::print() const {
	ListNodePtr<T> current = this->head;

	while (current) {
		std::cout << current->getData() << " ";
		current = current->getNext();
	}

	std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::reverse() {
	ListNodePtr<T> prev = head;
	ListNodePtr<T> current = head->next;

	while (current) {
		ListNodePtr<T> after = current->next;
		current->next = prev;
		prev = current;
		current = after;
	}

	head = prev;
}

template class LinkedList<int>;
