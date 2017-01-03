/*!
 * \file 
 * \brief  LinkedList.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include "ListNode.h"

template <typename T>
class LinkedList {
public:
	LinkedList();
	LinkedList(ListNodePtr<T> head);
	virtual ~LinkedList();

	void print() const;

	const ListNodePtr<T>& getHead() const {
		return head;
	}

	void setHead(const ListNodePtr<T>& head) {
		this->head = head;
	}

	void reverse();

private:
	ListNodePtr<T> head;
};

#endif /* LINKEDLIST_H_ */
