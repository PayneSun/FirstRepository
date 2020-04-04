/******************************************
 * ch_03_list_stack_queue/stack_in_array.c
 *
 * 2020.04.04
 *****************************************/

#include "stack_in_array.h"
#include <iostream>

#define EmptyTOS (-1)
#define MinStackSize (5)

//
template<typename T>
Stack<T>::Stack(int maxElements) {
	if (maxElements < MinStackSize) {
		return;
	}

	this->array = new T[maxElements];
	this->capacity = maxElements;
	this->topOfStack = EmptyTOS;
	this->makeEmpty();
}

//
template<typename T>
void Stack<T>::dispose() {
	if (this->array != NULL) {
		delete[] this->array;
	}
}

//
template<typename T>
bool Stack<T>::isEmpty() {
	return this->topOfStack == EmptyTOS;
}

//
template<typename T>
void Stack<T>::makeEmpty() {
	this->topOfStack = EmptyTOS;
}

//
template<typename T>
void Stack<T>::push(T x) {
	if (this->isFull()) {
		return;
	} else {
		this->array[++this->topOfStack] = x;
	}
}

//
template<typename T>
T Stack<T>::top() {
	if (!this->isEmpty()) {
		return this->array[this->topOfStack];
	} else {
		return 0;
	}
}

//
template<typename T>
void Stack<T>::pop() {
	if (this->isEmpty()) {
		return;
	} else {
		this->topOfStack--;
	}
}

//
template<typename T>
T Stack<T>::topAndPop() {
	if (!this->isEmpty()) {
		return this->array[this->topOfStack--];
	} else {
		return 0;
	}
}
