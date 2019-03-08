// ���ݽṹ��C����������.��ε��
// ��10��.����
// internal_sort.h
// 2016.10.23


#define MAX_SIZE 20   // һ������ʾ����С˳������󳤶�

typedef int KeyType;  // ����ؼ�������Ϊ��������

typedef struct {
	KeyType key;		   // �ؼ�����
	InfoType other_info;   // ����������
} RedType;                 // ��¼����

typedef struct {
	RedType r[MAX_SIZE+1];   // r[0]���û������ڱ���Ԫ
	int length;              // ˳�����
}SqList;					 // ˳�������

typedef SqList HeapType;

// -->Radix Sorting
#define MAX_NUM_OF_KEY 8      // �ؼ������������ֵ
#define RADIX          10     // �ؼ��ֻ�������ʱ��ʮ���������Ļ���
#define MAX_SPACE      1000
typedef struct {
	KeyType keys[MAX_NUM_OF_KEY];   // �ؼ���
	InfoType other_items;           // ����������
	int next;
} SLCell;                           // ��̬����Ľ������
typedef struct {
	SLCell r[MAX_SPACE];   // ��̬����Ŀ����ÿռ䣬r[0]Ϊͷ���
	int key_num;           // ��¼�ĵ�ǰ�ؼ��ָ���
	int rec_num;           // ��̬����ĵ�ǰ����
} SLList;                  // ��̬��������
typedef int ArrType[RADIX];   // ָ����������
// --<Radix Sorting


// �㷨10.01
void InsertSort(SqList sl);


// �㷨10.02
void BInsertSort(SqList sl);


// �㷨10.04
void ShellInsert(SqList sl, int dk);


// �㷨10.05
void ShellSort(SqList sl, int dlta[], int t);


// �㷨10.06(a)
int Partition(SqList sl, int low, int high);


// �㷨10.06(b)
int Partition(SqList sl, int low, int high);


// �㷨10.07
void QSort(SqList sl, int low, int high);


// �㷨10.08
void QSort(SqList sl);


// �㷨10.09
void SelectSort(SqList sl);


// �㷨10.10
void HeapAdjust(HeapType ht, int s, int m);


// �㷨10.11
void HeapSort(HeapType ht);


// �㷨10.12
void Merge(RedType sr[], RedType tr[], int i, int m, int n);


// �㷨 10.13
void MSort(RedType sr[], RedType tr[], int s, int t);


// �㷨10.14
void MergeSort(SqList sl);


// �㷨10.15
void Distribute(SLCell r, int i, ArrType f, ArrType e);


// �㷨10.16
void Collect(SLCell r, int i , ArrType f, ArrType e);


// �㷨10.17
void RadixSort(SLList sll);
