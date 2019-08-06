// ch09_sequential_containers
// vector.cpp
// 2019.04.24

#include <iostream>
#include <vector>


int main() {
	std::vector<int> ivec;

	std::cout << "size:\t" << ivec.size() << std::endl;
	std::cout << "capacity:\t" << ivec.capacity() << std::endl;

	for (std::vector<int>::size_type is = 0; is != 24; ++is) {
		ivec.push_back(is);
	}
	std::cout << "size:\t" << ivec.size() << std::endl;
	std::cout << "capacity:\t" << ivec.capacity() << std::endl;

	ivec.reserve(50);
	std::cout << "size:\t" << ivec.size() << std::endl;
	std::cout << "capacity:\t" << ivec.capacity() << std::endl;

	while (ivec.size() != ivec.capacity()) { ivec.push_back(1); }
	ivec.push_back(1);
	std::cout << "size:\t" << ivec.size() << std::endl;
	std::cout << "capacity:\t" << ivec.capacity() << std::endl;

	ivec.shrink_to_fit();
	std::cout << "size:\t" << ivec.size() << std::endl;
	std::cout << "capacity:\t" << ivec.capacity() << std::endl;

	return 0;
}
