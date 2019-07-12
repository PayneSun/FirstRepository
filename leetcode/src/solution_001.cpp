// Question 001: Two Sum
//
// 2019/03/18

#include <vector>


class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::vector<int> result;
		for (std::size_t i = 0; i < nums.size(); ++i) {
			for (std::size_t j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					result.push_back(i);
					result.push_back(j);
					break;
				}
			}
			if (!result.empty()) {
				break;
			}
		}
		return result;
	}
};
