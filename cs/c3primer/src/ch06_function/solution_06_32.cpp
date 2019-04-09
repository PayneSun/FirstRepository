// ch06_function
// solution_06_32.cpp
// 2019/4/8

#include <iostream>
#include <initializer_list>


int &get(int *arry, int index) {
	return arry[index];
}


int main()
{
	int ia[10];

	for (int i = 0; i != 10; ++i) {
		get(ia, i) = 2 * i;
	}

	for (int i = 0; i != 10; ++i) {
		std::cout << ia[i] << std::endl;
	}

	return 0;
}
