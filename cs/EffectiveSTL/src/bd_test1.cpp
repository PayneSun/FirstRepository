// 百度C++/PHP开发
//
// 2019/09/17

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long n, m, k;
	cin >> n >> m >> k;

	long long a = 0, b = 0;
	vector<long long> ivec;
	for (long long i = n; i >= 0; --i) {
		for (long long j = m; j >= 0; --j) {
			if ((n-i)*(m-j) <= k) {
				ivec.push_back(i+j);
//				break;
			}
		}
	}

	sort(ivec.begin(), ivec.end());
	cout << ivec[0] << endl;
}
