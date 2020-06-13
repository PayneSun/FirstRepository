// Question 019: Remove Nth Node From End of List
//
// 2019/08/09

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 统计链表长度
        ListNode *th = head;
        int len = 0;
        while (th) {
            len++;
            th = th->next;
        }
        // 如果长度不及要删除的位置
        if (len < n) {
            return head;
        }
        // 如果删除的位置刚好是链表首部
        if (len == n) {
            th = head;
            head = head->next;
            delete th;
            return head;
        }

        int index = 1;
        ListNode *nh = head;
        while (index != len - n) {
            head = head->next;
            index++;
        }
        // 如果删除的是链表的尾部
        if (index + 1 == len) {
            delete head->next;
            head->next = NULL;
        } else {
            th = head->next;
            head->next = th->next;
            delete th;
        }
        return nh;
    }
};
