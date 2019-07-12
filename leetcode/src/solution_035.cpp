// Question 035: Search Insert Position
//
// 2019/03/25

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i;
        for (i = 0; i < nums.size(); ++i) {
            if (nums[i] >= target) {
                break;
            }
        }

        return i;
    }
};
