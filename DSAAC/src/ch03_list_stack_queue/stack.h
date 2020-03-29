/******************************************
 * ch_03_list_stack_queue/stack.h
 *
 * 2017.10.17
 *****************************************/

#ifndef CH_03_LIST_STACK_QUEUE_STACK_H_
#define CH_03_LIST_STACK_QUEUE_STACK_H_


struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;


int IsEmpty(Stack S);
Stack CreateStackEmpty(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);


#endif /* CH_03_LIST_STACK_QUEUE_STACK_H_ */
