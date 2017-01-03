'''
Created on Dec 29, 2011

@author: ruben
'''

def create_pentagonal_numbers (amount):
    numbers = []
    for i in range(1, amount + 1):
        number = i * (3 * i - 1) / 2
        numbers.append(number)
    return numbers


if __name__ == '__main__':
    pentagonals = create_pentagonal_numbers (10000)
    found = False
    for i in range(1000, len(pentagonals)):
        for j in range(i + 1, len(pentagonals)):
            print(i, j)
            if (pentagonals[i] + pentagonals[j]) in pentagonals and (pentagonals[j] - pentagonals[i]) in pentagonals:
                print('For', pentagonals[i], 'and', pentagonals[j], 'I found j - i =', pentagonals[j] - pentagonals[i])
                found = True
            if found: break
        if found: break