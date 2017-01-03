def find_palindrome_index(s):
    n = len(s)
    for i in range(len(s) // 2):
        if s[i] != s[n-i-1]:
            left_check = s[i+1] == s[n-i-1]
            if left_check and is_palindrome(s[i+1:n-i]):
                return i
            else:
                return n-i-1
    return -1

for _ in range(int(input())):
    print(find_palindrome_index(input()))

def is_palindrome(s):
    n = len(s)
    for i in range(n // 2):
        if s[i] != s[n-i-1]:
            return False
    return True