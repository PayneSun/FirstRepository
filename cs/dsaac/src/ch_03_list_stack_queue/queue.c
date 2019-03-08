/******************************************
 * ch_03_list_stack_queue/queue.h
 *
 * 2017.10.21
 *****************************************/


#include "queue.h"

#define MinQueueSize (5)


/**
 *
 */
struct QueueRecord {
	int Capacity;
	int Front;
	int Rear;
	int Size;
	ElemType *Array;
};


/**
 *
 */
int IsEmpty(Queue Q) {
	return Q->Size == 0;
}


/**
 *
 */
void MakeEmpty(Queue Q) {
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}


/**
 *
 */
static int Succ(int Value, Queue Q) {
	if (++Value == Q->Capacity) {
		Value = 0;
	}

	return Value;
}


/*
 *
 */
void Enqueue(ElemType X, Queue Q) {
	if (IsFull(Q)) {
		return;
	} else {
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

