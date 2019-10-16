// 字节跳动-后端开发
//
// 2019/10/14

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	int m, n;
	cin >> m >> n;

	int rd = 0, tmp;
	vector<int> bvec;
	for (int i = 0; i < n; ++i) {
		bvec.push_back(0);
	}

	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		bvec[0] += tmp;
		sort(bvec.begin(), bvec.end());
	}

	sort(bvec.begin(), bvec.end());
	cout << bvec[bvec.size()-1] << endl;

	return 0;
}

/*
5 3
4 4 1 2 1

 */
