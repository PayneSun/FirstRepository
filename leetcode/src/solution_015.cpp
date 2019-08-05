// Question 015: 3Sum
//
// 2019/08/05

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) {
            return std::vector<vector<int>>();
        }

        std::sort(nums.begin(), nums.end());
        std::vector<vector<int>> ivv;
        for (std::size_t i = 0; i < nums.size() - 2; ++i) {
            if (i != 0 && nums[i-1] == nums[i]) {
                continue;
            }
            std::size_t j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    ivv.push_back(std::vector<int>{nums[i], nums[j], nums[k]});
                    while (j < k && nums[j+1] == nums[j]) { ++j; }
                    while (j < k && nums[k-1] == nums[k]) { --k; }
                    ++j;
                    --k;
                }
            }
        }

        return ivv;
    }
};
