__author__ = 'ruben'

"""
Only stacks are allowed n the implementation of the queue
"""


class Queue():
    def __init__(self):
        self.stack_new = []
        self.stack_old = []

    def push(self, p):
        self.stack_new.append(p)
        return self

    def pop(self):
        if len(self.stack_old) == 0:
            while len(self.stack_new) > 0:  # worst case scenario
                self.stack_old.append(self.stack_new.pop(-1))

        return self.stack_old.pop(-1)


if __name__ == '__main__':
    q = Queue()
    q.push(5).push(6).push(3)
    print(q.pop())
    q.push(7)
    print(q.pop())