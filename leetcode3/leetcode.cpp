#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, string::iterator> m;
        int maxLen = 0;
        auto left = s.begin();
        auto right = s.begin();
        while (right != s.end()) {  
            if (m.find(*right) == m.end()) {
                m.insert({*right, right});
                right++;
            } else {
                maxLen = maxLen > right - left ? maxLen : right- left;
                auto temp = m.find(*right)->second+1;
                while (left != temp) {
                    m.erase(m.find(*left));
                    left++;
                }
                // m.clear();
            }
        }
        maxLen = maxLen > right - left ? maxLen : right- left;
        return maxLen;
    }
};


int main() {
    auto a = string("abcabcbb");
    auto s = Solution();
    cout << s.lengthOfLongestSubstring(a);


}