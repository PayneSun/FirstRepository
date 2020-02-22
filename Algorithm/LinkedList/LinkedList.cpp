// LinkedList/
// LinkedList.cpp
// 2019.09.20

#include "LinkedList.h"
#include <iostream>


// 追加节点
void appendNode(ListNode **pHead, int value)
{
	ListNode *pNew = new ListNode();
	pNew->value = value;
	pNew->pNext = NULL;

	if (*pHead == NULL) {
		*pHead = pNew;
	} else {
		ListNode *pNode = *pHead;
		while (pNode->pNext != NULL) {
			pNode = pNode->pNext;
		}
		pNode->pNext = pNew;
	}
}


// 删除第一个符合指定值的节点
void removeNode(ListNode **pHead, int value)
{
	// 空链表
	if (pHead == NULL || *pHead == NULL) {
		return;
	}

	ListNode *pDeletedNode = NULL;
	if ((*pHead)->value == value) {  // 如果被删除节点是链表首部
		pDeletedNode = *pHead;
		*pHead = (*pHead)->pNext;
	} else {
		ListNode *pNode = *pHead;
		while (pNode->pNext != NULL && pNode->pNext->value != value) {  // 找到待删除节点前一个节点
			pNode = pNode->value;
		}

		if (pNode->pNext != NULL && pNode->pNext->value == value) {  // 如果待删除节点不是尾部
			pDeletedNode = pNode->pNext;
			pNode->pNext = pNode->pNext->pNext;
		}
	}

	if (pDeletedNode != NULL) {  // 包含待删除节点是链表尾部的情况，可以直接删除
		delete pDeletedNode;
		pDeletedNode = NULL;
	}
}
