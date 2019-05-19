// ch13_copy_control
// solution_13_05.cpp
// 2019/5/14

#include <iostream>
#include <algorithm>


class HasPtr {
public:
	HasPtr(const std::string &s = new std::string()):
		ps(new std::string(s)), i(0) {}
	HasPtr(const HasPtr& hp) {
		*(this->ps) = *(hp.ps);
		this->i = hp.i;
	}
private:
	std::string *ps;
	int i;
};


int main() {
	//
	return 0;
}
