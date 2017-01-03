'''
Created on Dec 29, 2011

@author: ruben
'''

if __name__ == '__main__':
    someList = []
    for i in range(2, 101):
        for j in range(2, 101):
            current = i ** j
            if current not in someList: someList.append(current)
    print('I found a total of', len(someList), 'unique terms.')