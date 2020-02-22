// 百度C++/PHP开发
//
// 2019/09/17

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 100000 + 1;
int vvec[maxn][maxn] = 0;

int main()
{
	int t, n;
	cin >> t;

	int a, b;
	while(t > 0) {
		cin >> n;
		for (int i = 0; i < n-1; ++i) {
			cin >> a >> b;
			vvec[a][b] = 1;
			vvec[b][a] = 1;
		}

		int x = 0, y = 0;
		for (int i = 1; i < maxn; ++i) {
			if (vvec[1][i] == 1 || vvec[i][1] == 1) {
				x++;
			}
			if (vvec[n][i] == 1 || vvec[n][1] == 1) {
				y++;
			}
		}

		if (x > y) {
			cout << "niuniu" << endl;
		} else {
			cout << "meimei" << endl;
		}

		for (int i = 0; i < maxn; ++i) {
			for (int j = 0; j < maxn; ++j) {
				vvec[i][j] = 0;
			}
		}
		t--;
	}

	return 0;
}

/*

2
7
3 6
1 2
3 1
7 4
5 7
1 4
4
1 4
4 2
2 3

 */
