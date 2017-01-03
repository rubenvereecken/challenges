#include <iostream>
#include <vector>
using namespace std;

void merge(int* A, int* B, int lenA, int lenB) {
    int totalLen = lenA + lenB;
    int currentP = totalLen-1;
    lenA--; lenB--;

    while (lenB >= 0) {
        if (A[lenA] <= B[lenB]) {
            A[currentP--] = B[lenB--];
        } else {
            A[currentP--] = A[lenA--];
        }
    }
}

int main() {
    int A[6] = {1, 4, 6, 0, 0, 0};
    int B[2] = {2, 4};
    merge(A, B, 3, 2);
    for (int i = 0; i < 6; ++i)
        cout << A[i] << ' ';
    cout << endl;
}
