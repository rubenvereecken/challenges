__author__ = 'ruben'

from itertools import *

#def replace(s, n):


def thing(s):
    perms = list(set(list(permutations(s, len(s)))))
    res = perms[0:len(s)]
    print (perms)



print(thing('lbb'))