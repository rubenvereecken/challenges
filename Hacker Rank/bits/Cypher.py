'''
/*
__author__ = 'ruben'

n, k = map(int, input().split(' '))
num = int(input(), 2)
t = n + k - 1
i = 1 << t-1

b = []

for _ in range(n):
    current = bool(i & num)
    #print(current, b[-k+1:])
    for bit in b[-k+1:]:
        current ^= bit
    b.append(current)
    i >>= 1

print(''.join(map(lambda x: str(int(x)), b)))
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

std::string dec2bin(unsigned n)
{
    std::string res;

    while (n)
    {
        res.push_back((n & 1) + '0');
        n >>= 1;
    }

    if (res.empty())
        res = "0";
    else
        std::reverse(res.begin(), res.end());
 
   return res;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, k;
    cin >> n >> k;
    int t = n+k-1;
    string str;
    cin >> str;
    
    unsigned num = stoi(str, 0, 2);
    unsigned result = 0;
    
    for (int j = t-1; j >= k-1; --j) {
        int i = j-k+1;
        bool current = bool((1 << j) &num);
        int m = min(n, i+k);
        //cout << j << endl;
        for (int l= i+1; l < m; l++) {
            bool thatbit = bool((1 << l) & result);
            //cout << thatbit << " for l " << l << endl;
            current ^= bool((1 << l) & result);
        }
        result |= unsigned(current) << i;
        //cout << dec2bin(result) << endl;
    }
        
    cout << dec2bin(result) << endl;
        
    return 0;
}
'''