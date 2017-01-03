#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combinations(vector<int> array, int r) {
    if (array.size() == 0 || r == 0)
        return vector<vector<int>>({{}});

    vector<vector<int>> newcombs;

    for (int i = 0; i < array.size() -r + 1; i++) {
        vector<int> shorter;
        for (int j = i+1; j<array.size(); j++) {
            shorter.push_back(array[j]);
        }
        auto combs = combinations(shorter, r-1);
        for (auto comb = combs.begin(); comb != combs.end(); comb++) {
            vector<int> newcomb({array[i]});
            if (comb->size())
                newcomb.insert(newcomb.end(), comb->begin(), comb->end());
            newcombs.push_back(newcomb);
        }
    }
    return newcombs;
}

vector<vector<int>> subsets(vector<int> array) {
    vector<vector<int>> subs;
    for (int i = 1; i <= array.size(); i++) {
        auto combs = combinations(array, i);
        subs.insert(subs.end(), combs.begin(), combs.end());
    }
    return subs;
}


int main() {
    vector<int> ar = {1, 2, 3, 4};
    auto result = subsets(ar);
    cout << result.size() << endl;
    for (auto it = result.begin(); it != result.end(); it++) {
        for (auto iter = it->begin(); iter != it->end(); iter++)
            cout << *iter << ' ';
        cout << endl;
    }
}
