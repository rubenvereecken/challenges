#include <iostream>
#include <vector>
using namespace std;

int skips2(int k) {
    if (k < 0)
        return 0;
    if (k == 0)
        return 1;
    return skips2(k-1) + skips2(k-2) + skips2(k-3);
}


int main() {
    cout << skips2(3) << endl;
    cout << skips2(4) << endl;
    cout << skips2(5) << endl;
}
