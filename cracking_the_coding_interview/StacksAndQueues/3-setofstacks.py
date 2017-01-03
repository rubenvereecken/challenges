__author__ = 'ruben'


class SetOfStacks():
    def __init__(self, threshold=4):
        self.stacks = []
        self.threshold = threshold

    def push(self, el):
        if len(self.stacks) and len(self.stacks[-1]) == self.threshold or not len(self.stacks):
            self.stacks.append([el])
        else:
            self.stacks[-1].append(el)

    def pop(self):
        if not len(self.stacks):
            raise Exception('Empty stacks')
        else:
            val = self.stacks[-1].pop(-1)
            if not len(self.stacks[-1]):
                self.stacks.pop(-1)
            return val