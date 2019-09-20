//
// LinkedList.h
// 2019.09.20


#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct ListNode{
	ListNode *pNext;
	int value;
};


void addNode(ListNode **pHead, int value);
void removeNode(ListNode **pHead, int value);




#endif //LINKED_LIST_H
