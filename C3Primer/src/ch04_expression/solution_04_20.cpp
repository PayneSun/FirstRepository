// ch04_expression
// solution_04_20.cpp
// 2019/4/1


#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::vector<std::string> svec = { "hello", "vector" };
	std::vector<std::string>::iterator iter = svec.begin();

	std::cout << *iter++ << std::endl;
	std::cout << (*iter)++ << std::endl;
	std::cout << *iter.empty() << std::endl;
	std::cout << iter->empty() << std::endl;
	std::cout << ++*iter << std::endl;
	std::cout << iter++->empty() << std::endl;

	return 0;
}
