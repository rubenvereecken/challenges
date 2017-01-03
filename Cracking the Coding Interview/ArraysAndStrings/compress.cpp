/*
    Problem 1.5
*/

#include <iostream>
#include <sstream>
using namespace std;

string compress(string str) {
    stringstream out;
    char last = '\0';
    int count = 0;
    int total = 2;

    for (string::iterator s = str.begin(); s != str.end(); ++s) {
        if (*s == last) {
            ++count;
        } else {
            if (count) {
                out << last;
                out << count;
                total += 2;
            }
            last = *s;
            count = 1;
        }
    }
    out << last;
    out << count;

    if (total > str.size())
        return str;

    return out.str();
}


int main() {
    string str = "aab";
    cout << compress(str) << endl;
    str = "maaa";
    cout << compress(str) << endl;
}
