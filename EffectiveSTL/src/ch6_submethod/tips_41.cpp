// 第41条：理解ptr_fun、mem_fun和mem_fun_ref的来由
//
// tips_41.cpp
// 2019/8/19

#include <iostream>
#include <cctype>
#include <string>
#include <vector>
#include <algorithm>


struct Foo
{
	Foo(int val): val(val) {}
	int val;
	void test() { std::cout << "class Foo: test() " << val << std::endl; }
};


void test(Foo& foo)
{
	std::cout << "test()" << std::endl;
}


int main()
{
	std::vector<Foo> fvec{1, 2, 3};
	std::vector<Foo*> pfvec{new Foo(4), new Foo(5), new Foo(6)};

	std::for_each(fvec.begin(), fvec.end(), std::ptr_fun(test));
	std::for_each(pfvec.begin(), pfvec.end(), std::mem_fun(&Foo::test));
	std::for_each(fvec.begin(), fvec.end(), std::mem_fun_ref(&Foo::test));

	return 0;
}

