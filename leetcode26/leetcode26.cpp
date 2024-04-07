#include <vector>

using namespace std;

#define DEBUG false



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // vector<int>::iterator left = nums.begin();
        // vector<int>::iterator right = left;
        // while(right != nums.end()) {
        //     if (*left >= *right) {
        //         right++;
        //     } else {
        //         left++;
        //         *left = *right;
        //         right++;
        //     }
        // }
        // return left - nums.begin() + 1;

        size_t left = 0;
        size_t right = 0;
        while (right != nums.size()) {
            if (nums[left] >= nums[right]) {
                right++;
            } else {
                left++;
                nums[left] = nums[right];
                right++;
            }
        }
        return left + 1;
    }
};

int main() {
    Solution s = Solution();

    vector<int> nums = {1, 1, 2};


    s.removeDuplicates(nums);
}