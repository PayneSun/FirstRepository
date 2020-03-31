/******************************************
 * ch03_list_stack_queue/list.cpp
 *
 * 2020.03.31
 *****************************************/

#include "list.h"
#include <iostream>

template<typename T>
List<T>::List() {
	this->head = new Node<T>();
	this->head->next = NULL;
}

// Return true if List is empty.
template<typename T>
bool List<T>::isEmpty() {
	return this->head->next == NULL;
}

// Return true if P is the last position in list.
// Parameter List is unused in this implementation.
template<typename T>
bool List<T>::isLast(Pos pos) {
	return pos->next == NULL;
}

// Return Position of X in list or NULL if not found.
template<typename T>
Pos List<T>::find(T x) {
	Pos posRet = this->head->next;
	while (posRet && posRet->element != x) {
		posRet = posRet->next;
	}

	return posRet;
}

// If X is not found, then Next field of returned
// Position is NULL. Assume a header.
template<typename T>
Pos List<T>::findPrevious(T x) {
	Pos posRet = this->head;
	while (posRet && posRet->next->element != x) {
		posRet = posRet->next;
	}

	return posRet;
}

// Delete first occurrence of X from a list,
// assume use of a header node.
template<typename T>
void List<T>::deleteElement(T x) {
	Pos posPrev, posTemp;

	posPrev = this->findPrevious(x);
	if (!this->isLast(posPrev)) {
		posTemp = posPrev->next;
		posPrev->next = posTemp->next;
		delete posTemp;
	}
}

// Insert x after legal position pos.
template<typename T>
void List<T>::insert(T x, Pos pos) {
	Pos posCurr = new Node<T>();
	posCurr->element = x;

	posCurr->next = pos->next;
	pos->next = posCurr;
}

// Delete list.
template<typename T>
List<T>::~List() {
	Pos posCurr = this->head->next, posTemp;
	while (posCurr) {
		posTemp = posCurr->next;
		delete posCurr;
		posCurr = posTemp;
	}

	delete this->head;
}
