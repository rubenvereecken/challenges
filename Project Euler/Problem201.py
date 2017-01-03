'''
Created on Dec 29, 2011

@author: ruben
'''

from itertools import combinations

def remove_duplicates (lst):
    clean_list = []
    flagged = []
    for i in range(len(lst)): 
        if not (lst[i] in lst[i + 1:] or lst[i] in flagged):
            clean_list.append(i)
        if lst[i] not in flagged: flagged.append(lst[i])
    return clean_list

if __name__ == '__main__':
    special_list = []
    for i in range(1, 101):
        special_list.append(i ** 2)
    sum_list = []
    for i in combinations(special_list, 50):
        sum_list.append(sum(i))
    cleansums = remove_duplicates (sum_list)
    print('Sum of cleaned sums is', sum(cleansums))