/*!
 * \file 
 * \brief  VII.IV_overlapping_acyclic.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "VII_linked_lists.h"

template<typename T>
ListNodePtr<T> getOverlapping(ListNodePtr<T> h1, ListNodePtr<T> h2) {
	ListNodePtr<T> current1;
	ListNodePtr<T> current2 = h2;

	while (current2) {
		current1 = h1;
		while (current1) {
			if (current1 == current2)
				return current1;
			current1 = current1->getNext();
		}
		current2 = current2->getNext();
	}
}
