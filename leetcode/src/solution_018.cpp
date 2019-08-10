// Question 018: 3Sum
//
// 2019/08/08

#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        string str;
        set<string> sset;
        vector<vector<int>> rvec;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                for (int m = j + 1; m < nums.size(); ++m) {
                    for (int n = m + 1; n < nums.size(); ++n) {
                        if (nums[i]+nums[j]+nums[m]+nums[n] == target) {
                            vector<int> ivec{nums[i],nums[j],nums[m],nums[n]};
                            sort(ivec.begin(), ivec.end());
                            str.assign(to_string(ivec[0]) + to_string(ivec[1]) + to_string(ivec[2]) + to_string(ivec[3]));
                            if (sset.find(str) == sset.end()) {
                                sset.insert(str);
                                rvec.push_back(ivec);
                            }
                        }
                    }
                }
            }
        }

        return rvec;
    }
};
