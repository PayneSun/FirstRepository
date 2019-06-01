// ch14_overloaded_operations_and_conversions
// solution_14_43.cpp
// 2019/6/1


#include <iostream>
#include <vector>
#include <functional>


int main()
{
	int val = 5;
	std::vector<int> ivec;
	for (std::size_t i = 0; i < 10; ++i) {
		ivec.push_back(i * val);
	}

	bool ret = true;
	std::modulus<int> imod;
	for (std::size_t i = 0; i < 10; i++) {
		if (imod(ivec[i], val)) {
			ret &= false;
		} else {
			ret &= true;
		}
	}
	std::cout << ret << std::endl;

	return 0;
}
