/******************************************
 * ch_03_list_stack_queue/list.c
 *
 * 2017.10.17 PayneSun
 *****************************************/


#include "list.h"

#include <stdio.h>
#include <stdlib.h>


/*
 * Definition of Node.
 */
struct Node
{
	ElemType Element;
	Position Next;
};


/*
 * 多项式ADT的数组实现
 */
typedef struct {
	int CoeffArray[MaxDegree + 1];
	int HighPower;
} *Polynomial;


/*
 * 多项式ADT的指针实现
 */
typedef struct PolyNode *PtrToPolyNode;
typedef struct PolyNode {
	int Coefficient;
	int Exponent;
	PtrToPolyNode Next;
} Polynomial2;


/*
 * Return true if L is empty.
 */
int IsEmpty(List L)
{
	return L->Next == NULL;
}


/*
 * Return true if P is the last position in list L.
 * Parameter L is unused in this implementation.
 */
int IsLast(Position P, List L)
{
	return P->Next == NULL;
}


/*
 * Return Position of X in L or NULL if not found.
 */
Position Find(ElemType X, List L)
{
	Position P;

	P = L->Next;
	while (P != NULL && P->Element != X) {
		P = P->Next;
	}

	return P;
}


/*
 * If X is not found, then Next field of returned
 * Position is NULL. Assume a header.
 */
Position FindPrevious(ElemType X, List L)
{
	Position P;

	P = L;
	while (P->Next != NULL && P->Next->Element != X) {
		P = P->Next;
	}

	return P;
}


/*
 * Delete first occurrence of X from a list,
 * assume use of a header node.
 */
void Delete(ElemType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if (!IsLast(P, L)) {
		TmpCell = P->Next;
		P->Next = TmpCell->Next;
		free(TmpCell);
	}
}


/*
 * Insert X after legal position P.
 */
void Insert(ElemType X, List L, Position P)
{
	Position TmpCell;

	if((TmpCell = malloc(sizeof(struct Node))) != NULL) {
		TmpCell->Element = X;
		TmpCell->Next = P->Next;
		P->Next = TmpCell;
	}
}


/*
 * Delete List L.
 */
void DeleteList(List L)
{
	Position P, Tmp;

	P = L->Next;
	L->Next = NULL;
	while (P != NULL) {
		Tmp = P->Next;
		free(P);
		P = Tmp;
	}
}

