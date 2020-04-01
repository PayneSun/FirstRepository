/******************************************
 * ch03_list_stack_queue/list.cpp
 *
 * 2020.03.31
 *****************************************/

#include "list.h"
#include <iostream>


List::List() {
	this->head = new Node();
	this->head->next = NULL;
}

// Return true if List is empty.

bool List::isEmpty() {
	return this->head->next == NULL;
}

// Return true if P is the last position in list.
// Parameter List is unused in this implementation.

bool List::isLast(Pos pos) {
	return pos->next == NULL;
}

// Return Position of X in list or NULL if not found.

Pos List::find(int x) {
	Pos posRet = this->head->next;
	while (posRet && posRet->element != x) {
		posRet = posRet->next;
	}

	return posRet;
}

// If X is not found, then Next field of returned
// Position is NULL. Assume a header.

Pos List::findPrevious(int x) {
	Pos posRet = this->head;
	while (posRet && posRet->next->element != x) {
		posRet = posRet->next;
	}

	return posRet;
}

// Delete first occurrence of X from a list,
// assume use of a header node.

void List::deleteElement(int x) {
	Pos posPrev, posTemp;

	posPrev = this->findPrevious(x);
	if (!this->isLast(posPrev)) {
		posTemp = posPrev->next;
		posPrev->next = posTemp->next;
		delete posTemp;
	}
}

// Insert x after legal position pos.

void List::insert(int x, Pos pos) {
	Pos posCurr = new Node();
	posCurr->element = x;

	posCurr->next = pos->next;
	pos->next = posCurr;
}

// Delete list.

List::~List() {
	Pos posCurr = this->head->next, posTemp;
	while (posCurr) {
		posTemp = posCurr->next;
		delete posCurr;
		posCurr = posTemp;
	}

	delete this->head;
}
