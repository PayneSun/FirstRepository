// Question 100: Same Tree
//
// 2019/08/05


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //base
        if (p == q && !p) {
            return true;
        }

        if (p && q) {
            return (p->val == q->val) && \
                isSameTree(p->left, q->left) && \
                isSameTree(p->right, q->right);
        }

        return false;
    }
};
