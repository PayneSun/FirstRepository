/******************************************
 * ch03_list_stack_queue/stack_in_array.h
 *
 * 2020.03.31
 *****************************************/

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
