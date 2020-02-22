// ch18_tools_for_lagre_programs
// namespace.cpp
// 2019/6/23


#include <iostream>
#include <exception>


namespace nspa
{
	int i, j;
	//
};


void f()
{
	using namespace nspa;
	std::cout << i *j << std::endl;
}


int main()
{
	nspa::i = 1;
	nspa::j = 2;

	f();

	return 0;
}
