// Question 023: Merge K Sorted Lists
//
// 2020/4/10

#include <vector>
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
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *pt;
		vector<int> ivec;
		for (auto it = lists.begin(); it != lists.end(); ++it) {
			pt = *it;
			while (pt != NULL) {
				ivec.push_back(pt->val);
				pt = pt->next;
			}

		}
		sort(ivec.begin(), ivec.end());

		ListNode *phd = NULL, *pcr;
		for (auto it = ivec.begin(); it != ivec.end(); ++it) {
			if (it == ivec.begin()) {
				phd = new ListNode(*it);
				pcr = phd;
			} else {
				pcr->next = new ListNode(*it);
				pcr = pcr->next;
			}
		}

		return phd;
	}
};
