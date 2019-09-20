// 数据结构（C语言描述）.严蔚敏
// 第6章.树和二叉树
// tree.h


#include "public.h"


// ***************
// ADT: BinaryTree
// ***************

// 二叉树的顺序存储表示
#define MAX_TREE_SIZE 100
typedef ElemType SqBiTree[];
SqBiTree bt;


// 二叉树的二叉链表存储表示
typedef struct BiTNode {
	ElemType data;
	BiTNode *lchild;   // 左孩子指针
	BiTNode *rchild;   // 右孩子指针
} BiTNode, *BiTree;

// 基本操作的函数原型声明
Status CreateBiTree(BiTree bt);
Status PreOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));
Status InOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));
Status PostOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));
Status LevelOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));

// 算法6.1 ~ 6.4


// 二叉树的二叉线索存储表示
typedef enum PointerTag {
	Link, Thread
} PointerTag;

typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;

// 算法6.5 ~ 6.7


// 树的双亲表存储表示
typedef struct {
	ElemType data;
	int parent;   // 双亲位置域
} PTNode ;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int r;   // 根位置
	int n;   // 结点数
} PTree;


// 树的孩子链表存储表示
typedef struct {
	int child;
	CTNode *next;
} *CTNode, *ChildPtr;

typedef struct {
	ElemType data;
	ChildPtr first_child;
} CTBox;

typedef struct {
	CTBox nodes[MAX_TREE_SIZE];
	int r;   // 根位置
	int n;   // 结点数
} CTree;


// 树的二叉链表（孩子-兄弟）存储表示
typedef struct {
	ElemType data;
	CSNode *first_child, *next_sibling;
} CSNode, *CSTree;


// ***************
// ADT: MFSet
// ***************

typedef PTree MFSet;

int find_mfset(MFSet mfs, int i);   // 算法6.8
Status merge_mfset(MFSet mfs, int i, int j);   // 算法6.9
Status mix_mfset(MFSet mfs, int i, int j);   // 算法6.10
int fix_mfset(MFSet mfs, int i);   // 算法6.11


// ***************
// ADT: HuffmanTree
// ***************

// 赫夫曼树和赫夫曼编码的存储表示
typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;   // 动态分配数组存储赫夫曼树

typedef char **HuffmanCode;   // 动态分配数组存储赫夫曼编码表


// 算法6.12
void HuffmanCoding(HuffmanTree ht, HuffmanCode hc,
		           int *w, int n) {
	// w存放n个字符的权值（正数），构造赫夫曼树ht，并求出n个字符的赫夫曼编码hc
	if (n <= 1) { return; }
	int m = 2 * n - 1;   // 结点总数
	ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	HuffmanTree p = ht;
	for (int i = 1; i <= n; ++i, ++p, ++w) {
		*p->weight = *w;
		*p->parent = *p->lchild = *p->rchild = 0;
	}
	for (int i = 1; i <= m; ++i, ++p) {
		*p->weight = *p->parent = *p->lchild = *p->rchild = 0;
	}
	// 建赫夫曼树
	for (int i = n + 1; i <= m; ++i) {
		// 在ht[1..i-1]选择parent为0且weight最小的两个结点，其序号分别为s1和s2。
		HTNode s1, s2;
		// TBD: Select(ht, i - 1, s1, s2);
		ht[s1].parent = ht[s2].parent = i;
		ht[i].lchild = s1;
		ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}
	// 从叶子到根逆向求每个字符的赫夫曼编码
	hc = (HuffmanCode)malloc((n + 1) * sizeof(char *));   // 分配n个字符编码的头指针向量
	char *cd = (char *)malloc(n * sizeof(char));   // 分配求编码的工作空间
	cd[n - 1] = '\0';                              // 编码结束符
	for (int i = 1; i <= n; ++i) {                 // 逐个字符求赫夫曼编码
		int start = n - 1;                         // 编码结束符位置
		int f = ht[i].parent;
		for (int c = i; f != 0; c = f, f = ht[f].parent) {   // 从叶子到根逆向求编码
			if (ht[f].lchild == c) {
				cd[--start] = "0";
			} else {
				cd[--start] = "1";
			}
		}
		hc[i] = (char *)malloc((n - start) *  sizeof(char));   // 为第i个字符编码分配空间
		strcpy(hc[i], &cd[start]);
	}
	free(cd);
}



