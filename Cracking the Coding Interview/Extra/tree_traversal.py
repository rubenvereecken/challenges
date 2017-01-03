__author__ = 'ruben'


class Tree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

    def __str__(self):
        s = '('
        s += self.left.__str__() if self.left else ''
        s += str(self.data)
        s += self.right.__str__() if self.right else ''
        s += ')'
        return s


def print_data(root):
    print(root.data)


def inorder_iteratively(root, f):
    """
    no parent pointers
    """
    current = root
    stack = []
    popped = False

    while current:
        if current.left and not popped:  # left child available
            stack.append(current)
            current = current.left
            popped = False
        else:  # need to go right
            f(current)
            if current.right:
                popped = False
                current = current.right
            else:
                if len(stack):
                    popped = True
                    current = stack.pop(-1)
                else:  # reached end of stack
                    return


def preorder_recursively(root, f):
    if root is None:
        return
    else:
        f(root)
        preorder_recursively(root.left, f)
        preorder_recursively(root.right, f)


def preorder_iteratively(root, f):
    current = root
    stack = []

    while current:
        f(current)
        if current.right:
            if current.left:
                stack.append(current.right)
                current = current.left
            else:
                current = current.right
        elif current.left:
            current = current.left
        elif len(stack):
            current = stack.pop(-1)
        else:
            return


def postorder_recursively(root, f):
    if root is None:
        return
    else:
        postorder_recursively(root.left, f)
        postorder_recursively(root.right, f)
        f(root)


def postorder_iteratively(root, f):
    current = root
    stack = []
    popped = None

    while current:
        if current.left is None and current.right is None:
            f(current)
            if len(stack):
                current = stack.pop(-1)
                popped = current
            else:
                return


if __name__ == '__main__':
    a = Tree(1)
    b = Tree(2)
    c = Tree(3)
    d = Tree(4)
    e = Tree(5)
    f = Tree(6)
    g = Tree(7)

    e.left = b
    e.right = g
    g.left = f
    b.left = a
    b.right = c
    c.right = d

    # e is root
    root = e
    postorder_recursively(root, print_data)