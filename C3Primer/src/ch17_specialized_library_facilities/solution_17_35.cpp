// ch17_specialized_library_facilities
// solution_17_35.cpp
// 2019/6/19


#include <iostream>
#include <cmath>
#include <iomanip>


int main()
{
	std::cout << std::hexfloat << std::uppercase << sqrt(2.0) << std::endl;

	return 0;
}
