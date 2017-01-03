/*!
 * \file 
 * \brief  MaxStackNode.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "MaxStackNode.h"

template <typename T>
MaxStackNode<T>::MaxStackNode() {
}

template <typename T>
MaxStackNode<T>::MaxStackNode(T data) : data(data)
{}

template <typename T>
MaxStackNode<T>::MaxStackNode(T data, MSNodePtr<T> under) : data(data), under(under)
{}

template <typename T>
MaxStackNode<T>::~MaxStackNode() {
}

template class MaxStackNode<int>;
