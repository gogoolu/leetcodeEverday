#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int length1 = nums1.size();
        int length2 = nums2.size();
        int index1 = (length1 + length2 + 1)/2;
        int index2 = index1 + (length1 + length2 + 1)%2;

        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        vector<int>::iterator cursor = it1;
        int midian1 = 0;
        int midian2 = 0;

        if (length1 == 0) {
            return (nums2.at(index1-1) + nums2.at(index2-1))/2.0;
        }
        if (length2 == 0) {
            return (nums1.at(index1-1) + nums1.at(index2-1))/2.0;
        }
        int i = 0;
        while (it1 != nums1.end() && it2 != nums2.end()) {
            cursor = *it1 <= *it2 ? it1++: it2++;
            i++;
            if (i == index1)
                midian1 = *cursor;
            if (i == index2)
                midian2 = *cursor;
        }
        
        while (it1 == nums1.end() && it2 != nums2.end()) {
            cursor = it2++;
            i++;
            if (i == index1)
                midian1 = *cursor;
            if (i == index2) 
                midian2 = *cursor;
        }
        while (it2 == nums2.end() && it1 != nums1.end()) {
            cursor = it1++;
            i++;
            if (i == index1)
                midian1 = *cursor;
            if (i == index2) 
                midian2 = *cursor;
        }

        cout << "index1: " << index1 << endl;
        cout << "index2: " << index2 << endl;
        cout << "midian1: " << midian1 << endl;
        cout << "midian2: " << midian2 << endl;


        return (midian1 + midian2)/2.0; 
    }
};

int main() {
    Solution s = Solution();

    vector<int> nums1 = {2, 2, 2, 2};
    vector<int> nums2 = {2, 2, 2};

    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}