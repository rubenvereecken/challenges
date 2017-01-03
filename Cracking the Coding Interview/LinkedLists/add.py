__author__ = 'ruben'

'''
You have two numbers represented by a linked list, where each node contains a
single digit. The digits are stored in reverse order, such that the 1 's digit is at the head
of the list. Write a function that adds the two numbers and returns the sum as a
linked list.
'''

from LinkedLists.LinkedList import LinkedListNode

def add(first, second): # first and second are nodes
    # Assume length not available
    result = LinkedListNode(first.value + second.value)
    result_tail = result
    first = first.next
    second = second.next
    carry = 0
    while first or second:
        new_val = 0
        if first and second:
            new_val = first.value + second.value + carry
            first = first.next
            second = second.next
        elif first:
            new_val = first.value + carry
            first = first.next
        else:  # second
            new_val = second.value + carry
            second = second.next
        result_tail.next = LinkedListNode(new_val % 10)
        carry = new_val / 10
        result_tail = result_tail.next
    if carry:
        result_tail.next = LinkedListNode(carry)
    return result
