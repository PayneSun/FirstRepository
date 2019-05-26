// 第4条：调用empty而不是检查size()是否为0
// tips_04.cpp
// 2019/5/26


#include <iostream>
#include <vector>
#include <list>


int main()
{
	std::vector<int> ivec{1,2,3};
	std::list<int> ilist{1,2,3};

	std::cout << ivec.empty() << std::endl;
	std::cout << ivec.size() << std::endl;

	std::cout << ilist.empty() << std::endl;
	std::cout << ilist.size() << std::endl;

	return 0;
}
