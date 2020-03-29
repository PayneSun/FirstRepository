/******************************************
 * ch_04_tree/avl_tree.h
 *
 * 2018.08.22
 *****************************************/

#ifndef CH_04_TREE_AVL_TREE_H_
#define CH_04_TREE_AVL_TREE_H_

struct AVLNode;
typedef struct AVLNode *Position;
typedef struct AVLNode *AVLTree;
typedef ElementType T;

AVLTree MakeEmpty(AVLTree avlt);
Position Find(T t, AVLTree avlt);
Position FindMin(AVLTree avlt);
Position FindMax(AVLTree avlt);
AVLTree Insert(T t, AVLTree avlt);
AVLTree Delete(T t, AVLTree avlt);
T Retrieve(Position p);



#endif /* CH_04_TREE_AVL_TREE_H_ */
