/*!
 * \file 
 * \brief  ListNode.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef NODE_H_
#define NODE_H_

#include <memory>
using namespace std;

template <typename T>
class ListNode;

template <typename T>
using ListNodePtr = shared_ptr<ListNode<T> >;

template <typename T>
class ListNode {
public:
	ListNode();
	ListNode(T data);
	ListNode(T data, ListNodePtr<T> next);
	virtual ~ListNode();

	T getData() const {
		return data;
	}

	void setData(T data) {
		this->data = data;
	}

	const ListNodePtr<T>& getNext() const {
		return next;
	}

	void setNext(const ListNodePtr<T>& next) {
		this->next = next;
	}

	T data;
	ListNodePtr<T> next;
};

#endif /* NODE_H_ */
