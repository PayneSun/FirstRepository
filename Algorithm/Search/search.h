// ���ݽṹ��C����������.��ε��
// ��9��.����
// search.h
// 2016.10.17

typedef int KeyType;

typedef struct {
	KeyType key;   // �ؼ�����
	//...          // ������
} ElemType;

// ��ֵ�͹ؼ���
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


// ��̬���ұ��˳��洢�ṹ
typedef struct {
	ElemType *elem;   // ����Ԫ�صĴ洢�ռ��ַ��0�ŵ�Ԫ����
	int length;       // ����
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


// ���������������Ͷ���
typedef struct BSTNode {
	ElemType data;
	int bf;                     // ����ƽ������
	BSTNode *lchild, *rchild;   // ���Һ���ָ��
} BSTNode, *BSTree;


// B���������Ͷ���
#define m 3    // ����
typedef struct BTNode {
	int key_num;          // �ؼ��ֵĸ���
	BTNode *parent;       // ˫�׽��
	KeyType key[m+1];     // �ؼ���������0�ŵ�Ԫδ��
	BTNode *prt[m+1];     // ����ָ������
	Record *recptr[m+1];  // ��¼ָ��������0�ŵ�Ԫδ��
} BTNode, *BTree;

typedef struct {
	BTNode *pt;   // ָ���ҵ��Ľ��
	int i;		  // �ڽ���еĹؼ������
	int tag;      // 1�����ҳɹ���0������ʧ��
} Result;



// �㷨9.01
int Search_Seq(SSTable st, KeyType key);

// �㷨9.02
int Search_Bin(SSTable st, KeyType key);

// �㷨9.03
void SecondOptimal(BiTree bt, ElemType r[], float sw[], int low, int high);

// �㷨9.04
typedef BiTree SOSTree;   // �����Ȳ��������ö�������Ĵ洢�ṹ
Status CreateSOSTree(SOSTree sost, SSTable sst);
