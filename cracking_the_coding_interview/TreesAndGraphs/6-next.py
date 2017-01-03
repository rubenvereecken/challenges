__author__ = 'ruben'

from TreesAndGraphs.Tree import Tree

def findNext(root):
    if root.right:  # leftmost child of right
        current = root.right
        while current.left:
            current = current.left
        return current
    else:           # first ancestor to the right
        current = root
        while current.parent and current.parent.right == current:
            current = current.parent
        return current.parent


if __name__ == '__main__':
    r = Tree.from_sorted_array(list(range(8)))
    node = r.right
    n = findNext(node)
    print(r)
    print(node)
    print(n)