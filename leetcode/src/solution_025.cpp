// Question 023: Merge K Sorted Lists
//
// 2020/4/10

#include <stack>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		int cnt = 0;
		stack<ListNode*> sln;

		ListNode *pcur = NULL, *pend = head;
		while (pend) {
			for (int i = 0; (pend != NULL) && (i < k); ++i) {
				sln.push(pend);
				pend = pend->next;
			}

			for (int j = 0; (pend != NULL) && (j < k); ++j) {
				if (!pcur) {
					head = sln.top();
					pcur = head;
				} else {
					pcur->next = sln.top();
					pcur = pcur->next;
				}
				sln.pop();
			}
		}

		return head;
	}
};
