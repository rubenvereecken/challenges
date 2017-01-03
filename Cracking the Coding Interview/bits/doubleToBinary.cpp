#include <iostream>
#include <vector>
using namespace std;

string doubleToBinary(double n, int cut=32) {
    int count = 0;
    double track = 1;
    string s;
    s.reserve(cut);

    while (count < cut && n) {
        track /= 2;
        if (n - track >= 0) {
            s.push_back('1');
            n -= track;
        } else {
            s.push_back('0');
        }
        count +=1;
    }
    if (n) {
        return "ERROR";
    } else {
        return "0." + s;
    }
}


int main() {
    cout << doubleToBinary(0.625) << endl;
    cout << doubleToBinary(0.1) << endl;
}
