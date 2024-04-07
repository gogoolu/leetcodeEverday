// 存在重复元素
#include <iostream>
#include <vector>
#include <unordered_map>


using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int i : nums)
            if (map.insert(pair<int, int>(i, i)).second == false)
                return true;
        return false;
    }
};
