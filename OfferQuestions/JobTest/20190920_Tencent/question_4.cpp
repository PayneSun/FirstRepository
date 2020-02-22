// ÌÚÑ¶ºóÌ¨
// question_4.cpp
// 2019/09/20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unsigned n, x;
	std::cin >> n;

	vector<unsigned> ivec;
	for (int i = 0; i < n; ++i) {
		cin >> x;
		ivec.push_back(x);
	}

	vector<unsigned> xvec;
	for (auto r: ivec) {
		for (int i = 0; i < n; ++i) {
			cin >> x;
			xvec.push_back(r + x);
		}
	}

	unsigned ret = xvec[0];
	for (int i = 1; i < xvec.size(); ++i) {
		ret ^= xvec[i];
	}
	std::cout << ret << std::endl;

	return 0;
}


/*

5
1 2 1 0 0
1 2 3 0 0

 */
