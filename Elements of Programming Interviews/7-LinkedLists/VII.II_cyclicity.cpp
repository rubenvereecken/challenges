/*!
 * \file 
 * \brief  VII_cyclicity.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */


#include "VII_linked_lists.h"
#include <unordered_set>


template <typename T>
ListNodePtr<T> getCycle(const LinkedList<T>& L) {
	std::unordered_set<ListNodePtr<T> > soFar;
	ListNodePtr<T> current = L.getHead();

	while (current) {
		if (soFar.find(current) == soFar.end()) {
			soFar.insert(current);
			current = current->getNext();
		}
		else return current;
	}

	return nullptr;
}

template ListNodePtr<int> getCycle(const LinkedList<int>& L);
