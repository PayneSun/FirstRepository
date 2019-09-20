// Q05_PrintListReversely.cpp
//
// 2019.09.20

#include <iostream>
#include <cstdio>
#include <cstring>


void replaceBlank(char strs[], int length)
{
	if (strs == NULL || length <= 0) {
		return;
	}

	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (strs[i] != '\0') {
		++originalLength;
		if (strs[i] == ' ') {
			++numberOfBlank;
		}
		++i;
	}

	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > length) {
		return;
	}

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
		if (strs[indexOfOriginal] == ' ') {
			strs[indexOfNew--] = '0';
			strs[indexOfNew--] = '2';
			strs[indexOfNew--] = '%';
		} else {
			strs[indexOfNew--] = strs[indexOfOriginal];
		}
		indexOfOriginal--;
	}
}


int main()
{
	char strs[50] = "We are happy!";

	replaceBlank(strs, 50);
	printf("%s", strs);

	return 0;
}
