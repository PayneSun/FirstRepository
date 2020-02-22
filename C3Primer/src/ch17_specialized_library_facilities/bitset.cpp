// ch17_specialized_library_facilities
// bitset.cpp
// 2019/6/14


#include <iostream>
#include <string>
#include <bitset>


int main()
{
	std::bitset<32> bitvec(1U);
	std::bitset<13> bitvec1(0xbeef);
	std::bitset<20> bitvec2(0xbeef);
	std::bitset<128> bitvec3(~0ULL);
	std::bitset<32> bitvec4("1100");

	for (int i = 0; i < bitvec4.size(); ++i) {
		std::cout << bitvec4[i] << "-";
	}
	std::cout << std::endl;

	unsigned long long ullong = bitvec3.to_ulong();
	std::cout << "ullong = " << ullong << std::endl;

	return 0;
}


