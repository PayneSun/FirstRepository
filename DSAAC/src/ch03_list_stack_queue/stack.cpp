/******************************************
 * ch03_list_stack_queue/stack.c
 *
 * 2017.10.17
 *****************************************/

#include "stack.h"
#include <cstdio>
#include <cstdlib>

/*
 *
 */
struct Node {
	ElementType Element;
	PtrToNode Next;
};

/*
 *
 */
int IsEmpty(Stack S) {
	return S->Next == NULL;
}

/*
 *
 */
Stack CreateStack(void) {
	Stack S;

	S = malloc(sizeof(struct Node));
	if (S == NULL) {
		return NULL;
	}
	S->Next = NULL;
	MakeEmpty(S);

	return S;
}

/*
 *
 */
void MakeEmpty(Stack S) {
	if (S == NULL) {
		return;
	} else {
		while (!IsEmpty(S)) {
			Pop(S);
		}
	}
}

/*
 *
 */
void Push(ElementType X, Stack S) {
	PtrToNode TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (TmpCell == NULL) {
		return;
	} else {
		TmpCell->Element = X;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

/*
 *
 */
ElementType Top(Stack S) {
	if (!IsEmpty(S)) {
		return S->Next->Element;
	} else {
		return 0;
	}
}

/*
 *
 */
void Pop(Stack S) {
	PtrToNode FirstCell;

	if (IsEmpty(S)) {
		return;
	} else {
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		free(FirstCell);
	}
}
