/******************************************
 * ch_03_list_stack_queue/list.h
 *
 * 2017.10.01 PayneSun
 *****************************************/

#ifndef CH_03_LIST_STACK_QUEUE_H
#define CH_03_LIST_STACK_QUEUE_H


#define MaxDegree 100
typedef int ElemType;


struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List CreateList(ElemType Data[]);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElemType X, List L);
void Delete(ElemType X, List L);
Position FindPrevioud(ElemType X, List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElemType Retrieve(Position P);




#endif /* CH_03_LIST_STACK_QUEUE_H */
