// Q03_FindInPartiallySortedMatrix.cpp
//
// 2019.08.22

#include <iostream>
#include <vector>


bool find(const std::vector<std::vector<int>> &matrix, int value)
{
	bool ret = false;
	int row = 0, col = matrix[0].size() - 1;
	while (row < matrix.size() && col >= 0) {
		if (matrix[row][col] > value) {
			col--;
		} else if (matrix[row][col] < value) {
			row++;
		} else {
			return true;
		}
	}

	return ret;
}


int main()
{
	std::vector<std::vector<int>> matrix{{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};

	std::cout << find(matrix, 7) << std::endl;

	return 0;
}
