'''
Created on Dec 29, 2011

@author: ruben
'''

from Factorization import trial_division

def get_amount_of_distinct_primes (number):
    uniques = []
    for i in trial_division (number):
        if i not in uniques: uniques.append(i)
    return len(uniques)


if __name__ == '__main__':
    i = 1
    while True:
        print(i)
        if get_amount_of_distinct_primes (i) == 4:
            flag = True
            for j in range(1, 4):
                if get_amount_of_distinct_primes (i + j) != 4: flag = False
            if flag:
                print('First of the four integers:', i)
                print('And here are his factors:', trial_division(i))
                for j in range(1, 4):
                    print('And for', i + j, trial_division(i + j))
                print('------------------------------')
                break
        i += 1