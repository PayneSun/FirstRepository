// ÌÚÑ¶ºóÌ¨
// question_1.cpp
// 2019/09/20

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	std::cin >> t;

	int n;
	string str;
	for (int i = 0; i < t; ++i) {
		std::cin >> n;
		std::cin >> str;
		auto pos = str.find('8');
		if (pos != -1 && str.size() - pos >= 11) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}


/*

2
11
88888888888
3
000

 */
