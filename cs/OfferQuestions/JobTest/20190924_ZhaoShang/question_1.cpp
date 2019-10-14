// 招商银行网络科技
// question_1.cpp
// 2019/09/24


#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	int n;
	std::cin >> n;

	int x, sum = 0;
	std::vector<int> ivec;
	ivec.reserve(n);
	for (int i = 0; i < n; ++n) {
		std::cin >> x;
		ivec.push_back(x);
		sum += x;
	}
	std::sort(ivec.begin(), ivec.end());

	int dp[n][sum/2+1];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= sum/2; ++j) {
			if (i*j) {
				if (j >= ivec[i-1]) {
					dp[i][j] = std::max(dp[i-1][j], dp[i-1][j-ivec[i-1]]+ivec[i-1]);
				} else {
					dp[i][j] = dp[i-1][j];
				}
			} else {
				dp[i][j] = 0;
			}
		}
	}

	std::cout << dp[n-1][sum/2] << std::endl;

	return 0;
}

/*
6
1 0 1 7 2 4
 */
