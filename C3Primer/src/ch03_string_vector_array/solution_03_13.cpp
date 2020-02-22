// ch03_string_vector_array
// solution_03_13.cpp
// 2019/3/27


#include <iostream>
#include <string>
#include <vector>


int main()
{
	std::vector<std::string> svec{10, "hi"};
	std::cout << svec.size() << std::endl;

	std::vector<int> ivec(10, 42);
	std::cout << ivec.size() << std::endl;

	return 0;
}
