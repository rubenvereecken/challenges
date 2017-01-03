/*!
 * \file 
 * \brief  VIII.IX_print_binary_tree.cpp
 *
 * \date   Aug 14, 2013
 * \author Ruben Vereecken
 */

#include "VIII_stacks_queues.h"
#include <queue>

using namespace std;

template <typename T>
void printLevelOrder(BTNodePtr<T> root) {
	queue<BTNodePtr<T> > toDo;
	toDo.push(root);
	BTNodePtr<T> current;

	while (current = toDo.front()) {
		std::cout << *current << " ";
		toDo.push(current->left);
		toDo.push(current->right);
		toDo.pop();
	}

	std::cout << std::endl;
}
