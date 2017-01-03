__author__ = 'ruben'

from TreesAndGraphs.Tree import Tree


def is_balanced(root):
    return is_balanced_helper(root)[1]

def is_balanced_helper(root):
    if root is None:
        return 0, True
    left = is_balanced_helper(root.left)
    right = is_balanced_helper(root.right)

    return max(left[0], right[0]), left[1] and right[1] and abs(left[0] - right[0]) <= 1


if __name__ == '__main__':
    r = Tree.from_sorted_array(list(range(10)))

    print(is_balanced(r))