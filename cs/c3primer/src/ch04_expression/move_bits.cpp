// ch04_expression
// move_bits.cpp
// 2019/4/2


#include <iostream>


int main()
{
	unsigned char bits = 0227;
	std::cout << (bits << 3) << std::endl;
	std::cout << (bits >> 9) << std::endl;

	return 0;
}
