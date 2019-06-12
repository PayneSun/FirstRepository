// ch16_templates_and_generic_programming
// overload_template.cpp
// 2019/6/12


#include <iostream>
#include <string>
#include <utility>
#include <sstream>
#include <type_traits>


template <typename T>
std::string debug_rep(const T &t)
{
	std::ostringstream ret;
	ret << t;
	return ret.str();
}


template <typename T>
std::string debug_rep(const T *p)
{
	std::ostringstream ret;
	ret << "pointer: " << p;
	if (p) {
		ret << " " << debug_rep(*p);
	} else {
		ret << " null pointer";
	}

	return ret.str();
}


std::string debug_rep(const std::string &s)
{
	return '"' + s + '"';
}


std::string debug_rep(char *p)
{
	return debug_rep(std::string(p));
}


std::string debug_rep(const char *p)
{
	return debug_rep(std::string(p));
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

