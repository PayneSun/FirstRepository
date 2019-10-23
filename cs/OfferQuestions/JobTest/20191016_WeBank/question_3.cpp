// 微众银行-后端数据开发

#include <iostream>
#include <vector>
#include <algorithm>


int main() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; ++i) {
		int n, tmp;
		std::cin >> n;

		std::vector<int> ivec;
		for (int j = 0; j < n * n; ++j) {
				std::cin >> tmp;
				ivec.push_back(tmp);
		}

		std::sort(ivec.rbegin(), ivec.rend());

		int cnt = 0;
		for (int j = n * n - 1; j >= 0; --j) {
			if (j > 0 && ivec[j] != ivec[j]) {
				std::cout << ivec[j] << " ";
			} else if () {

			}
		}

		std::cout << std::endl;
	}

	return 0;
}

/*
 4
 0 1 1 1
 0 2 1 2
 0 2 2 2
 0 2 0 2

 8
 */
