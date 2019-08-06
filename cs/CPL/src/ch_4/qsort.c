/*
 * src/ch_4/qsort.c
 *
 * 2019/2/18
 */

#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);

int main()
{
	int array[] = {1, 9, 7, 3, 5};

	qsort(array, 0, 5);

	for (int i = 0; i < 5; ++i) {
		printf("%d\t", array[i]);
	}
}


void qsort(int v[], int left, int right)
{
	int i, last;
	void swap(int v[], int i, int j);

	if (left >= right) {
		return;
	}
	swap(v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left]) {
			swap(v, ++last, i);
		}
	}
	swap(v, left, last);

	qsort(v, left, last - 1);
	qsort(v, last + 1, right);
}


void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
