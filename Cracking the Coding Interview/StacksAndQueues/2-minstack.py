__author__ = 'ruben'


class MinStack():
    def __init__(self):
        self.data = []  # array of tuples, second tuple is the current min

    def __str__(self):
        s = ''
        for val, min in self.data:
            s += str(val)
            s += ' ' + str(min) if min else '-'
            s += '\n'
        return s

    def push(self, el):
        current_min = self.data[-1][1] if len(self.data) else None
        if current_min is None or el < current_min:
            current_min = el
        self.data.append((el, current_min))
        return self

    def pop(self):
        if not len(self.data):
            raise Exception("Stack is empty")
        else:
            return self.data.pop(-1)[0]

    def min(self):
        return self.data[-1][1]


if __name__ == '__main__':
    s = MinStack()
    s.push(5).push(6).push(3).push(7)
    s.pop()
    print(s)