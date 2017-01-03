/*!
 * \file 
 * \brief  MaxStackNode.h
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#ifndef MAXSTACKNODE_H_
#define MAXSTACKNODE_H_

#include <memory>

template <typename T>
class MaxStackNode;

//typedef MaxStackNode MSNode;

template <typename T>
using MSNodePtr = std::shared_ptr<MaxStackNode<T> >;

template <typename T>
class MaxStackNode {
public:
	MaxStackNode();
	MaxStackNode(T);
	MaxStackNode(T, MSNodePtr<T>);
	virtual ~MaxStackNode();

	T data;
	MSNodePtr<T> under;
};



#endif /* MAXSTACKNODE_H_ */
