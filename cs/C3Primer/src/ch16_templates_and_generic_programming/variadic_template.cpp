// ch16_templates_and_generic_programming
// variadic_template.cpp
// 2019/6/12


#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <type_traits>


template <typename T, typename ... Args>
void foo(const T &t, const Args& ... rest)
{
	std::cout << sizeof...(Args) << std::endl;
	std::cout << sizeof...(rest) << std::endl;
}


template<typename T>
std::ostream& print(std::ostream &os, const T &t)
{
	return os << t;
}


template<typename T, typename ... Args>
std::ostream& print(std::ostream &os, const T &t, const Args& ... rest)
{
	os << t << ", ";
	return print(os, rest ...);
}


int main()
{
	int i = 0;
	double d = 3.14;
	std::string s = "how are you";
	foo(i, d, s);

	print(std::cout, 1, 2.3, false, "hello");

	return 0;
}

