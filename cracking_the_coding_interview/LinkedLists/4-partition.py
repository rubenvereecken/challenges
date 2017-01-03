__author__ = 'ruben'

from LinkedLists.LinkedList import LinkedListNode as LL


def partition_around(head, k):
    lower = lowerTail = None
    higher = higherTail = None

    while head:
        if head.value < k:
            if lower is None:
                lower = LL(head.value)
                lowerTail = lower
            else:
                lowerTail.next = LL(head.value)
                lowerTail = lowerTail.next
        else:
            if higher is None:
                higher = LL(head.value)
                higherTail = higher
            else:
                higherTail.next = LL(head.value)
                higherTail = higherTail.next
        head = head.next

    lowerTail.next = higher
    return lower


if __name__ == '__main__':
    a = LL.from_list(range(9, 0, -1))
    print(a)
    b = partition_around(a, 5)
    print(b)