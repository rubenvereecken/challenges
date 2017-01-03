__author__ = 'ruben'


def isBST(root, min=-float('inf'), max=float('inf')):
    left = min < root.left.data < root.data and isBST(root.left, min, root.data) if root.left else True
    right = max > root.right.data > root.data and isBST(root.right, root.data, max) if root.right else True
    return left and right