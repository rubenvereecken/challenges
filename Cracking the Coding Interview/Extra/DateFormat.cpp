
#include <iostream>
#include <map>
#include <iomanip>
#include <stdexcept>

using namespace std;

map<string, int> monthMap {
{"jan", 1}, {"feb", 2}, {"mar", 3}

};

string toLower(string str) {
    string out = "";

    for (string::iterator it = str.begin(); it != str.end(); ++it) {
        if (*it <= 'Z' && *it >= 'A') {
            out += 'a' + (*it) - 'A';
        } else {
            out += *it;
        }
    }

    return out;
}

int mystoi(const string& str) {
    int out = 0;
    int d = 1;
    for (string::const_reverse_iterator it = str.crbegin(); it != str.crend(); ++it) {
        if (*it < '0' || *it > '9') {
            throw runtime_error("Encountered non-digit character.");
        }
        out += d * (*it - '0');
        d *= 10;
    }

    return out;
}


int main() {
    int total;
    cin >> total;
    const string digits = "0123456789";

    for (int i = 0; i < total; ++i) {
        string dayIn, monthIn, yearIn;
        cin >> dayIn >> monthIn >> yearIn;

        int dayNum = mystoi(dayIn.substr(0, dayIn.find_first_not_of(digits)));
        int monthNum = monthMap[toLower(monthIn.substr(0, 3))];

        cout << yearIn;
        cout << '-' << setfill('0') << setw(2) << monthNum;
        cout << '-' << setfill('0') << setw(2) << dayNum << endl;

    }
}
