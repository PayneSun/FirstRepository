// ch03_string_vector_array
// multi_array.cpp
// 2019/3/29


#include <iostream>
#include <string>
#include <vector>


int main()
{
	constexpr std::size_t rowCnt = 3, colCnt = 4;
	int ia[rowCnt][colCnt];

	std::size_t cnt= 0;
	for (auto &row : ia) {
		for (auto &col : row) {
			col = cnt;
			++cnt;
		}
	}

	return 0;
}
