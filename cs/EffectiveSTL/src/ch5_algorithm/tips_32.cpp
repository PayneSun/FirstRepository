// 第32条：如果确实需要删除元素，则需要在remove这一算法之后调用erase
// tips_32.cpp
//
// 2019/8/14

#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
	std::vector<int> ivec;
	for (int i = 0; i < 15; i++) {
		ivec.push_back((5 * i + 1) % 11);
	}
	for (auto r: ivec) { std::cout << r << " ";	}
	std::cout << std::endl;

	ivec.erase(std::remove(ivec.begin(), ivec.end(), 5), ivec.end());
	for (auto r: ivec) { std::cout << r << " ";	}
	std::cout << std::endl;

	return 0;
}

