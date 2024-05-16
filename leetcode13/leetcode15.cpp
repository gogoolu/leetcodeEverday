#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int num = 0;
        int temp;
        auto it = s.begin();
        while (it != s.end()) {
            if (*it == 'M'){
                num += 1000;
            } else if (*it == 'D') {
                num += 500;
            } else if (it != s.end()-1 && *it == 'C' && *(it+1) == 'D') {
                num += 400;
                it++;
            } else if (it != s.end()-1 && *it == 'C' && *(it+1) == 'M') {
                num += 900;
                it++;
            } else if (*it == 'C') {
                num += 100;
            } else if (*it == 'L') {
                num += 50;
            } else if (it != s.end()-1 && *it == 'X' && *(it+1) == 'L') {
                num += 40; 
                it++;
            } else if (it != s.end()-1 && *it == 'X' && *(it+1) == 'C') {
                num += 90;
                it++;
            } else if (*it == 'X') {
                num += 10;
            } else if (*it == 'V') {
                num += 5;
            } else if (it != s.end()-1 && *it == 'I' && *(it+1) == 'V') {
                num += 4;
                it++;
            } else if (it != s.end()-1 && *it == 'I' && *(it+1) == 'X') {
                num += 9;
                it++;
            } else if (*it == 'I') {
                num += 1;
            }
            it++;
        }
        return num;
    }
};
