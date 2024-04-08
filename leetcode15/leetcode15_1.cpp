#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
/*
超时
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> results;
        for (vector<int>::iterator ptr1 = nums.begin(); ptr1 < nums.end()-2; ptr1++) {
            for (auto ptr2 = ptr1+1; ptr2 < nums.end()-1; ptr2++) {
                for (auto ptr3 = ptr2+1; ptr3 < nums.end(); ptr3++) {
                    if (*ptr1 + *ptr2 + *ptr3 == 0) {
                        vector<int> temp = {*ptr1, *ptr2, *ptr3};

                        sort(temp.begin(), temp.end());
                        bool flag = false;
                        if (results.size() == 0)
                            flag = true;
                        else 
                        for (auto vec : results) 
                            if (equal(vec.begin(), vec.end(), temp.begin())) {
                                flag = false;
                                break;
                            }
                            else    
                                flag = true;
                        if (flag) 
                            results.push_back(temp);
                    }
                }
            }
        }
        return results;
    }
};



int main() {
    Solution s = Solution();

    vector<int> nums = {-1,0,1,2,-1,-4,-2,-3,3,0,4};


    s.threeSum(nums);
}