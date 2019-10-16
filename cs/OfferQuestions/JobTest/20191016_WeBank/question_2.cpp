// 微众银行-后端数据开发

#include <iostream>
#include <vector>

const int maxn = 50 + 1;
int compass[maxn][maxn];

int diff(int n, int i, int j) {
	int s = 0, d = 0;
	if (compass[i][j] != 0) {
		// 上
		if (i - 1 >= 0 && compass[i - 1][j] && compass[i - 1][j] == compass[i][j]) {
			s++;
		} else if (i - 1 >= 0 && compass[i - 1][j] && compass[i - 1][j] != compass[i][j]) {
			d++;
		}

		//左
		if (j - 1 >= 0 && compass[i][j - 1] && compass[i][j - 1] == compass[i][j]) {
			s++;
		} else if (j - 1 >= 0 && compass[i][j - 1] && compass[i][j - 1] != compass[i][j]) {
			d++;
		}

		//下
		if (i + 1 < n && compass[i + 1][j] && compass[i + 1][j] == compass[i][j]) {
			s++;
		} else if (i + 1 < n && compass[i + 1][j] && compass[i + 1][j] != compass[i][j]) {
			d++;
		}

		//右
		if (j + 1 < n && compass[i][j + 1] && compass[i][j + 1] == compass[i][j]) {
			s++;
		} else if (j + 1 < n && compass[i][j + 1] && compass[i][j + 1] != compass[i][j]) {
			d++;
		}
	}

	return s > d ? s - d : d - s;
}

int main() {
	int n, t, sum = 0;
	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> t;
			compass[i][j] = t;
			if (t) {
				sum += 1;
			}
		}
	}

	int cnt = 0;
	std::vector<int> ivec;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (diff(n, i, j) > 2) {
//				std::cout << diff(n,i,j) << "---" << std::endl;
				cnt++;
			}
		}
	}
	std::cout << sum - cnt << std::endl;

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
