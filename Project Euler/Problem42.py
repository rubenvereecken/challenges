'''
Created on Dec 29, 2011

@author: ruben
'''

def generate_triangles (amount):
    lst = []
    for i in range(1, amount + 1):
        lst.append(int(0.5 * i * (i + 1)))
    return lst


if __name__ == '__main__':
    words = open('words.txt', 'r')
    strng = words.readline()
    words.close()
    cleanwords = strng.split(',')
    for i, word in enumerate(cleanwords):
        newword = word[1:-1]
        cleanwords[i] = newword
    
    totalTriangles = 0
    triangleList = generate_triangles(50)
    print(triangleList)
    for word in cleanwords:
        wordvalue = 0
        for letter in word:
            wordvalue += ord(letter) - 64
        if wordvalue in triangleList: totalTriangles += 1
    
    print('Found a total of', totalTriangles, 'triangle words in inspected file.')
    
        