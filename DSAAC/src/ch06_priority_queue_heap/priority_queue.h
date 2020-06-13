/******************************************
 * ch_06_priority_queue_heap/priority_queue.h
 *
 * 2017.04.07
 *****************************************/


#ifndef _BinHeap_H
#define _BinHeap_H


#define MinData   -1
#define MinPQSize -1

struct HeapStruct;
typedef int ElementType;
typedef struct HeapStruct *PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);
void Insert(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);
ElementType FindMin(PriorityQueue H);
int isEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);


#endif //_BinHeap_H
