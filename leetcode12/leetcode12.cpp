#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>


using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        int temp = 0;
        int a = 1000;
        while (true) {
            temp = num / 1000;
            num %= 1000;
            for (int i = 0; i < temp; i++) {    // 1000
                result.push_back('M');
            }

            temp = num / 100;
            num %= 100;
            RomanAppend(temp, 'C', 'D', 'M', result);

            temp = num / 10;
            num %= 10;
            RomanAppend(temp, 'X', 'L', 'C', result);

            RomanAppend(num, 'I', 'V', 'X', result);

            return result;
        }
    }

    void RomanAppend(int n, char I, char V, char X, string &result) {
        if (n == 4) {   
            result.push_back(I);
            result.push_back(V);
        } else if (n == 9) {
            result.push_back(I);
            result.push_back(X);
        } else if (n >= 5) {
            result.push_back(V);
            for (int i = 5; i < n; i++) {
                result.push_back(I);
            }
        } else if (n < 5) {
            for (int i = 0; i < n; i++) {
                result.push_back(I);
            }
        }
    }
};

int main() {
    Solution s = Solution();

    cout << s.intToRoman(399);
}