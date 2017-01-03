'''
Created on Dec 27, 2011

@author: ruben
'''
literals = {1:'I', 5:'V', 10:'X', 50:'L', 100:'C', 500:'D', 1000:'M'}
values = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}


def translate_up_to_five (num):
    if num == 0:
        return ''
    elif 0 < num < 4:
        return num * literals[1]
    elif num == 4:
        return literals[1] + literals[5]
    elif num == 5:
        return literals[5]


def translate_to_ten (num):
    if num <= 5:
        return translate_up_to_five (num)
    elif num < 9:
        return literals[5] + translate_up_to_five (num - 5)
    elif num == 9:
        return literals[1] + literals[10]
    
    

def translate_up_to_fifty (num):
    if num == 0:
        return ''
    elif 0 < num < 4:
        return num * literals[10]
    elif 4 <= num < 5:
        return literals[10] + literals[50]
    elif num >= 5:
        return literals[50]
    

def translate_to_one_hundred (num):
    if num <= 5:
        return translate_up_to_fifty (num)
    elif num < 9:
        return literals[50] + translate_up_to_fifty (num - 5)
    elif num == 9:
        return literals[10] + literals[100] 


def translate_up_to_fivehundred (num):
    if num == 0:
        return ''
    elif 0 < num < 4:
        return num * literals[100]
    elif 4 <= num < 5:
        return literals[100] + literals[500]
    elif num >= 5:
        return literals[500]
        

def translate_to_one_thousand (num):
    if num <= 5:
        return translate_up_to_fivehundred (num)
    elif num < 9:
        return literals[500] + translate_up_to_fivehundred(num - 5)
    elif num == 9:
        return literals[100] + literals[1000] 
    
    
def translate_over_one_thousand (num):
    return num * literals[1000]
    

def translate_roman (num):
    strng = str(num)
    length = len(strng)
    final = ''
    for i in strng:
        if length == 1:
            final += translate_to_ten(int(i))
        elif length == 2:
            final += translate_to_one_hundred(int(i))
        elif length == 3:
            final += translate_to_one_thousand(int(i))
        elif length == 4:
            final += translate_over_one_thousand(int(i))
        length -= 1
    return final


def translate_back (literal):
    first = 'VX'
    second = 'LC'
    third = 'DM'
    returnval = 0
    skip = False
    for index, l in enumerate(literal):
        if skip:
            skip = False
            continue
        if l == 'I':
            if index + 1 != len(literal) and literal[index + 1] in first:
                returnval += values[literal[index + 1]] - values[l]
                skip = True
                continue
            else:
                returnval += values[l]
                
        elif l == 'X':
            if index + 1 != len(literal) and literal[index + 1] in second:
                returnval += values[literal[index + 1]] - values[l]
                skip = True
                continue
            else:
                returnval += values[l]
                 
        elif l == 'C':
            if index + 1 != len(literal) and literal[index + 1] in third:
                returnval += values[literal[index + 1]] - values[l]
                skip = True
                continue     
            else:
                returnval += values[l]
                
        else:
            returnval += values[l]
                
    return returnval
        
        
def optimize (literal):
    return translate_roman(translate_back(literal))


def count_savings (literal):
    return len(literal) - len(optimize(literal))

if __name__ == '__main__':
    roman = open('roman.txt', 'r')
    nice = roman.readlines()
    for i in range(len(nice) - 1):
        nice[i] = nice[i][0:-1]
    totalSum = 0
    count = 1
    for i in nice:
        print('------'+str(count)+'------')
        count += 1
        print('Old literal:', i)
        print('New literal:', optimize(i))
        print('In Arabic:', translate_back(i))
        print('Total saved:', count_savings(i))
        totalSum += count_savings(i)
        print('Total saved so far', totalSum)
        print()
    roman.close()
    print('A total of', totalSum, 'literals have been saved.')