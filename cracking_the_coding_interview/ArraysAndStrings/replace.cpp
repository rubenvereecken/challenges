/*
    Problem 4
*/

#include <iostream>
#include <string>
using namespace std;

void replaceSpaces(char* str, int length) {
    int spaces = 0;
    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') ++spaces;
    }
    int newLength = length + 2 * spaces;
    int lastI = newLength - 1;
    int i = 0;

    for (int i = length-1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[lastI--] = str[i];
        } else {
            str[lastI--] = '0';
            str[lastI--] = '2';
            str[lastI--] = '%';
        }
    }
}

int main() {
    char str[17] = "sexy ladeh m    ";
    int len = 12;
    cout << str << endl;
    replaceSpaces(str, len);
    cout << str << endl;
}
