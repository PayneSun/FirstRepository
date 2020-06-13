// Question 016: 3Sum Closet
//
// 2019/08/05

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int ret = nums[0] + nums[1] + nums[2],
            begin, end, sum;
        for (int i = 0; i < nums.size(); ++i) {
            begin = i + 1;
            end = nums.size() - 1;
            while (begin < end) {
                sum = nums[i] + nums[begin] + nums[end];
                if (abs(sum - target) < abs(ret - target)) {
                    ret = sum;
                }

                if (sum < target) {
                    begin++;
                } else if (sum > target) {
                    end--;
                } else {
                    return ret;
                }
            }
        }

        return ret;
    }
};
