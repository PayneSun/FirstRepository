// 第20条：为包含指针的关联容器指定比较类型
// tips_20.cpp
// 2019/8/6

#include <iostream>
#include <string>
#include <set>
#include <functional>


struct StringPtrLess:
		public std::binary_function<const std::string*, const std::string*, bool> {
	bool operator()(const std::string *ps1, const std::string *ps2) const {
		return *ps1 < *ps2;
	}
};


int main()
{
	std::set<std::string*, StringPtrLess> ssp;
	ssp.insert(new std::string("Anteater"));
	ssp.insert(new std::string("Wombat"));
	ssp.insert(new std::string("Lemur"));
	ssp.insert(new std::string("Penguin"));

	for(auto i = ssp.begin(); i != ssp.end(); ++i) {
		std::cout << **i << std::endl;
	}

	return 0;
}
