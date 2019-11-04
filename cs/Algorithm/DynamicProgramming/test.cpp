// 动态规划：0-1背包
// 2019.11.04
//


#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::vector<int> wvec = {0,2,2,6,5,4},
					 vvec = {0,6,3,5,4,6};

	int n = 5, W = 10;
	int dp[n+1][W+1];
	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (i * j == 0) {
				dp[i][j] = 0;
			} else if (wvec[i] > j) {
				dp[i][j] = dp[i-1][j];
			} else {
				dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-wvec[i]] + vvec[i]);
			}
		}
	}

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= W; ++j) {
			std::cout << dp[i][j] << "\t";
		}
		std::cout << std::endl;
	}

	return 0;
}
