#include <iostream>
#include <vector>

#define MIN(a, b) ((a)<=(b)?(a):(b))
#define MAX(a, b) ((a)>=(b)?(a):(b))

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        int midIndex1 = (len+1)/2;
        int midIndex2 = (len+1)/2 + (len+1)%2;
        return (getNumberByIndex(nums1, nums2, midIndex1) + getNumberByIndex(nums1, nums2,midIndex2)) / 2.0;
    }

    int getNumberByIndex(vector<int>& nums1, vector<int>& nums2, int index) {
        int removedPartEndIndex1 = 0;
        int removedPartEndIndex2 = 0;
        int index1 = 0;
        int index2 = 0;
        int len1 = nums1.size();
        int len2 = nums2.size();
        int stepSize = 0;

        while(index-removedPartEndIndex1-removedPartEndIndex2 > 0) {
            cout << removedPartEndIndex1+removedPartEndIndex2;
            stepSize = max((index - removedPartEndIndex1 - removedPartEndIndex2)/2, 1);

            index1 = min(removedPartEndIndex1+stepSize, len1);
            index2 = min(removedPartEndIndex2+stepSize, len2);

            if (nums1.at(index1-1) <= nums2.at(index2-1)) {
                removedPartEndIndex1 = index1;
            } else {
                removedPartEndIndex2 = index2;
            }
        }
        return min(nums1.at(index1-1), nums2.at(index2-1));
    }
};

int main() {
    Solution s = Solution();

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};



    cout << s.findMedianSortedArrays(nums1, nums2) << endl;
}