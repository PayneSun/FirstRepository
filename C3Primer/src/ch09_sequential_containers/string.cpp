// ch09_sequential_containers
// string.cpp
// 2019.04.24

#include <iostream>
#include <string>


int main() {
	char arr[] = "abcdefghijklmnopqrstuvwxyz";
	std::string cs = "abcdefghijklmnopqrstuv";

	std::string str1(arr, 5);
	std::cout << str1 << std::endl;

	std::string str2(cs, 1);
	std::cout << str2 << std::endl;

	std::string str3(cs, 2, 5);
	std::cout << str3 << std::endl;

	std::cout << cs.find(str3) << std::endl;
	std::cout << cs.rfind(str3) << std::endl;
	std::cout << cs.find_first_of(str3) << std::endl;
	std::cout << cs.find_last_of(str3) << std::endl;
	std::cout << cs.find_first_not_of(str3) << std::endl;
	std::cout << cs.find_last_not_of(str3) << std::endl;

	// 比较操作
	std::cout << cs.compare(str3) << std::endl;

	// 数值转化
	int i = 42;
	std::string str4 = std::to_string(i);
	std::cout << "\n" << str4 << std::endl;

	double d = std::stod(str4);

	return 0;
}
