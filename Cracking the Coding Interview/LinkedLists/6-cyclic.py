__author__ = 'ruben'

from LinkedLists.LinkedList import LinkedListNode as LL

def find_start(head):
    slow = head
    fast = head.next

    while slow != fast:
        slow = slow.next
        fast = fast.next.next

    fast = fast.next
    slow = head

    while slow != fast:
        slow = slow.next
        fast = fast.next

    return slow


if __name__ == '__main__':
    a = LL.from_list(range(5))
    a.tail().next = a.find(2)
    s = find_start(a)
    print(s.value)