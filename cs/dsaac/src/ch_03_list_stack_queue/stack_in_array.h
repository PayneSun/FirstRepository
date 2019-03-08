/******************************************
 * ch_03_list_stack_queue/stack_in_array.h
 *
 * 2017.10.17
 *****************************************/

#ifndef CH_03_LIST_STACK_QUEUE_STACK_IN_ARRAY_H_
#define CH_03_LIST_STACK_QUEUE_STACK_IN_ARRAY_H_

#include <stdio.h>

struct StackRecord;
typedef struct StackRecord *Stack;

int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStackEmpty(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);
ElementType TopAndPop(Stack S);


#endif /* CH_03_LIST_STACK_QUEUE_STACK_IN_ARRAY_H_ */
