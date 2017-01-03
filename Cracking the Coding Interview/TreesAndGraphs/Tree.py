__author__ = 'ruben'


class Tree:
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None
        self.parent = None

    def __str__(self):
        s = '('
        s += self.left.__str__() if self.left else ''
        s += str(self.data)
        s += self.right.__str__() if self.right else ''
        s += ')'
        return s

    def depth(self):
        left = 0
        right = 0
        if self.left is None and self.right is None:
            return 1
        if self.left:
            left = self.left.depth()
        if self.right:
            right = self.right.depth()
        return max(left, right) + 1

    @staticmethod
    def from_sorted_array(array):
        if len(array) == 0:
            return None
        if len(array) == 1:
            return Tree(array[0])
        i = len(array) // 2
        root = Tree(array[i])
        root.left = Tree.from_sorted_array(array[0:i])
        root.right = Tree.from_sorted_array(array[i+1:len(array)])
        if root.left:
            root.left.parent = root
        if root.right:
            root.right.parent = root
        return root


if __name__ == '__main__':
    r = Tree.from_sorted_array(list(range(8)))
    print(r)
    print(r.depth())
