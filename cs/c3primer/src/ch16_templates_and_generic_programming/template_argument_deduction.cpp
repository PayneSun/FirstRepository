// ch16_templates_and_generic_programming
// template_argument_deduction.cpp
// 2019/6/10


#include <iostream>
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


