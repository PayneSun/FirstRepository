// ch13_copy_control
// solution_13_13.cpp
// 2019/5/14

#include <iostream>
#include <vector>
#include <memory>


struct X {
	X() { std::cout << "X()" << std::endl; }
	X(const X&) { std::cout << "X(const X&)" << std::endl; }
	X& operator=(const X&) { std::cout << "operator=(const X&)" << std::endl; }
	~X() { std::cout << "~X()" << std::endl; }
};


void foo1(const X) { }

void foo2(const X&) { }


int main() {
	std::cout << __LINE__ << std::endl;
	X x1;

	std::cout << __LINE__ << std::endl;
	X x2 = x1;

	std::cout << __LINE__ << std::endl;
	X* px = new X;

	std::cout << __LINE__ << std::endl;
	foo1(x1);

	std::cout << __LINE__ << std::endl;
	foo2(x1);

	std::vector<X> xvec;
	std::cout << __LINE__ << std::endl;
	xvec.push_back(x1);

	std::cout << __LINE__ << std::endl;
	return 0;
}
