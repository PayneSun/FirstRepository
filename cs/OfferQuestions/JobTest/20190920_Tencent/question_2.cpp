// ÌÚÑ¶ºóÌ¨
// question_2.cpp
// 2019/09/20

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	std::cin >> n;

	vector<int> ivec;
	int x, y;
	for (int i = 0; i < n; ++i) {
		std::cin >> x >> y;
		for (int j = 0; j < x; ++j) {
			ivec.push_back(y);
		}
	}
	sort(ivec.begin(), ivec.end());

    int len = ivec.size();
    vector<int> rvec;
    //rvec.reserve(len/2);
	for (int i = 0; i < len / 2; ++i) {
		rvec.push_back(ivec[i] + ivec[len-1-i]);
	}
	sort(rvec.begin(), rvec.end());
	cout << rvec[rvec.size()-1] << endl;

	return 0;
}


/*

3
1 8
2 5
1 2

 */
