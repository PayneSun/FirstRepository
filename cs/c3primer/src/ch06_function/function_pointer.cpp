// ch06_function
// function_pointer.cpp
// 2019/4/10


#include <iostream>
#include <string>


bool lengthCompare(const std::string &str1, const std::string &str2)
{
	return (str1.size() == str2.size());
}

bool (*pft)(const std::string &, const std::string &) = lengthCompare;

// 等价声明
void useBigger(const std::string &, const std::string &,
		bool pf(const std::string &, const std::string &));
void useBigger2(const std::string &, const std::string &,
		bool (*pf)(const std::string &, const std::string &));

// 等价声明
typedef bool Func(const std::string &, const std::string &);
typedef decltype(lengthCompare) Func2;

// 等价声明
typedef bool (*FuncP)(const std::string &, const std::string &);
typedef decltype(lengthCompare) *FuncP2;


int main()
{
	// 等价定义
	decltype(pft) pf1 = lengthCompare;
	decltype(pft) pf2 = &lengthCompare;

	std::cout << pft("Hello", "Cpp") << std::endl;

	std::cout << pf1("Hello", "Java") << std::endl;
	std::cout << pf2("Hello", "world") << std::endl;

	return 0;
}
