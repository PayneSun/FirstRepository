/*
 * LeetCode
 *
 * Question 014: Longest Common Prefix
 */

#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string outstr = "";

        if (strs.size() == 0) {
            return outstr;
        } else if (strs.size() == 1) {
            return strs[0];
        }

        int idx = -1;  //index of min length
        for (size_t i = 0; i < strs.size(); ++i) {
            if (strs[i].size() < idx) {
                idx = i;
            }
        }

        for (size_t i = 1; i <= strs[idx].size(); ++i) {
            string pfix = strs[idx].substr(0,i);

            size_t j = 0;
            for (; j < strs.size(); ++j) {
                if (strs[j].find(pfix) != 0) {
                    break;
                }
            }
            if (j == strs.size()) {
                outstr = pfix;
            }
        }

        return outstr;
    }
};
