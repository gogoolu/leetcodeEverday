#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> table = {
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };
        vector<string> result;
        for (auto num : digits) {
            vector<string> temp;
            for (auto ch : table.at(num - '1')) {
                for (auto& front : result) {
                    temp.push_back(front + ch);
                }
                if (result.empty()) {
                    temp.push_back(string(1, ch));
                }
            }
            result = temp;
        }
        return result;
    }
};

int main() {
    Solution s;
    auto vec = s.letterCombinations("23");
    for (auto& str : vec) {
        cout << str << endl;
    }
}
