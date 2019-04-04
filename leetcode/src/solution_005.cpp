/*
 * LeetCode
 * Question 005: Longest Palindromic Substring
 * 2019/4/4
 */

#include <string>
#include <string>

using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
            return s;
        }

        const int n = s.size();
		int start = 0, end = 0;
		bool dp[n][n];
		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j < n; ++j) {
				dp[i][j] = (s[i] == s[j]) && (j - i < 3 || dp[i+1][j-1]);

                if(dp[i][j] && (j - i > end - start)) {
					start = i;
					end = j;
				}
			}
		}

        return s.substr(start, end - start + 1);
	}
};
