// Question 027: Remove Element
//
// 2019/03/25

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int index = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[index++] = nums[i];
            }
        }

        nums.erase(nums.begin() + index, nums.end());

        return index;
    }
};
