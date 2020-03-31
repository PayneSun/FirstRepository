/******************************************
 * ch_03_list_stack_queue/stack.h
 *
 * 2017.10.17
 *****************************************/

#include "define.h"

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
