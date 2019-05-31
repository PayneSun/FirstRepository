// ch14_overloaded_operations_and_conversions
// func_call_operator.cpp
// 2019/5/31


#include <iostream>
#include <vector>
#include <algorithm>


struct absInt
{
	int operator()(int val) const {
		return (val < 0) ? -val : val;
	}
};


class PrintString
{
public:
	PrintString(std::ostream &o = std::cout, char c = ' '):
		os(o), sep(c) {}
	void operator()(const std::string &s) const {
		os << s << sep;
	}
private:
	std::ostream &os;
	char sep;
};


int main()
{
	int i = -42;
	absInt absObj;

	int ui = absObj(i);
	std::cout << ui << std::endl;

	std::vector<std::string> svec = {"Welcome", "to", "China"};
	std::for_each(svec.begin(), svec.end(), PrintString(std::cout, '\n'));

	return 0;
}
