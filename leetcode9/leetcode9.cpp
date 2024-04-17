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
    bool isPalindrome(int x) {
        string srcStr = to_string(x);
        string str = string(srcStr);

        reverse(srcStr.begin(), srcStr.end());
        if (srcStr == str) {
            return true;
        } else return false;
    }
};
