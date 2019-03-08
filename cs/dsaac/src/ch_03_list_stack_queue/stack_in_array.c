/******************************************
 * ch_03_list_stack_queue/stack_in_array.c
 *
 * 2018.08.12
 *****************************************/

#include "../ch_03_list_stack_queue/stack_in_array.h"

#define EmptyTOS (-1)
#define MinStackSize (-5)


/*
 *
 */
struct StackRecord {
	int Capacity;
	int TopOfStack;
	ElemType *Array;
};


/*
 *
 */
Stack CreateStack(int MaxElements) {
	if (MaxElements < MinStackSize) {
		return NULL;
	}

	Stack S;
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL) {
		return NULL;
	}

	S->Array = malloc(sizeof(struct StackRecord) * MaxElements);
	if (S->Array == NULL) {
		return NULL;
	}
	S->Capacity = MaxElements;
	MakeEmpty(S);

	return S;
}


/*
 *
 */
void DisposeStack(Stack S) {
	if (S != NULL) {
		free(S->Array);
		free(S);
	}
}


/*
 *
 */
int IsEmpty(Stack S) {
	return S->TopOfStack == EmptyTOS;
}


/*
 *
 */
void MakeEmpty(Stack S) {
	S->TopOfStack = EmptyTOS;
}


/*
 *
 */
void Push(ElemType X, Stack S) {
	if (IsFull(S)) {
		return;
	} else {
		S->Array[++S->TopOfStack] = X;
	}
}


/*
 *
 */
ElemType Top(Stack S) {
	if (!IsEmpty(S)) {
		return S->Array[S->TopOfStack];
	}

	return 0;
}


/*
 *
 */
void Pop(Stack S) {
	if (IsEmpty(S)) {
		return;
	} else {
		S->TopOfStack--;
	}
}


/*
 *
 */
ElemType TopAndPop(Stack S) {
	if (!IsEmpty(S)) {
		return S->Array[S->TopOfStack--];
	}

	return 0;
}

