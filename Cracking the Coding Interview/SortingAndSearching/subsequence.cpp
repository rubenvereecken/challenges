#include <iostream>
#include <vector>
using namespace std;

void findLongestIncreasingSubsequence(vector<int>& array, int& bestL, int& bestR) {
    int l = bestL = 0;
    int r = bestR = 1;
    int best = 1;

    for (int i = 1; i < array.size(); i++) {
        int el = array[i];
        if (array[i] >= array[i-1]) {
            r = i+1;
        } else {
            l = i;
            r = i + 1;
        }
        if (r-l > best) {
            best = r-l;
            bestL = l;
            bestR = r;
        }
    }
}

int main() {
    vector<int> ar1 = {1, 2, 3, 1, 2, 3, 4};
    vector<int> ar2 = {1, 2, 1, 2, 0, 1, 0};
    int l, r;
    findLongestIncreasingSubsequence(ar1, l, r);
    cout << l << ' ' << r << endl;
    findLongestIncreasingSubsequence(ar2, l, r);
    cout << l << ' ' << r << endl;
}
