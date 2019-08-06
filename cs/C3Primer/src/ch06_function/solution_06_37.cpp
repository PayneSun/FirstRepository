// ch06_function
// solution_06_37.cpp
// 2019/4/9

#include <iostream>
#include <string>


std::string arr[10];


typedef std::string sarr[10];
sarr* func1(const std::string &s);


auto func2(const std::string &s) -> std::string(*)[10];


decltype(arr) *func3(const std::string &s);


int main()
{
	return 0;
}
