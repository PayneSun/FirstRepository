// ch03_string_vector_array
// array.cpp
// 2019/3/29


#include <iostream>
#include <string>
#include <vector>

std::vector<int> ivec{1, 2, 3};
std::vector<int> ivec2(10, -1);
std::vector<std::string> svec(5, "hi");

int main()
{
	const char ca[] = {'h', 'e', 'l', 'l', 'o'};
	const char *cp =ca;
	while (*cp) {
		std::cout << *cp << std::endl;
		++cp;
	}

	int int_arr[] = {0, 1, 2, 3, 4, 5};
	std::vector<int> ivec(std::begin(int_arr), std::end(int_arr));

	return 0;
}
