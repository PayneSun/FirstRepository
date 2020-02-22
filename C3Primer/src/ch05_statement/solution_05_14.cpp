// ch05_statement
// solution_05_14.cpp
// 2019/4/4


#include <iostream>
#include <vector>
#include <string>

int main()
{
	std::vector<std::string> svec;
	int cnt = 1, max = 1;
	std::string str;
	while (std::cin >> str) {
		if (!svec.empty()) {
			if (svec[svec.size() - 1] == str) {
				cnt++;
			} else {
				if (cnt > max) {
					max = cnt;
				}
				cnt = 1;
			}
		}
		svec.push_back(str);
	}

	if (max > 1) {
		std::cout << max << std::endl;
	} else {
		std::cout << "no repeated word" << std::endl;
	}
}
