#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int area = (right-left) * min(height.at(left), height.at(right));
        while (right > left) {
            if (height.at(left) < height.at(right)) {
                left++;
            } else {
                right--;
            }
            area = max(area, (right-left) * min(height.at(left), height.at(right)));
        }
        return area;
    }
};