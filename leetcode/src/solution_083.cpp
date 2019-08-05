// Question 083: Remove Duplicates from Sorted List
//
// 2019/08/05


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) { return head; }

        ListNode *ph = NULL, *pn = NULL, *pt = NULL;
        int value;
        while (head) {
            if (!ph) {
                ph = new ListNode(head->val);
                pn = ph;
                value = head->val;
            }
            if (value != head->val) {
                pt = new ListNode(head->val);
                pn->next = pt;
                pn = pn->next;
                value = head->val;
            }

            head = head->next;
        }

        return ph;
    }
};
