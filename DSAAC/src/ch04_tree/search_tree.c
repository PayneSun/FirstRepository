/******************************************
 * ch_04_tree/search_tree.c
 *
 * 2018.08.14
 *****************************************/


#include "../ch_04_tree/search_tree.h"
#include <stdio.h>

//typedef int T;


/*
 *
 */
SearchTree MakeEmpty(SearchTree st) {
	if (st != NULL) {
		MakeEmpty(st->left);
		MakeEmpty(st->right);
		free(st);
	}
	return NULL;
}


/*
 *
 */
Position Find(T t, SearchTree st) {
	if (st == NULL) {
		return NULL;
	}
	if (t < st->element) {
		return Find(t, st->left);
	} else if (t > st->element) {
		return Find(t, st->right);
	} else {
		return st;
	}
}


/*
 *
 */
Position FindMin(SearchTree st) {
	if (st == NULL) {
		return NULL;
	} else if (st->left != NULL) {
		return FindMin(st->left);
	} else {
		return st;
	}
}


/*
 *
 */
Position FindMax(SearchTree st) {
	if (st != NULL) {
		while(st->right != NULL) {
			st = st->right;
		}
	}
	return st;
}


/*
 *
 */
SearchTree Insert(T t, SearchTree st) {
	if (st == NULL) {
		st = malloc(sizeof(struct TreeNode));
		if (st == NULL) {
			FatalError("Out of space!!!");
		} else {
			st->element = t;
			st->left = st->right = NULL;
		}
		return st;
	}

	if (t < st->element) {
		st->left = Insert(t, st->left);
	} else if (t > st->element) {
		st->right = Insert(t, st->right);
	}

	return st;
}


/*
 *
 */
SearchTree Delete(T t, SearchTree st) {
	Position tmp_cell;

	if (st == NULL) {
		Error("Element not found.");
	} else if (t < st->element) {
		st->left = Delete(t, st->left);
	} else if (t > st->element) {
		st->right = Delete(t, st->right);
	} else if (st->left && st->right) {
		tmp_cell = FindMin(st->right);
		st->element = tmp_cell->element;
		st->right = Delete(st->element, st->right);
	} else {
		tmp_cell = st;
		if (st->left == NULL) {
			st = st->right;
		} else if (st->right == NULL) {
			st = st->left;
		}
		free(tmp_cell);
	}
	return st;
}
