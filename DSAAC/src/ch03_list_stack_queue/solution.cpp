/******************************************
 * ch03_list_stack_queue/solution.cpp
 *
 * 2020.04.06
 *****************************************/

#include "list.h"
#include <iostream>

// question-3.1
void printList(List *pList) {
	Node *pNode = pList->header();

	while ((pNode = pNode->next) != NULL)  {
		std::cout << pNode->element << std::endl;
	}
}


int main() {
	// solution for 3.1
	List *pList = new List();
	pList->insert(5, pList->header());
	pList->insert(3, pList->header());
	pList->insert(2, pList->header());
	printList(pList);

	return 0;
}
