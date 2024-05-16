#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> dpFront = {1};
        vector<int> dpBack = {1};
        for (int i = 0; i < nums.size(); i++) {
            dpFront.push_back(*(dpFront.end()-1) * nums.at(i));
        }
        for (int j = nums.size(); j > 0; j--) {
            dpBack.push_back(*(dpBack.end()-1) * nums.at(j-1));
        }
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            result.push_back(dpFront.at(i) * dpBack.at(nums.size()-i-1));
        }
        return result;
    }
};

int main() {
    Solution s = Solution();

    // vector<int> nums = {1, 2, 3};
    vector<int> nums = {-1,1,0,-3,3};
    s.productExceptSelf(nums);

}