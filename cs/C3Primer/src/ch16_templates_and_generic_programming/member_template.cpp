// ch16_templates_and_generic_programming
// member_template.cpp
// 2019/6/9


#include <iostream>
#include <cstring>
#include <memory>
#include <functional>


class DebugDelete {
public:
	DebugDelete(std::ostream &s = std::cerr): os(s) {}
	template <typename T> void operator()(T *p) const {
		os << "deleting unique_ptr" << std::endl;
		delete p;
	}

private:
	std::ostream &os;
};


int main()
{
	double *p = new double;
	DebugDelete d;
	d(p);

	int *ip = new int;
	DebugDelete()(ip);

	std::unique_ptr<int, DebugDelete> pu(new int, DebugDelete());

	std::unique_ptr<std::string, DebugDelete> ps(new std::string, DebugDelete());

	return 0;
}
