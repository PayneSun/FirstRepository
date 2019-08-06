/*
 * ch_07_sort/heap_sort.c
 *
 * 2019/3/4
 */


#define LeftChild(i) (2 * (i) + 1)

typedef int ElementType;


void PercDown(ElementType A[], int i, int N)
{
	int Child;
	ElementType Tmp;

	for (Tmp = A[i]; LeftChild(i) < N; i = Child) {
		Child = LeftChild(i);
		if (Child != N - 1 && A[Child+1] > A[Child]) {
			Child++;
		}
		if (Tmp < A[Child]) {
			A[i] = A[Child];
		} else {
			break;
		}
	}
}


void HeapSort(ElementType A[], int N)
{
	int i;

	/* build heap */
	for (i = N/2; i >= 0; i--) {
		PercDown(A, i, N);
	}
	/* delete max */
	for (i = N - 1; i > 0; i--) {
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}


void Swap(ElementType *left, ElementType *right)
{
	ElementType *tmp;

	tmp = left;
	left = right;
	right = tmp;
}
