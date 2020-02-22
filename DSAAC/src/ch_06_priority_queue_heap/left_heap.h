/******************************************
 * ch_06_priority_queue_heap/left_heap.h
 *
 * 2018.08.31
 *****************************************/

#ifndef CH_06_PRIORITY_QUEUE_HEAP_LEFT_HEAP_H_
#define CH_06_PRIORITY_QUEUE_HEAP_LEFT_HEAP_H_


struct TreeNode;
typedef struct TreeNode *PriorityQueue;

PriorityQueue Initializer(void);
ElementType FindMin(PriorityQueue H);
int IsEmpty(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H))

PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DelelteMin1(PriorityQueue H);


#endif /* CH_06_PRIORITY_QUEUE_HEAP_LEFT_HEAP_H_ */
