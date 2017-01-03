/*!
 * \file 
 * \brief  VII_linked_lists.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef VII_LINKED_LISTS_H_
#define VII_LINKED_LISTS_H_

#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include "helper.h"
#include "LinkedList.h"

template <typename T>
LinkedList<T> mergeSortedLists(LinkedList<T>& L, LinkedList<T>& F);

template <typename T>
ListNodePtr<T> getCycle(const LinkedList<T>& L);

#endif /* VII_LINKED_LISTS_H_ */
