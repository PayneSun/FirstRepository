/*
 * LeetCode
 * Question 026: Remove Duplicates from Sorted Array
 * 2019/3/24
 */

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> si;
    	for (size_t i = 0; i < nums.size(); ++i) {
    		si.insert(nums[i]);
    	}
    	nums.clear();

        for (auto it = si.rbegin(); it != si.rend(); ++it) {
    		nums.push_back(*it);
    	}
        sort(nums.begin(), nums.end());

    	return nums.size();
    }
};
