__author__ = 'ruben'


from LinkedLists.LinkedList import LinkedListNode

def remove_by_reference(node):
    """
    the list is expected to be singly-linked
    :param node:
    :return:
    """

    prev = None

    while node.next:
        node.value = node.next.value
        prev = node
        node = node.next

    if prev:
        prev.next = None
    else:
        # node was tail, should do something
        pass


if __name__ == '__main__':
    l = LinkedListNode.from_list(range(6))
    node = l.next.next
    print(l)
    remove_by_reference(node)
    print(l)