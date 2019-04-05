// ch05_statment
// solution_05_20.cpp
// 2019/4/5


#include <iostream>
#include <string>


int main()
{
	std::string str, pre;
	while (std::cin >> str && !str.empty()) {
		if (pre.empty()) {
			pre = str;
		} else if (pre == str) {
			std::cout << "repeated string: " << str << std::endl;
			break;
		} else {
			pre = str;
		}
	}
	std::cout << "end of input" << std::endl;

	return 0;
}

