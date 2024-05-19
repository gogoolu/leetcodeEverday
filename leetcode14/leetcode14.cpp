#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;

        while (index < strs.at(0).size()) {
            char ch = strs.at(0).at(index);
            for (auto& str : strs) {
                if (index >= str.size() || str.at(index) != ch) {
                    return string(str.begin(), str.begin()+index);
                }
            }
            index++;
        }
        return string(strs.at(0).begin(), strs.at(0).begin()+index);
    }
};


int main() {
    Solution s;
    vector<string> strs = {"a"};
    cout << s.longestCommonPrefix(strs);
}

