// ch14_overloaded_operations_and_conversions
// callable_func.cpp
// 2019/5/31


#include <iostream>
#include <map>
#include <functional>


int add(int a, int b) {	return a + b; }


int main()
{
	std::divides<int> div;
	auto mod = [](int i, int j) { return i % j; };

	std::function<int(int, int)> f1 = add;
	std::function<int(int, int)> f2 = div;
	std::function<int(int, int)> f3 = [](int i, int j) { return i * j; };

//	std::cout << f1(4,2) << std::endl;
//	std::cout << f2(4,2) << std::endl;
//	std::cout << f3(4,2) << std::endl;

	std::map<std::string, std::function<int(int,int)>> binops = {
			{"+", add},
			{"-", std::minus<int>()},
			{"/", div},
			{"*", [](int l, int r) { return l * r; }},
			{"%", mod}
	};

	std::cout << binops["+"](10, 5) << std::endl;
	std::cout << binops["-"](10, 5) << std::endl;
	std::cout << binops["*"](10, 5) << std::endl;
	std::cout << binops["/"](10, 5) << std::endl;
	std::cout << binops["%"](10, 5) << std::endl;

	return 0;
}
