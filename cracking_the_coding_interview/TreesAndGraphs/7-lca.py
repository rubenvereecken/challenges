__author__ = 'ruben'

from TreesAndGraphs.Tree import Tree

def findLCA(first, second):
    df = first.depth()
    ds = second.depth()
    deepest, deepdepth, highest, highdepth = (first, df, second, ds) if df > ds else (second, ds, first, df)

    while deepdepth > highdepth:
        deepest = deepest.parent
        deepdepth -= 1

    while deepest != highest:
        deepest = deepest.parent
        highest = highest.parent

    return deepest