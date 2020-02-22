// ÌÚÑ¶ºóÌ¨
// question_3.cpp
// 2019/09/20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	std::cin >> t;

	vector<int> ivec;
	int n, p;
	for (int i = 0; i < t; ++i) {
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> p;
			ivec.push_back(p);
		}
		sort(ivec.begin(), ivec.end());

		int x = 0, y = 0;
		for (int k = 0; k < n / 2; ++k) {
			if (k % 2) {
				x += ivec[k] + ivec[n-k-1];
			} else {
				y += ivec[k] + ivec[n-k-1];
			}
		}
		if (x <= y) {
			cout << x << " " << y << endl;
		} else {
			cout << y << " " << x << endl;
		}

		ivec.clear();
	}

	return 0;
}


/*

2
4
5 9 4 7
8
9 13 18 10 12 4 18 3

 */
