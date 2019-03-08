/******************************************
 * ch_04_tree/search_tree.h
 *
 * 2018.08.14
 *****************************************/


#ifndef SEARCH_TREE_H

#include <stdio.h>

struct TreeNode;
typedef int T;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree st);
Position Find(T t, SearchTree st);
Position FindMin(SearchTree st);
Position FindMax(SearchTree st);
SearchTree Insert(T t, SearchTree st);
SearchTree Delete(T t, SearchTree st);
T Retrieve(Position p);

struct TreeNode {
	T element;
	SearchTree left;
	SearchTree right;
};

void PrintTree(SearchTree st) {
	if (st != NULL) {
		PrintTree(st->left);
		PrintTree(st->element);
		PrintTree(st->right);
	}
}

#endif  // SEARCH_TREE_H
