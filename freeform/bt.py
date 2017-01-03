__author__ = 'ruben'


class BST():
    def __init__(self, data=None):
        self.data = data
        self.left = None
        self.right = None

    @staticmethod
    def use(data):
        if len(data) == 0:
            return None
        l = len(data)
        m = l / 2
        root = BST(data[m])
        root.left = BST.use(data[0:m])
        root.right = BST.use(data[m+1:l])
        return root

    def inorder(self, f):
        if self.left:
            self.left.inorder(f)
        f(self)
        if self.right:
            self.right.inorder(f)

    def to_array(self):
        a = []
        keep = lambda x: a.append(x.data)
        self.inorder(keep)
        return a

from math import isinf
INF = float('infinity')
def ceil(root, n, sofar=INF):
    if root is None:
        return sofar if not isinf(sofar) else None
    if root.data >= n:
        return ceil(root.left, n, root.data)
    else:
        return ceil(root.right, n, sofar)


def approximate(root, n, small=-INF, large=INF):
    if root is None:
        return None if isinf(small) and isinf(large) else small if abs(n - small) < abs(n - large) else large
    if root.data <= n:
        return approximate(root.right, n, root.data if root.data > small else small, large)
    else:
        return approximate(root.left, n, small, root.data if root.data < large else large)

if __name__ == '__main__':
    r = BST.use(range(0, 21, 2))
    print(r.to_array())
    assert ceil(r, 19) == 20
    assert ceil(r, 14) == 14
    assert ceil(r, 21) is None
    assert approximate(r, 21) == 20
    assert approximate(r, 19) == 20
    assert approximate(r, -100) == 0