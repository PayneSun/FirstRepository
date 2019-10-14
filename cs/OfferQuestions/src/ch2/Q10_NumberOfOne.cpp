// Q10_NumberOfOne.cpp
//
// 2019.10.07

#include <iostream>


int numberOfOne(int n) {
	int cnt = 0;
	while (n) {
		++cnt;
		n = n & (n-1);
	}

	return cnt;
}


int main()
{
	std::cout << numberOfOne(-15) << std::endl;

	return 0;
}
