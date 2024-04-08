#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
/*
双指针
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        int i = 0;
        while (i < nums.size() - 2 ) {
            int left = i + 1;
            int right = nums.size()-1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    results.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    while(nums[right] == nums[right+1] && left < right) right--;
                    while(nums[left] == nums[left-1] && left < right) left++;
                } 
                else if (nums[i] + nums[left] + nums[right] > 0) {
                    right--;
                    while(nums[right] == nums[right+1] && left < right) right--;
                } 
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                    while(nums[left] == nums[left-1] && left < right) left++;
                }
            }
            i++;
            while (nums[i] == nums[i-1] && i < left) i++;
            if (i >= left) {
                break;
            }
        }
        return results;
    }
};



int main() {
    Solution s = Solution();

    vector<int> nums = {0,4,-1,0,3,1,1,0,-3,2,-5,-4,-3,0,0,-3};


    s.threeSum(nums);
}