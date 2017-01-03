/*!
 * \file 
 * \brief  ListNode.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "ListNode.h"

template <typename T>
ListNode<T>::ListNode(T data) : data(data), next(nullptr)
{

}

template <typename T>
ListNode<T>::ListNode(T data, ListNodePtr<T> next) : data(data), next(next)
{

}

template <typename T>
ListNode<T>::~ListNode() {
}

template class ListNode<int>;
