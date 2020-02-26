// Vector.cpp
// 2020.02.21

#include "Vector.h"

#include <iostream>
#include <algorithm>

//动态扩容
template<typename T>
void Vector<T>::expand() {
	if (_size < _capacity) {
		return;
	}
	_capacity = std::max(_capacity, DEFAULT_CAPACITY);
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; ++i) {
		_elem[i] = oldElem[i];
	}

	delete[] oldElem;
}

//插入元素
template<typename T>
Rank Vector<T>::insert(Rank r, T const &e) {
	this->expand();
	for (int i = _size; i > r; --i) {
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
	_size++;

	return r;
}

//区间删除
template<typename T>
int Vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) {
		return 0;
	}
	while (hi < _size) {
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	this->shrink();

	return hi - lo;
}

//单元素删除
template<typename T>
T Vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);

	return e;
}

//查找
template<typename T>
Rank Vector<T>::find(T const &e, Rank lo, Rank hi) const {
	while ((lo < hi--) && e != _elem[hi]) {
	}
	return hi;
}

//唯一化
template<typename T>
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size) {
		find(_elem[i], 0, i) < 0 ? i++ : remove(i);
	}

	return oldSize - _size;
}

//遍历
template<typename T> template <typename VST>
void Vector<T>::traverse(VST& visit) {
	for (int i = 0; i < _size; ++i) {
		visit(_elem[i]);
	}
}

template <typename T>
void increase(Vector<T> &v) {
	v.traverse(Increase<T>());
}

//统计逆序对数
template<typename T>
int Vector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; ++i) {
		n += (_elem[i-1] > _elem[i]);
	}

	return n;
}

//有序向量的唯一化（低效）
template<typename T>
int Vector<T>::uniquify() {
	int i = 0, oldSize = _size;
	while (i < _size - 1) {
		(_elem[i] == _elem[i+1]) ? remove(i+1) : ++i;
	}

	return oldSize - _size;
}

//有序向量的唯一化（高效）
template<typename T>
int Vector<T>::uniquify2() {
	Rank i = 0, j = 0;
	while (++j < _size) {
		if (_elem[i] != _elem[j]) {
			_elem[++i] = _elem[j];
		}
	}
	_size = ++i;

	return j - i;
}

template<typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {

}

template<typename T>
void Vector<T>::expand() {

}

template<typename T>
void Vector<T>::shrink() {

}

template<typename T>
bool Vector<T>::bubble(Rank lo, Rank hi) {

}

template<typename T>
void Vector<T>::bubbleSort(Rank lo, Rank hi) {

}

template<typename T>
Rank Vector<T>::max(Rank lo, Rank hi) {

}

template<typename T>
void Vector<T>::selectionSort(Rank lo, Rank hi) {

}

template<typename T>
void Vector<T>::merge(Rank lo, Rank mi, Rank hi) {

}

template<typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {

}

template<typename T>
void Vector<T>::heapSort(Rank lo, Rank hi) {

}

template<typename T>
Rank Vector<T>::partition(Rank lo, Rank hi) {

}

template<typename T>
void Vector<T>::quickSort(Rank lo, Rank hi) {

}

template<typename T>
void Vector<T>::shellSort(Rank lo, Rank hi) {

}
