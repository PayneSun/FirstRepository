// Q06_ConstructBinaryTree.cpp
//
// 2019.09.23

#include <iostream>


struct BinaryTreeNode {
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;
};


BinaryTreeNode* construct(int *preOrder, int *inOrder, int length);
BinaryTreeNode* constructCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder);


BinaryTreeNode* construct(int *preOrder, int *inOrder, int length)
{
	if (preOrder == NULL || inOrder == NULL || length <= 0) {
		return 0;
	}
	return constructCore(preOrder, preOrder + length - 1, inOrder, inOrder + length - 1);
}


BinaryTreeNode* constructCore(int *startPreOrder, int *endPreOrder, int *startInOrder, int *endInOrder)
{
	// 前序遍历序列的第一个数字是根结点的值
	int rootValue = startPreOrder[0];
	BinaryTreeNode *root = new BinaryTreeNode();
	root->value = rootValue;
	root->left = root->right = NULL;

	// 当前前序和中序遍历序列只有一个值
	if (startPreOrder == endPreOrder) {
		if (startInOrder == endInOrder && *startPreOrder == *startInOrder) {
			return root;
		} else {
			std::cerr << "Invalid input." << std::endl;
			return NULL;
		}
	}

	// 在中序遍历中找到根结点的值
	int *rootInOrder = startInOrder;
	while (rootInOrder <= endInOrder && *rootInOrder != rootValue) {
		++rootInOrder;
	}
	if (rootInOrder == endInOrder && *rootInOrder != rootValue) {
		std::cerr << "Invalid input." << std::endl;
		return NULL;
	}
	int leftLength = rootInOrder - startInOrder;
	int *leftPreOrderEnd = startPreOrder + leftLength;
	if (leftLength > 0) {
		// 构建左子树
		root->left = constructCore(startPreOrder + 1, leftPreOrderEnd, startInOrder, rootInOrder-1);
	}
	if (leftLength < endPreOrder - startPreOrder) {
		// 构建右子树
		root->right = constructCore(leftPreOrderEnd + 1, endPreOrder, rootInOrder + 1, endInOrder);
	}

	return root;
}


int main()
{
	return 0;
}
