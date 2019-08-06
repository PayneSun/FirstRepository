// ch19_specialized_tools_and_techniques
// solution_19_09.cpp
// 2019/6/26


#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>


int main()
{
	std::cout << typeid(int).name() << std::endl;
	std::cout << typeid(float).name() << std::endl;
	std::cout << typeid(double).name() << std::endl;
	std::cout << typeid(long).name() << std::endl;
	std::cout << typeid(long long).name() << std::endl;
	std::cout << typeid(std::string).name() << std::endl;
	std::cout << typeid(std::vector<int>).name() << std::endl;

	return 0;
}
