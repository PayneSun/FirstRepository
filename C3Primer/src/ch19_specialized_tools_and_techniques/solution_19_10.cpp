// ch19_specialized_tools_and_techniques
// solution_19_10.cpp
// 2019/6/26


#include <iostream>
#include <typeinfo>
#include <string>
#include <vector>


class A
{
public:
	A() {}
	virtual ~A() {}
};


class B: public A
{
public:
	B() {}
	virtual ~B() {}
};


class C: public B
{
public:
	C() {}
	virtual ~C() {}
};


int main()
{
	A *pa = new C;
	std::cout << typeid(pa).name() << std::endl;

	C cobj;
	A &ra1 = cobj;
	std::cout << typeid(&ra1).name() << std::endl;

	B *px = new B;
	A &ra2 = *px;
	std::cout << typeid(ra2).name() << std::endl;

	return 0;
}
