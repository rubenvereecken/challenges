#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void reverse(char* str) {
    // str expected to be null-terminated
    char* c = str;
    while (*c != '\0') {
        ++c;
    }
    --c;
    char* f = str;
    while (f < c) {
        char tmp = *f;
        *f++ = *c;
        *c-- = tmp;
    }
}

int main() {
    char str[] = "sexy\0";
    reverse(str);
    cout << str << endl;
}
