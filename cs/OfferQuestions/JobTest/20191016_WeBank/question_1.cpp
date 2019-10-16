// 微众银行-后端数据开发

#include <iostream>
#include <vector>

int main() {
	int n, t;
	std::cin >> n;

	std::vector<int> ivec;
	for (int i = 0; i < n; ++i) {
		std::cin >> t;
		ivec.push_back(t);
	}

	int maxIndex = 0;
	for (int i = 0; i < n; ++i) {
		if (ivec[maxIndex] < ivec[i]) {
			maxIndex = i;
		}
	}

	int sum = 0;
	for (int i = 0; i < n; ++i) {
		if (i + 1 < n && i < maxIndex && ivec[i] > ivec[i + 1]) {
			sum += ivec[i];
		} else if (i > maxIndex && ivec[i]) {
			sum += ivec[i];
		}
	}

	std::cout << sum << std::endl;

	return 0;
}

/*
 4
 8 1 2 3

 6
 */
