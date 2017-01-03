#include <iostream>
#include <vector>
using namespace std;

int findString(const vector<string>& array, const string& s) {
    int l = 0;
    int h = s.size();
    int lastM = -1;

    while (l < h) {
        int m = (l+h) / 2;
        if (lastM == m)
            break;
        int comp = array[m].compare(s);
        bool isEmpty = array[m].compare("") == 0;
        if (!isEmpty) {
            if (comp == 0)
                return m;
            else if (comp < 0) {
                h = m;
            } else {
                l = m+1;
            }
        } else {
            int left = m-1;
            int right = m+1;
            while (left >= 0 || right < array.size()) {
                if (left >= 0 && array[left].compare(s) == 0)
                    return left;
                if (right < array.size() && array[right].compare(s) == 0)
                    return right;


                if (left >= 0 && array[left].compare("") != 0) {
                    if (array[left].compare(s) < 0)
                        h = left;
                    else
                        l = left+1;
                    break;
                }
                if (right < array.size() && array[right].compare("") != 0) {
                    if (array[right].compare(s) < 0)
                        h = right;
                    else
                        l = right+1;
                    break;
                }
                left -= 1;
                right += 1;
            }
        }
        lastM = m;
    }

    return -1;
}

int main() {
    vector<string> ar1 = {"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
    cout << findString(ar1, "ball") << endl;
    vector<string> ar2 = {"", "", "nowp"};
    cout << findString(ar2, "sexy?") << endl;
}
