#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1) {
            return s;
        }
        string result;
        int gap = 2*numRows - 2;
        for(int i = 0; i < numRows; i++) {
            int current_gap = gap-i*2;

            for(int index = i; index < s.size(); ) {
                // int index = i;
                if (current_gap == 0)
                    current_gap = gap;

                result.push_back(s.at(index));
                index += current_gap;
                current_gap = gap - current_gap;
                
            }
        }
        return result;
    }
};


int main() {
    Solution s = Solution();

    string str = string("PAYPALISHIRING");


    cout << s.convert(str, 4) << endl;
}