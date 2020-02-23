// Vector.h
// 2019.09.17

#include "Vector.h"

#include <iostream>
#include <algorithm>


template<typename T>
void Vector<T>::expand() {
	if (_size < _capacity) {
		return;
	}
	_capacity = std::max(_capacity, DEAFAULT_CAPACITY);
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; ++i) {
		_elem[i] = oldElem[i];
	}

	delete [] oldElem;
}


template<typename T>
void Vector<T>::insert(Rank r, T const &e) {
	this->expand();
	for (int i = _size; i > r; --i) {
		_elem[i] = _elem[i-1];
	}
	_elem[r] = e;
	_size++;

	return r;
}


template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) { return 0; }
	while (hi < _size) {
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
//	shrink();
	return hi-lo;
}


template<typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r+1);
	return e;
}


template<typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const {
	while ((lo < hi--) && e != _elem[hi]) {}
	return hi;
}


template<typename T>
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size) {
		find(_elem[i], 0, i) < 0 ? i++ : remove(i);
	}

	return oldSize - _size;
}


template<typename T>
void Vector<T>::traverse(Increase<T> &visit) {
	for (int i = 0; i <_size; ++i) {
		visit(_elem[i]);
	}
}


template<typename T>
int Vector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; ++i) {
		n += (_elem[i-1] > _elem[i]);
	}
	return n;
}


template<typename T>
int Vector<T>::uniquify() {

    return 0;
}


template<typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi); //复制数组区间A[lo, hi)


template<typename T>
void Vector<T>::expand(); //空间不足时扩容


template<typename T>
void Vector<T>::shrink(); //装填因子过小时压缩


template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi); //扫描交换


template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi); //起泡排序算法


template<typename T>
Rank Vector<T>::max(Rank lo, Rank hi); //选取最大元素


template<typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi); //选择排序算法


template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi); //归并算法


template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi); //归并排序算法


template<typename T>
void Vector<T>::heapSort(Rank lo, Rank hi); //堆排序（稍后结合完全堆讲解）


template<typename T>
Rank Vector<T>::partition(Rank lo, Rank hi)


template<typename T>
void Vector<T>::quickSort(Rank lo, Rank hi); //快速排序算法


template<typename T>
void shellSort(Rank lo, Rank hi); //希尔排序算法
