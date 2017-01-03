__author__ = 'ruben'

from LinkedLists.LinkedList import LinkedListNode as LinkedList

def find_k_last(head, k):
    runner = head
    c = 0
    while runner.next:
        c += 1
        runner = runner.next
    k = c - k
    runner = head
    while k > 0:
        runner = runner.next
        k -= 1
    return runner


def find_k_last2(head, k):
    first = head
    second = head

    for i in range(k):
        if second.next:
            second = second.next
        else:
            return None

    while second.next:
        first = first.next
        second = second.next

    return first


if __name__ == '__main__':
    a = LinkedList.from_list(list(range(9)))
    print(a)
    b = find_k_last2(a, 5)
    print(b.value)