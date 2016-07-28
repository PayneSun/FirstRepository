#ifndef TREE_H_
#define TREE_H_

typedef int ElementType;
typedef struct TreeNode* PtrToNode;

struct TreeNode
{
	ElementType Element;
	PtrToNode   FirstChild;
	PtrToNode   NextSibling;
};

#endif  // TREE_H_
