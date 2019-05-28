// 第5条：区间成员函数优先于与之对应的单元素成员函数
// tips_05.cpp
// 2019/5/26


#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> ivec1(10,1);
	std::vector<int> ivec2(10,2);

//	方法1
	ivec1.assign(ivec2.begin() + ivec2.size() / 2, ivec2.end());

//	方法2
//	ivec1.clear();
//	std::copy(ivec2.begin() + ivec2.size() / 2, ivec2.end(), std::back_inserter(ivec1));

//	方法3
//	ivec1.clear();
//	ivec1.insert(ivec1.end(), ivec2.begin() + ivec2.size() / 2, ivec2.end());

	for (const auto ele : ivec1) {
		std::cout << ele << std::endl;
	}

	return 0;
}
