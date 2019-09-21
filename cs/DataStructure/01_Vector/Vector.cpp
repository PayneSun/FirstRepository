// Algorithm/Vector
// Vector.h
// 2019/09/17

#include "../01_Vector/Vector.h"

#include <iostream>
#include <algorithm>


//
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


//
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
