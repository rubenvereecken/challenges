#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<string> groupAnagrams(vector<string> strings) {
    unordered_map<string, vector<string>> anagrams;

    for (int i = 0; i < strings.size(); ++i) {
        string cpy(strings[i]);
        sort(cpy.begin(), cpy.end());
        auto found = anagrams.find(cpy);

        if (found != anagrams.end()) {
            anagrams[cpy].push_back(strings[i]);
        } else {
            anagrams.emplace(cpy, vector<string>({strings[i]}));
        }
    }

    vector<string> grouped;
    grouped.reserve(strings.size());
    for (auto it = anagrams.begin(); it != anagrams.end(); ++it) {
        grouped.insert(grouped.end(), it->second.begin(), it->second.end());
    }

    return grouped;
}

int main() {
    vector<string> words = {"smexy", "nom", "mesxy"};
    vector<string> result = groupAnagrams(words);
    
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i] << endl;
    }

}
