__author__ = 'ruben'

from LinkedLists.LinkedList import LinkedList

def remove_duplicates(list):
    dict = {}
    if list.head:
        current = list.head
        previous = None
        while current:
            if dict.get(current.value): # Remove it
                previous.next = current.next
            else:
                dict[current.value] = True
                previous = current
            current = current.next

if __name__ == '__main__':
    list = LinkedList()
    a = list.insert(0).insert(0).insert(1).insert(2).insert(2)
    print(a)
    remove_duplicates(a)
    print(a)