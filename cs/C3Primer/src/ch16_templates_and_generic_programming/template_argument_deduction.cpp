// ch16_templates_and_generic_programming
// template_argument_deduction.cpp
// 2019/6/10


#include <iostream>
#include <string>
#include <utility>
#include <type_traits>


template <typename T>
auto fcn(T beg, T end) -> decltype(*beg)
{
	return *beg;
}


template <typename T>
auto fcn2(T beg, T end) -> typename std::remove_reference<decltype(*beg)>::type
{
	return *beg;
}


int main()
{
	std::string s1("hi"), s2;

	s2 = std::move(std::string("bye"));
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;

	s2 = std::move(s1);
	std::cout << "s1: " << s1 << std::endl;
	std::cout << "s2: " << s2 << std::endl;

	return 0;
}

