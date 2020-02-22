// ch14_overloaded_operations_and_conversions
// solution_14_34.cpp
// 2019/5/31


#include <iostream>
#include <vector>
#include <algorithm>


struct Judge
{
	int operator()(int val1, int val2, int val3) const {
		if (val1 > 0) {
			return val2;
		} else {
			return val3;
		}
	}
};


int main()
{
	Judge jdg;

	std::cout << jdg(1,2,3) << std::endl;

	return 0;
}
