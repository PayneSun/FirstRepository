// insert_sort.cpp
// chapter-2: sort
// 2019/07/14

#include <iostream>
#include <algorithm>


template<typename T>
void insertSort(T array[], int n)
{
	for (int i = 1; i < n; ++i) {
		int j = i, tmp = array[i];
		while (j > 0 && array[j-1] > tmp) {
			array[j] = array[j-1];
			j--;
		}
		array[j] = tmp;
	}
}

//¡¥±Ìµƒ≤Â»Î≈≈–Ú
template<typename T>
struct ListNode
{
	struct ListNode<T> *next;
	T value;
};

template<typename T>
struct List
{
	struct ListNode<T> *head;
	int size;
};

template<typename T>
void SortLink(List<T> *link)
{
	if (!link) {
		return;
	}

	ListNode<T> *pHead, *pRear, *p, *tp;
	for (pHead = link->head, pRear = NULL; pHead; pHead = pHead->next) {
		for (tp = pHead, p = pHead->next; p; tp = p, p = p->next) {
			if (pHead->value >= p->value) {
				tp->next = p->next;
				p->next = pHead;
				pHead = p;
				p = tp;
			}
		}
		if (!pRear) {
			link->head = pHead;
		} else {
			pRear->next = pHead;
		}
		pRear = pHead;
	}
}


int main()
{
	int array[] = {9, 48, 7, 3, 22, 1, 0, 16, 15, 14};
	insertSort(array, 10);

	for (int i = 0; i < 10; ++i) {
		std::cout << array[i] << " ";
	}

	return 0;
}
