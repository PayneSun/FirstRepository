// 数据结构（C语言描述）.严蔚敏
// 第10章.排序
// internal_sort.h
// 2016.10.23


#define MAX_SIZE 20   // 一个用作示例的小顺序表的最大长度

typedef int KeyType;  // 定义关键字类型为整型类型

typedef struct {
	KeyType key;		   // 关键字项
	InfoType other_info;   // 其他数据项
} RedType;                 // 记录类型

typedef struct {
	RedType r[MAX_SIZE+1];   // r[0]闲置或用作哨兵单元
	int length;              // 顺序表长度
}SqList;					 // 顺序表类型

typedef SqList HeapType;

// -->Radix Sorting
#define MAX_NUM_OF_KEY 8      // 关键字项数的最大值
#define RADIX          10     // 关键字基数，此时是十进制整数的基数
#define MAX_SPACE      1000
typedef struct {
	KeyType keys[MAX_NUM_OF_KEY];   // 关键字
	InfoType other_items;           // 其他数据项
	int next;
} SLCell;                           // 静态链表的结点类型
typedef struct {
	SLCell r[MAX_SPACE];   // 静态链表的可利用空间，r[0]为头结点
	int key_num;           // 记录的当前关键字个数
	int rec_num;           // 静态链表的当前长度
} SLList;                  // 静态链表类型
typedef int ArrType[RADIX];   // 指针数组类型
// --<Radix Sorting


// 算法10.01
void InsertSort(SqList sl);


// 算法10.02
void BInsertSort(SqList sl);


// 算法10.04
void ShellInsert(SqList sl, int dk);


// 算法10.05
void ShellSort(SqList sl, int dlta[], int t);


// 算法10.06(a)
int Partition(SqList sl, int low, int high);


// 算法10.06(b)
int Partition(SqList sl, int low, int high);


// 算法10.07
void QSort(SqList sl, int low, int high);


// 算法10.08
void QSort(SqList sl);


// 算法10.09
void SelectSort(SqList sl);


// 算法10.10
void HeapAdjust(HeapType ht, int s, int m);


// 算法10.11
void HeapSort(HeapType ht);


// 算法10.12
void Merge(RedType sr[], RedType tr[], int i, int m, int n);


// 算法 10.13
void MSort(RedType sr[], RedType tr[], int s, int t);


// 算法10.14
void MergeSort(SqList sl);


// 算法10.15
void Distribute(SLCell r, int i, ArrType f, ArrType e);


// 算法10.16
void Collect(SLCell r, int i , ArrType f, ArrType e);


// 算法10.17
void RadixSort(SLList sll);
