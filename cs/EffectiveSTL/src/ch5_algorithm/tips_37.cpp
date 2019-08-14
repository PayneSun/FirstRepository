// 第37条：使用accumulate或者for_each进行区间统计
//
// tips_37.cpp
// 2019/8/14

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <numeric>


std::string::size_type stringLengthSum(std::string::size_type sumSoFar, const std::string &s)
{
	return sumSoFar + s.size();
}


int main()
{
	std::vector<std::string> svec{"welcome", "to", "China"};

	std::cout << std::accumulate(svec.begin(), svec.end(),
			static_cast<std::string::size_type>(0), stringLengthSum) << std::endl;

	return 0;
}

