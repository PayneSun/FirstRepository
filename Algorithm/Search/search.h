// 数据结构（C语言描述）.严蔚敏
// 第9章.查找
// search.h
// 2016.10.17

typedef int KeyType;

typedef struct {
	KeyType key;   // 关键字域
	//...          // 其他域
} ElemType;

// 数值型关键字
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))


// **********************
// ADT: StaticSearchTable
// **********************
/*
ADT StaticSearchTable {
	Create(st, n);
	Destroy(st);
	Search(st, key);
	Traverse(st, Visit());
} ADT StaticSearchTable
*/


// 静态查找表的顺序存储结构
typedef struct {
	ElemType *elem;   // 数据元素的存储空间基址，0号单元留空
	int length;       // 表长度
} SSTable;


// ***********************
// ADT: DynamicSearchTable
// ***********************
/*
ADT DynamicSearchTable {
	InitDStable(dt);
	DestroyDSTable(dt);
	SearchDSTable(dt, key);
	InsertDSTable(dt, e);
	DeleteDSTable(dt, key);
	TraverseDSTable(dt, Visit());
} ADT DynamicSearchTable
*/


// 二叉排序树的类型定义
typedef struct BSTNode {
	ElemType data;
	int bf;                     // 结点的平衡因子
	BSTNode *lchild, *rchild;   // 左、右孩子指针
} BSTNode, *BSTree;


// B树结点的类型定义
#define m 3    // 阶树
typedef struct BTNode {
	int key_num;          // 关键字的个数
	BTNode *parent;       // 双亲结点
	KeyType key[m+1];     // 关键字向量，0号单元未用
	BTNode *prt[m+1];     // 子树指针向量
	Record *recptr[m+1];  // 记录指针向量，0号单元未用
} BTNode, *BTree;

typedef struct {
	BTNode *pt;   // 指向找到的结点
	int i;		  // 在结点中的关键字序号
	int tag;      // 1：查找成功，0：查找失败
} Result;



// 算法9.01
int Search_Seq(SSTable st, KeyType key);

// 算法9.02
int Search_Bin(SSTable st, KeyType key);

// 算法9.03
void SecondOptimal(BiTree bt, ElemType r[], float sw[], int low, int high);

// 算法9.04
typedef BiTree SOSTree;   // 次优先查找树采用二叉链表的存储结构
Status CreateSOSTree(SOSTree sost, SSTable sst);
