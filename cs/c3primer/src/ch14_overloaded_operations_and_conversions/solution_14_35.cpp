// ch14_overloaded_operations_and_conversions
// solution_14_35.cpp
// 2019/5/31


#include <iostream>
#include <vector>
#include <algorithm>


class PrintStr
{
public:
	PrintStr(std::istream &istr = std::cin): is(istr) {}
	std::string operator()() const {
		std::string ret;
		if (getline(is, ret)) {
			return ret;
		}
		return ret;
	}
private:
	std::istream &is;
};


int main()
{
	PrintStr ps;
	std::cout << ps() << std::endl;

	return 0;
}
