// 第35条：通过mismatch或lexicographical_compare实现简单的忽略大小写的字符串比较
//
// tips_35.cpp
// 2019/8/14

#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>


bool ciCharLess(char c1, char c2)
{
	return tolower(static_cast<unsigned char>(c1)) <
			tolower(static_cast<unsigned char>(c2));
}


bool ciStringCompare(const std::string &s1, const std::string &s2)
{
	return std::lexicographical_compare(
			s1.begin(), s1.end(), s2.begin(), s2.end(), ciCharLess);
}


int main()
{
	std::string str1{"hello"}, str2{"HelLoX"};

	std::cout << ciStringCompare(str1, str2) << std::endl;

	return 0;
}

