#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int maxLen = 1;
        int index = 0;
        vector<vector<bool>> isPd(s.length(), vector<bool>(s.length()));

        if (s.length() == 1)
            return s;

        for (int i = 0; i < s.length(); i++)
            isPd[i][i] = true;

        for (int len = 2; len <= s.length(); len++) {
            for (int left = 0; left < s.length(); left++) {
                int right = left + len - 1;
                
                if (right >= s.length())
                    break;
                
                if (s.at(left) == s.at(right)) {
                    if (isPd[left+1][right-1] || left + 1 == right) {
                        // maxLen = max(maxLen, len);
                    
                        if (maxLen < len) {
                            maxLen = len;
                            index = left;
                        }

                        isPd[left][right] = true;
                    }
                }
            }
        }
        return s.substr(index, maxLen);
    }
};


int main() {
    Solution s = Solution();

    // vector<int> nums = {0,4,-1,0,3,1,1,0,-3,2,-5,-4,-3,0,0,-3};
    string str = string("babad");


    cout << s.longestPalindrome(str);
}