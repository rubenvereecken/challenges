__author__ = 'ruben'

def find_path_sums(root, k):
    success = []
    if k == root.data:
        success.append([root])
    find_path_sums(root.left, k, [[root.data]], success)
    find_path_sums(root.right, k, [[root.data]], success)
    return success
