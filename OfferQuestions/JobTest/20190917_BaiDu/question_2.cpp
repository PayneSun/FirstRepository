// 百度C++/PHP开发
//
// 2019/09/17

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
	point(int a, int b): a(a), b(b) {}
	int a;
	int b;
};

bool cmp(point a, point b) {
	return a.b < b.b;
}

int main()
{
	int t, n;
	cin >> t;

	int a, b;
	vector<point> vec;
	while(t > 0) {
		cin >> n;
		vec.reserve(n);
		for (int i = 0; i < n; ++i) {
			cin >> a >> b;
			vec.push_back(point(a,b));
		}

		sort(vec.begin(), vec.end(), cmp);
		bool ret = true;
		int dt = 0;
		for (auto &r : vec) {
			dt += r.a;
			if (dt > r.b) {
				ret = false;
				break;
			}
		}

		if (ret) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}

		vec.clear();
		t--;
	}

	return 0;
}

/*

1
5
2 4
1 9
1 8
4 9
3 12

 */
