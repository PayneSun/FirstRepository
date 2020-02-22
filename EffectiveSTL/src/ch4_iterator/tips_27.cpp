// 第27条：使用distance和advance将容器的const_iterator转换成iterator
// tips_27.cpp
//
// 2019/8/10

#include <iostream>
#include <queue>


typedef std::deque<int> IntDeque;
typedef IntDeque::iterator Iter;
typedef IntDeque::const_iterator ConstIter;


int main()
{
	IntDeque d;
	ConstIter ci;

	Iter i(d.begin());
	std::advance(i, std::distance<ConstIter>(i, ci));

	return 0;
}
