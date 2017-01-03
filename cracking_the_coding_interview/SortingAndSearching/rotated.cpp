#include <iostream>
#include <vector>
using namespace std;

int findStart(const vector<int>& array) {
    int l = 0;
    int h = array.size();

    while (l < h) {
        int m = (l + h) / 2;
        if (m < array.size() - 1) {
            if (array[m+1] < array[m])
                return m+1;
            if (array[m] > array[0]) {
                l = m+1;
            } else {
                h = m;
            }
        } else if (array[m] > array[0]){
            return 0;
        }
    }
    return -1;
}

int find(const vector<int>& array, int k) {
    int l = 0;
    int h = array.size();

    while (l < h) {
        int m = (l + h) / 2;
        if (k == array[m])
            return m;
        if (k < array[0]) {
            if (array[m] > k && array[m] < array[0]) {
                h = m;
            } else if (array[m] > k) {
                l = m+1;
            } else { // smaller
                l = m;
            }
        } else {
            if (array[m] < k && array[m] < array[0]) {
                h = m;
            } else if (array[m] < k) {
                l = m+1;
            } else {
                h = m;
            }
        }
    }

    return -1;
}

int main() {
    // vectors are rotated
    vector<int> ar = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    vector<int> ar2 = {1, 2, 3, 4};
    vector<int> ar3 = {4, 1, 3, 4};
    cout << findStart(ar) << endl;
    cout << findStart(ar2) << endl;
    cout << findStart(ar3) << endl;

    cout << find(ar, 5) << endl;
    cout << find(ar2, 3) << endl;
    cout << find(ar3, 5) << endl;
}
