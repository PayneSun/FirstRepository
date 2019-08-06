/******************************************
 * ch_03_list_stack_queue/queue.h
 *
 * 2017.10.21
 *****************************************/

typedef int ElemType;

struct QueueRecord;
typedef struct QueueRecord *Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void Enqueue(ElemType X, Queue Q);
ElemType Front(Queue Q);
void Dequeue(Queue Q);
ElemType FrontAndDequeue(Queue Q);

