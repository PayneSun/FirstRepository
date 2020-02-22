// ÌÚÑ¶ºóÌ¨
// question_5.cpp
// 2019/09/20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, k;
	std::cin >> n >> k;

	vector<int> ivec;
	int x;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		ivec.push_back(x);
	}

	for (int i = 0; i < k; ++i) {
		x = ivec[0];
		for (auto r : ivec) {
			if (x) {
				if (r && r < x) {
					x = r;
				}
			} else {
				x = r;
			}
		}
		std::cout << x << std::endl;

		for (auto &r : ivec) {
			if (r) {
				r -= x;
			}
		}
	}

	return 0;
}


/*

7 5
5 8 10 3 6 10 8

 */
