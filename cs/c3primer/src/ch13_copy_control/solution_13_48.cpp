// ch13_copy_control
// solution_13_48.cpp
// 2019/5/20

#include <iostream>
#include <vector>
#include <memory>


class String {
public:
	String() {
		std::cout << "String::String()" << std::endl;
	}
	String(const String&) {
		std::cout << "String::String(const String&)" << std::endl;
	}
	String& operator=(const String &bs) {
		std::cout << "String::operator=(const String&)" << std::endl;
		return *this;
	}
};


int main() {
	String xs;
	std::cout << __LINE__ << std::endl;

	std::vector<String> svec;
	for (auto i = 0; i < 10; i++) {
		svec.push_back(String(xs));
		std::cout << __LINE__ << std::endl;
	}

	return 0;
}
