/******************************************
 * ch_04_tree/tree.c
 *
 * 2018.08.22
 *****************************************/


#include "tree.h"
#include "search_tree.h"


/*
 *
 */
void PrintTree(SearchTree T) {
	if (T != NULL) {
		PrintTree(T->left);
		PrintTree(T->Element);
		PrintTree(T->right);
	}
}


/*
 *
 */
int Height(BinaryTree T) {
	if (T == NULL) {
		return -1;
	} else {
		return 1 + Max(Height(T->Left), Height(T->Right));
	}
}
