/******************************************
 * ch03_list_stack_queue/queue.h
 *
 * 2020.03.31
 *****************************************/

#include "define.h"

class QueueRecord;
typedef class QueueRecord *Queue;

class QueueRecord {
private:
	QueueRecord();
public:
	int IsEmpty(Queue Q);
	int IsFull(Queue Q);
	Queue CreateQueue(int MaxElements);
	void DisposeQueue(Queue Q);
	void MakeEmpty(Queue Q);
	void Enqueue(ElementType X, Queue Q);
	ElementType Front(Queue Q);
	void Dequeue(Queue Q);
	ElementType FrontAndDequeue(Queue Q);
};
