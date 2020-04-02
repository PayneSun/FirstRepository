/******************************************
 * ch03_list_stack_queue/stack.c
 *
 * 2020.04.02
 *****************************************/

#include "stack.h"
#include <cstdio>
#include <cstdlib>

//
template<typename T>
Stack<T>::Stack() {
	this->stackTop = new Node<T>();
}

//
template<typename T>
int Stack<T>::isEmpty() {
	return this->stackTop->next == NULL;
}

//
template<typename T>
void Stack<T>::makeEmpty() {
	if (this->stackTop->next == NULL) {
		return;
	} else {
		while (!this->isEmpty()) {
			this->pop();
		}
	}
}

//
template<typename T>
void Stack<T>::push(T x) {
	Node<T> tmpNode = new Node<T>();

	if (tmpNode == NULL) {
		return;
	} else {
		tmpNode->element = x;
		tmpNode->next = this->stackTop->next;
		this->stackTop->next = tmpNode;
	}
}

//
template<typename T>
T Stack<T>::top() {
	if (!this->isEmpty()) {
		return this->stackTop->element;
	} else {
		return 0;
	}
}

//
template<typename T>
void Stack<T>::pop() {
	Node<T> firstNode;

	if (this->isEmpty()) {
		return;
	} else {
		firstNode = this->stackTop->next;
		this->stackTop->next = this->stackTop->next->next;
		delete firstNode;
	}
}
