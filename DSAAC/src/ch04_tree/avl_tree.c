/******************************************
 * ch_04_tree/avl_tree.c
 *
 * 2018.08.22
 *****************************************/


#include "../ch_04_tree/avl_tree.h"
#include <stdio.h>


/*
 *
 */
struct AVLNode {
	T element;
	AVLTree left;
	AVLTree right;
	int height;
};


/*
 *
 */
static int Height(Position p) {
	if (p == NULL) {
		return -1;
	} else {
		return p->height;
	}
}


/*
 *
 */
AVLTree Insert(T t, AVLTree avlt) {
	if (avlt == NULL) {
		// Create and return a one-node tree
		avlt = malloc(sizeof(struct AVLNode));
		if (avlt == NULL) {
			FatalError("Out of space!!!");
		} else {
			avlt->element = t;
			avlt->height = 0;
			avlt->left = avlt->right = NULL;
		}
	} else if (t < avlt->element) {
		avlt->left = Insert(t, avlt->left);
		if (Height(avlt->left) - Height(avlt->right) == 2) {
			if (t < avlt->left->element) {
				avlt = SingleRotateWithLeft(avlt);
			} else {
				avlt = DoubleRotateWithLeft(avlt);
			}
		}
	} else if (t > avlt->element) {
		avlt->right = Insert(t, avlt->right);
		if (Height(avlt->right) - Height(avlt->left) == 2) {
			if (t > avlt->right->element) {
				avlt = SingleRotateWithRight(avlt);
			} else {
				avlt = DoubleRotateWithRight(avlt);
			}
		}
	} else {
		// This value has existed, do nothing.
	}

	avlt->height = Max(Height(avlt->left), Height(avlt->right)) + 1;

	return avlt;
}


/*
 * This function can be called only if K2 has a left child.
 * Perform a rotate between a node (K2) and its left child.
 * Update heights, then return new tree root.
 */
static Position SingleRotateWithLeft(Position K2) {
	Position K1;

	K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;

	K2->height = Max(Height(K2->left), Height(K2->right)) + 1;
	K1->height = Max(Height(K1->left), Height(K1->right)) + 1;

	return K1;
}


/*
 * todo
 */
static Position SingleRotateWithRight(Position K2) {
	Position K1;

//	K1 = K2->left;
//	K2->left = K1->right;
//	K1->right = K2;
//
//	K2->height = Max(Height(K2->left), Height(K2->right)) + 1;
//	K1->height = Max(Height(K1->left), Height(K1->right)) + 1;

	return K1;
}



/*
 * This function can be called only K3 has a left
 * child and K3's left child has a right child.
 * Do the left-right double rotation
 * Update heights, then return new tree root.
 */
static Position DoubleRotateWithLeft(Position K3) {
	// Rotate between K1 and K2.
	K3->left = SingleRotateWithRight(K3->left);

	// Rotate between K3 and K2.
	return SingleRotateWithLeft(K3);
}


/*
 * todo
 */
static Position DoubleRotateWithRight(Position K3) {
	// Rotate between K1 and K2.
	K3->left = SingleRotateWithRight(K3->left);

	// Rotate between K3 and K2.
	return SingleRotateWithLeft(K3);
}
