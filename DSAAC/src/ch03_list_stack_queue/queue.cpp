/******************************************
 * ch03_list_stack_queue/queue.cpp
 *
 * 2020.04.06
 *****************************************/

#include "queue.h"

//
template<typename T>
bool Queue<T>::isEmpty() {
	return this->size == 0;
}

//
template<typename T>
void Queue<T>::makeEmpty() {
	this->size = 0;
	this->front = 1;
	this->rear = 0;
}

//
template<typename T>
int Queue<T>::succ(int value) {
	if (++value == this->capacity) {
		value = 0;
	}

	return value;
}

//
template<typename T>
void Queue<T>::enqueue(T x) {
	if (this->isFull()) {
		return;
	} else {
		this->size++;
		this->rear = this->succ(this->rear);
		this->array[this->rear] = x;
	}
}
