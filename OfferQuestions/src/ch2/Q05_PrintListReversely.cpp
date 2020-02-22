// Q05_PrintListReversely.cpp
//
// 2019.09.23

#include <iostream>
#include <stack>
#include <cstring>


struct ListNode {
	int value;
	ListNode *next;
};


void printListReversely(ListNode **head)
{
	if (*head == NULL || head == NULL) {
		return;
	}

	std::stack<ListNode *> nodeStack;
	ListNode *pNode = *head;
	while (pNode) {
		nodeStack.push(pNode);
		pNode = pNode->next;
	}

	while (!nodeStack.empty()) {
		std::cout << nodeStack.top()->value << std::endl;
		nodeStack.pop();
	}
}


void printListReverselyRecursively(ListNode *pHead)
{
	if (*pHead != NULL) {
		if (pHead->next != NULL) {
			printListReverselyRecursively(pHead->next);
		}

		std::cout << pHead->value << std::endl;
	}
}


int main()
{
	return 0;
}
