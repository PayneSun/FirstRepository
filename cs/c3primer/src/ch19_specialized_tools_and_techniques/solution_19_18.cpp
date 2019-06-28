// ch19_specialized_tools_and_techniques
// solution_19_18.cpp
// 2019/6/27


#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>


int main()
{
	std::vector<std::string> svec = {"hello", "cpp", "", "hello", "java", ""};
	std::cout <<
		std::count_if(svec.begin(), svec.end(), std::mem_fn(&std::string::empty))
	<< std::endl;

	std::cout <<
		std::count_if(svec.begin(), svec.end(), std::bind(&std::string::empty, std::placeholders::_1))
	<< std::endl;

	return 0;
}
