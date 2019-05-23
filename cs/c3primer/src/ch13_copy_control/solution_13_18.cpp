// ch13_copy_control
// solution_13_17.cpp
// 2019/5/15

#include <iostream>
#include <vector>
#include <memory>


class numbered {
public:
	numbered() { mysn = 6; }
	int mysn;
};


void f(numbered s) { std::cout << s.mysn << std::endl; }


int main() {
	numbered a, b = a, c = b;

	f(a);

	f(b);

	f(c);

	return 0;
}
