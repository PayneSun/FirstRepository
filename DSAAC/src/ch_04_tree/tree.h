/******************************************
 * ch_04_tree/tree.h
 *
 * 2017.10.28
 *****************************************/


#ifndef TREE_H


struct TreeNode;
typedef int ElemType;
typedef struct TreeNode *PtrToNode;

struct TreeNode {
	ElemType Element;
	PtrToNode FirstChild;
	PtrToNode NextSibling;
};


typedef struct BinaryTreeNode {
	ElemType Element;
	BinaryTree Left;
	BinaryTree Right;
} *BinaryTree;


#endif //TREE_H
