__author__ = 'ruben'

class LinkedListNode:
    def __init__(self, value, **kwargs):
        self.value = value
        self.next = kwargs.get('next', None)
        self.prev = kwargs.get('prev', None)

    def __str__(self):
        str = "[" + self.value.__str__()
        current = self.next
        while current:
            str += ", " + current.value.__str__()
            current = current.next
        str += "]"
        return str

    def tail(self):
        current = self
        while current.next:
            current = current.next
        return current

    def find(self, value):
        if self.value == value:
            return self
        if self.next:
            return self.next.find(value)
        else:
            return None

    @staticmethod
    def from_list(array):
        if len(array) == 0:
            return None
        else:
            head = LinkedListNode(array[0])
            tail = head
            for el in array[1:]:
                tail.next = LinkedListNode(el)
                tail.next.prev = tail
                tail = tail.next
            return head


class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def __str__(self):
        if self.head:
            return self.head.__str__()
        else:
            return "[]"

    def push(self, node):
        if not isinstance(node, LinkedListNode):
            node = LinkedListNode(node)
        if self.tail:
            self.tail.next = node
            self.tail = node
        else:
            self.head = self.tail = node
        return self

    def insert(self, node):
        return self.push(node)

    def last(self):
        return self.tail

    def pop(self):
        if self.tail:
            last = self.tail
            if self.tail.prev:
                self.tail = self.tail.prev
                self.tail.next = None
            else:
                self.head = None
                self.tail = None
            return last
        else:
            raise AssertionError("Can't pop from empty list.")

    def remove(self, node):
        current = self.head
        if current:
            while current:
                if current == node:
                    if current.prev:
                        current.prev = current.next
                    else:
                        self.head = current.next
                    if current.next:
                        current.next = current.prev
                    else:
                        self.tail = current.prev
                    return current
                current = current.next
        return None


if __name__ == '__main__':
    list = LinkedListNode.from_list(list(range(9)))
    print(list)