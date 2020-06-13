// Question 004: Median of Two Sorted Arrays
//
// 2019/04/03

#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums;

        int i = 0, j = 0;
        while(i < nums1.size() && j < nums2.size()) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i++]);
            } else {
                nums.push_back(nums2[j++]);
            }
        }

        while (i < nums1.size()) {
            nums.push_back(nums1[i++]);
        }
        while (j < nums2.size()) {
            nums.push_back(nums2[j++]);
        }

        if (nums.size() % 2) {
            return 1.0 * nums[nums.size() / 2];
        } else {
            return 0.5 * (nums[(nums.size()-1)/2] + nums[(nums.size()+1)/2]);
        }
    }
};
