// ch06_function
// inline.cpp
// 2019/4/10


#include <iostream>
#include <string>


inline const std::string &
shorterString(const std::string &s1, const std::string &s2)
{
	return s1.size() <= s2.size() ? s1 : s2;
}


int main()
{
	std::string str1 = "hello-cpp";
	std::string str2 = "hello-csharp";

	std::cout << shorterString(str1, str2) << std::endl;

	return 0;
}
