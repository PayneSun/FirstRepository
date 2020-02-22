// Q08_MinNumberInRotatedArray.cpp
//
// 2019.09.27

#include <iostream>


int MinInOrder(int *numbers, int index1, int index2) {
	int result = numbers[index1];
	for (int i = index1 + 1; i <= index2; ++i) {
		if (result > numbers[i]) {
			result = numbers[i];
		}
	}

	return result;
}


int Min(int *numbers, int length) {
	if (numbers == NULL || length <=0) {
		return -1;
	}

	int index1 = 0,
		index2 = length - 1,
		indexMid = index1;
	while (numbers[index1] >= numbers[index2]) {
		if (index2 - index1 == 1) {
			indexMid = index2;
			break;
		}
		indexMid = (index1 + index2) / 2;
		if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1]) {
			return MinInOrder(numbers, index1, index2);
		}
		if (numbers[indexMid] >= numbers[index1]) {
			index1 = indexMid;
		} else if (numbers[indexMid] <= numbers[index2]) {
			index2 = indexMid;
		}
	}

	return numbers[indexMid];
}


int main()
{
	int arr[] = {3, 4, 5, 1, 2};
	std::cout << Min(arr, 5) << std::endl;

	return 0;
}
