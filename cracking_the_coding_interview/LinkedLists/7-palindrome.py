__author__ = 'ruben'

from LinkedLists.LinkedList import LinkedListNode as LL

def is_palindrome(head):
    slow = head
    fast = head
    stack = []

    step = True
    while fast and fast.next:
        stack.append(slow)
        slow = slow.next
        fast = fast.next
        if fast:
            fast = fast.next
            if fast is None:
                step = False

    # In the odd length case you need to step over the middle element
    if step:
        slow = slow.next

    while len(stack):
        left = stack.pop().value
        right = slow.value
        if left != right:
            return False
        slow = slow.next

    return True


if __name__ == '__main__':
    first = LL.from_list([1, 0, 1, 0, 1, 0, 1])
    second = LL.from_list([1, 0, 1, 1, 0, 1])
    third = LL.from_list([1, 0, 0, 1, 1, 0, 1])
    print(is_palindrome(first))
    print(is_palindrome(second))
    print(is_palindrome(third))