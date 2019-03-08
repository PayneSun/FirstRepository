/******************************************
 * ch_06_priority_queue_heap/binary_queue.h
 *
 * 2018.09.05
 *****************************************/

#ifndef CH_06_PRIORITY_QUEUE_HEAP_BINARY_QUEUE_H_
#define CH_06_PRIORITY_QUEUE_HEAP_BINARY_QUEUE_H_


#define MaxTrees 1000

typedef struct BinNode *BinTree;
typedef struct BinNode *Position;
typedef struct Collection *BinQueue;

struct BinNode {
	ElementType Element;
	Position LeftChild;
	Position NextSibling;
};

struct Collection {
	int CurrentSize;
	BinTree TheTrees[MaxTrees];
};


#endif /* CH_06_PRIORITY_QUEUE_HEAP_BINARY_QUEUE_H_ */
