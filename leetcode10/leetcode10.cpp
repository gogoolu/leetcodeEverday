#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <limits>
#include <stack>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        string::iterator it_p = p.begin();
        string::iterator it_s = s.begin();
        while (it_p != p.end() && it_s != s.end()) {
            if (*it_p == *it_s) {
                it_s++;
                it_p++;
            } else if (*it_p == '.') {
                it_s++;
                it_p++;
            } else if (*it_p == '*' && it_p != p.begin()) {
                char matchChar = *(it_p-1);
                while ( (*it_s == matchChar || matchChar == '.') && it_s != s.end() ) {
                    it_s++;
                }
                it_p++;
            } else {
                it_p++;
            }
        }
        if (it_s == s.end() && it_p == p.end())
            return true;
        else return false;
        // return it_s == s.end();
    }
};


int main() {
    auto s = Solution();
    cout << s.isMatch("ab", ".*c");
}