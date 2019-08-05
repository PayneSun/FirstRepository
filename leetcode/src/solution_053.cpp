// Question 053: Maximum Subarray
//
// 2019/08/05

#include <string>
#include <vector>
#include <sstream>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0], sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            sum = max(nums[i], sum+nums[i]);
            ret = max(ret, sum);
        }

        return ret;
    }
};
