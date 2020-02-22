// ch05_statement
// solution_05_19.cpp
// 2019/4/4


#include <iostream>
#include <string>


int main()
{
	std::string str1, str2;
	do {
		std::cin >> str1 >> str2;
		std::cout << (str1.size() > str2.size() ? str2 : str1) << std::endl;
	} while (std::cin);

	return 0;
}

