__author__ = 'ruben'

from TreesAndGraphs.Tree import Tree


def gather_by_level(root):
    nodes = []
    gather_next(root, nodes)
    return nodes


def gather_next(root, nodes, level=0):
    if root is None:
        return
    if len(nodes) <= level:
        nodes.append([])
    nodes[level].append(root)
    gather_next(root.left, nodes, level + 1)
    gather_next(root.right, nodes, level + 1)


if __name__ == '__main__':
    r = Tree.from_sorted_array(list(range(10)))
    for level in gather_by_level(r):
        print(level)