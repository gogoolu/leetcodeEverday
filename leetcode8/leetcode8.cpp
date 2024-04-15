#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <limits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        string::iterator p = s.begin();
        int result = 0;
        bool isNagative = false;
        while (p < s.end()) {
            if (isdigit(*p)) {
                if (isNagative) {
                    if (result < (numeric_limits<int>::min() + (*p-'0'))/10)
                        return numeric_limits<int>::min();
                    else 
                        result = result * 10 - (*p - '0');
                } else {
                    if (result > (numeric_limits<int>::max() - (*p-'0'))/10)
                        return numeric_limits<int>::max();
                    else 
                        result = result * 10 + (*p - '0');
                }
            } else if (p > s.begin() && isdigit(*(p-1)) ) {
                break;
            } else if (*p == '-' && p+1 < s.end() && isdigit(*(p+1)) ) {
                isNagative = true;
            } else if (*p == '+' && p+1 < s.end() && isdigit(*(p+1)) ) {
                isNagative = false;
            } else if (*p == ' ') {

            } else break;

            p++;
        }
        return result;
    }
};

int main() {
    auto s = Solution();
    // cout << s.myAtoi("words and 987") << endl;
    // cout << s.myAtoi("42") << endl;
    // cout << s.myAtoi("   -42") << endl;
    // cout << s.myAtoi("4193 with words") << endl;
    // cout << s.myAtoi("-91283472332") << endl;
    // cout << s.myAtoi("+1") << endl;
    // cout << s.myAtoi("00000-42a1234") << endl;
    cout << s.myAtoi("  0000000000012345678") << endl;
    // cout << numeric_limits<int>::min() << endl;
    // -2147483648
    // -91283472332
}