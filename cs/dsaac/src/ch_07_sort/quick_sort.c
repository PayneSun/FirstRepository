/*
 * ch_07_sort/quick_sort.c
 *
 * 2019/3/11
 */

#include <stdio.h>

typedef int ElementType;

#define SWAP(A, B) { ElementType *tmp = A; A = B; B = tmp; }


/*
 * Return median of Left, Center, and Right
 * Order these and hide the pivot
 */
ElementType Median3(ElementType A[], int Left, int Right)
{
	int Center = (Left + Right) / 2;

	if (A[Left] > A[Center]) {
		SWAP(&A[Left], &A[Center]);
	}
	if (A[Left] > A[Right]) {
		SWAP(&A[Left], &A[Right]);
	}
	if (A[Center] > A[Right]) {
		SWAP(&A[Center], &A[Right]);
	}

	SWAP(&A[Center], &A[Right-1]);
	return A[Right-1];
}


/*
 * QSort
 */
void QSort(ElementType A[], int Left, int Right)
{
	int i, j;
	ElementType Pivot;

	Pivot = Median3(A, Left, Right);
	for (; ;) {
		i = Left; j = Right - 1;
		while(A[++i] < Pivot) {}
		while(A[--j] > Pivot) {}
		if (i < j) {
			SWAP(A[i], A[j]);
		} else {
			break;
		}
	}
	QSort(A, Left, i - 1);
	QSort(A, i - 1, Right);
}


/*
 * QuickSort
 */
void QuickSort(ElementType A[], int N)
{
	QSort(A, 0, N - 1);
}


/*
 * Places the k-th smallest element in the k-th position
 * Because arrays start at 0, this will be index k-1
 */
void QSelect(ElementType A[], int k, int Left, int Right)
{
	int i, j;
	ElementType Pivot;

	Pivot = Median3(A, Left, Right);
	i = Left;
	j = Right - 1;
	for (; ;) {
		while(A[++i] < Pivot) {}
		while(A[--j] > Pivot) {}
		if (i < j) {
			SWAP(&A[i], &A[j]);
		} else {
			break;
		}
		SWAP(&A[i], &A[Right-1]);

		if (k <= i) {
			QSelect(A, k, Left, i - 1);
		} else if (k > i + 1) {
			QSelect(A, k, i + 1, Right);
		}
	}



}

}
