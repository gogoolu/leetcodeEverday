#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> out;
        for (string word : words) {
            word.push_back(separator);
            string str;
            for (char ch : word) {
                if (ch != separator) {
                    str.push_back(ch);
                } else if (!str.empty()) {
                    out.push_back(str);
                    str.clear();
                }
            }
        }
        return out;
    }
};
