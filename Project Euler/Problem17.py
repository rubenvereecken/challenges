'''
Created on Dec 27, 2011

@author: ruben
'''
numbers = {1:'one', 2:'two', 3:'three', 4:'four', 5:'five', 6:'six', 7:'seven', 8:'eight', 9:'nine', 0:''}
tenPlus = {11:'eleven', 12:'twelve', 13:'thirteen', 14:'fourteen', 15:'fifteen', 16:'sixteen',
        17:'seventeen', 18:'eighteen', 19:'nineteen', 0:''}
tens = {10:'ten', 20:'twenty', 30:'thirty', 40:'forty', 50:'fifty', 60:'sixty', 70:'seventy', 80:'eighty', 90:'ninety'}
hundred = 'hundred'
thousand = 'thousand'
hyphen = '-'



def ten_to_ninetynine(num):
    if len(str(num)) == 2:
        if num % 10 == 0:
            return tens[num]
        elif 10 < num < 20:
            return tenPlus[num]
        else:
            return tens[num - (num % 10)] + hyphen + numbers[num % 10]
    else: return 'Invalid length'
    

def number_to_string(i):
    if len(str(i)) == 1:
        return numbers[i]
    if len(str(i)) == 2:
        return ten_to_ninetynine(i)
    if len(str(i)) == 3:
        result = numbers[int(str(i)[0])] + ' ' + hundred
        if (i % 100 != 0):
            result += ' and '
            if (i % 100 < 10):
                result += numbers[i % 100]
            else:
                subten = i % 100
                result += ten_to_ninetynine(subten)
        return result
    if len(str(i)) == 4:
        return numbers[int(str(i)[0])] + ' ' + thousand

def clean(strng):
    cleanstrng = ''
    for i in strng:
        if i != ' ' and i != '-':
            cleanstrng += i
            print(i)
            print(cleanstrng)
    return cleanstrng

if __name__ == '__main__':

    
    print('5 becomes', number_to_string(5))
    print('817 becomes', number_to_string(817))
    count = 0
    for i in range (1, 1001): 
        print(clean(number_to_string(i)))
        count += len(clean(number_to_string(i)))
    print('Total count of all desired letters is', count)
