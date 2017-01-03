/*!
 * \file 
 * \brief  VII.I_merge_lists.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "VII_linked_lists.h"

/*
 * Input lists are expected to be sorted.
 * Lists L and F are not guaranteed to be valid afterwards.
 */
template<typename T>
LinkedList<T> mergeSortedLists(LinkedList<T>& L, LinkedList<T>& F) {
	ListNodePtr<T> currentL = L.getHead();
	ListNodePtr<T> currentF = F.getHead();
	ListNodePtr<T> tail;
	LinkedList<T> M;

	if ((currentF && !currentL) || (currentF->getData() < currentL->getData())) {
		M.setHead(currentF);
		currentF = currentF->getNext();
	} else {
		M.setHead(currentL);
		currentL = currentL->getNext();
	}

	tail = M.getHead();

	while (currentL && currentF) {
		if (currentF->getData() < currentL->getData()) {
			tail->setNext(currentF);
			tail = currentF;
			currentF = currentF->getNext();
		} else {
			tail->setNext(currentL);
			tail = currentL;
			currentL = currentL->getNext();
		}
	}

	// Append remaining sublist
	if (currentL)
		tail->setNext(currentL);
	else
		tail->setNext(currentF);

	return M;
}

template LinkedList<int> mergeSortedLists(LinkedList<int>& L,
		LinkedList<int>& F);
