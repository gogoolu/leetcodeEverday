#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int difference = std::numeric_limits<int>::max();
        int sum;
        for (int firstIndex = 0; firstIndex <= nums.size()-3; firstIndex++) {
            int start = firstIndex + 1;
            int end = nums.size() - 1;
            while (start < end) {
                if (abs(nums.at(firstIndex) + nums.at(start) + nums.at(end) - target) < difference) {
                    difference = abs(nums.at(firstIndex) + nums.at(start) + nums.at(end) - target);
                    sum = nums.at(firstIndex) + nums.at(start) + nums.at(end);
                }
                if (nums.at(firstIndex) + nums.at(start) + nums.at(end) > target) {
                    end--;
                } else if (nums.at(firstIndex) + nums.at(start) + nums.at(end) < target) {
                    start++;
                } else if (nums.at(firstIndex) + nums.at(start) + nums.at(end) == target) {
                    return sum;
                }
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
    vector<int> v = {-1,2,1,-4};
    cout << s.threeSumClosest(v, 1);

}