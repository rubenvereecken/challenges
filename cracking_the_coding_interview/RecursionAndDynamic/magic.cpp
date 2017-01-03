#include <iostream>
#include <vector>
using namespace std;

int findMagicIndex(const vector<int>& array) {
    int l = 0;
    int h = array.size();

    while (l < h) {
        //cout << l << ' ' << h << endl;
        int m = (l+h) / 2;
        if (m == array[m])
            return m;
        else if (m > array[m])
            l = m+1;
        else
            h = m;
    }
    return -1;
}

int min(int a, int b) {
    return a > b? b : a;
}
int max(int a, int b) {
    return a > b? a : b;
}

int findMagicIndex2(const vector<int>& array, int l=0, int h=-1) {
    if (h == -1)
        h = array.size();

    if (l >= h || l < 0 || h > array.size())
        return -1;

    int m = (l+h) / 2;
    if (m == array[m])
        return m;

    // left
    int left = findMagicIndex2(array, l, min(array[m]+1, m));
    if (left >= 0)
        return left;

    int right = findMagicIndex2(array, max(array[m], m+1), h);
    return right;
}

int main() {
    //vector<int> ar1 = {-4, 0, 1, 2, 4};
    //cout << findMagicIndex2(ar1) << endl;
    vector<int> ar2 = {0, 0, 0, 0, 4, 6};
    cout << findMagicIndex2(ar2) << endl;
}
