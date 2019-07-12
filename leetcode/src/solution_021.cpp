// Question 021: Merge Two Sorted Lists
//
// 2019/3/24

#include <string>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = NULL, *head = NULL, *pln;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                pln = new ListNode(l1->val);
                l1 = l1->next;
            } else {
                pln = new ListNode(l2->val);
                l2 = l2->next;
            }
            if (!head) {
                head = pln;
                ret = head;
            } else {
                head->next = pln;
                head = head->next;
            }

        }

        while (l1) {
            pln = new ListNode(l1->val);
            if (!head) {
                head = pln;
                ret = head;
            } else {
                head->next = pln;
                head = head->next;
            }

            l1 = l1->next;
        }
        while (l2) {
            pln = new ListNode(l2->val);

            if (!head) {
                head = pln;
                ret = head;
            } else {
                head->next = pln;
                head = head->next;
            }

            l2 = l2->next;
        }

        return ret;
    }
};
