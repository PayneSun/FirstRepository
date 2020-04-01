/******************************************
 * ch03_list_stack_queue/list_in_cursor.cpp
 *
 * 2020.04.01
 *****************************************/

#include "list_in_cursor.h"

//
static Position cursorAlloc(void) {
	Position pos;
	pos = CursorSpace[0].next;
	CursorSpace[0].next = CursorSpace[pos].next;

	return pos;
}

//
static void cursorFree(Position pos) {
	CursorSpace[pos].next = CursorSpace[0].next;
	CursorSpace[0].next = pos;
}

//
int isEmpty(List list) {
	return CursorSpace[list].next == 0;
}

//
int isLast(Position pos, List list) {
	return CursorSpace[pos].next == 0;
}

//
Position find(int x, List list) {
	Position pos;

	pos = CursorSpace[list].next;
	while (pos && CursorSpace[pos].element != x) {
		pos = CursorSpace[pos].next;
	}

	return pos;
}

//
void deleteElement(int x, List list) {
	Position pos, posTmp;

	pos = findPrevious(x, list);
	if (!isLast(pos, list)) {
		posTmp = CursorSpace[pos].next;
		CursorSpace[pos].next = CursorSpace[posTmp].next;
		cursorFree(posTmp);
	}
}

//
void insert(int x, List list, Position pos) {
	Position posTmp;

	posTmp = cursorAlloc();
	if (posTmp == 0) {
		return;
	}

	CursorSpace[posTmp].element = x;
	CursorSpace[posTmp].next = CursorSpace[pos].next;
	CursorSpace[pos].next = posTmp;
}
