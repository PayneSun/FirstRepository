// 数据结构（C语言描述）.严蔚敏
// 第2章.线性表
// list.h
// 2016.09.18


#include "public.h"


// ***************
// ADT: List
// ***************

// 线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100   // 初试分配量
#define LIST_INCREMENT 10    // 再分配增量

typedef struct {
	ElemType *elem;   // 存储空间基址
	int length;       // 当前长度
	int list_size;    // 当前分配的储存容量
} SqList;

// 算法2.3 ~ 2.7


// 线性表的静态单链表存储结构
#define MAX_SIZE 1000   // 链表的最大长度

typedef struct {
	ElemType data;
	int cur;
} Component, SLinkList[MAX_SIZE];

// 算法2.13 ~ 2.17


// 线性表的双向链表存储结构
typedef struct {
	ElemType data;
	DulNode *prior;
	DulNode *next;
} DulNode, *DulLinkList;

// 算法2.18 ~ 2.19


// 一个带头结点的线性链表类型
typedef struct {
	ElemType element;
	Node next;
} *Node, *Position;

typedef struct {
	Node head, tail;   // 分别指向线性链表中的头结点和最后一个结点
	int len;           // 指示线性链表中数据元素的个数
} LinkList;

// 基本操作的函数原型声明
Status MakeNode(Node p, ElemType e);
void FreeNode(Node p);
Status InitList(LinkList ll);
Status DestroyList(LinkList ll);
Status ClearList(LinkList ll);
Status InsFirst(Node h, Node s);
Status DelFirst(Node h, Node s);
Status Apped(LinkList h, Node s);
Status Remove(LinkList h, Node s);
Status InsBefore(LinkList h, Node p, Node s);
Status InsAfter(LinkList l, Node p, Node s);
Status SetCurElem(Node p, ElemType e);
ElemType GetCurElem(Node p);
Status ListEmpty(LinkList l);
int ListLength(LinkList l);
Position GetHead(LinkList l);
Position PriorPos(LinkList, Node p);
Position NextPos(LinkList p, Node p);
Status LocatePos(LinkList l, int i, Node p);
Position LocateElem(LinkList l, ElemType e, Status (*compare)(ElemType, ElemType));
Status ListTraverse(LinkList l, Status (*visit)());


// 算法2.20
Status ListInsert_L(LinkList l, int ,ElemType et);

// 算法2.21
Status MergeList_L(LinkList la, LinkList lb, LinkList lc,
		           int (*compare)(ElemType, ElemType));


/*

// 算法2.1
void Union(LinkList la, LinkList lb);

// 算法2.2
void MergeList(LinkList la, LinkList lb, LinkList lc);

// 算法2.3
bool InitList_Sq(SqList l);

// 算法2.4
bool ListInsert_Sq(SqList l, int i, ElemType et);

// 算法2.5
bool ListDelete_Sq(SqList l, int i, ElemType et);



