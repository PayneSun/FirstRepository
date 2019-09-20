// ���ݽṹ��C����������.��ε��
// ��6��.���Ͷ�����
// tree.h


#include "public.h"


// ***************
// ADT: BinaryTree
// ***************

// ��������˳��洢��ʾ
#define MAX_TREE_SIZE 100
typedef ElemType SqBiTree[];
SqBiTree bt;


// �������Ķ�������洢��ʾ
typedef struct BiTNode {
	ElemType data;
	BiTNode *lchild;   // ����ָ��
	BiTNode *rchild;   // �Һ���ָ��
} BiTNode, *BiTree;

// ���������ĺ���ԭ������
Status CreateBiTree(BiTree bt);
Status PreOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));
Status InOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));
Status PostOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));
Status LevelOrderTraverse(BiTree bt, Status (*Visit)(ElemType et));

// �㷨6.1 ~ 6.4


// �������Ķ��������洢��ʾ
typedef enum PointerTag {
	Link, Thread
} PointerTag;

typedef struct BiThrNode {
	ElemType data;
	struct BiThrNode *lchild, *rchild;
	PointerTag LTag, RTag;
} BiThrNode, *BiThrTree;

// �㷨6.5 ~ 6.7


// ����˫�ױ�洢��ʾ
typedef struct {
	ElemType data;
	int parent;   // ˫��λ����
} PTNode ;

typedef struct {
	PTNode nodes[MAX_TREE_SIZE];
	int r;   // ��λ��
	int n;   // �����
} PTree;


// ���ĺ�������洢��ʾ
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
	int r;   // ��λ��
	int n;   // �����
} CTree;


// ���Ķ�����������-�ֵܣ��洢��ʾ
typedef struct {
	ElemType data;
	CSNode *first_child, *next_sibling;
} CSNode, *CSTree;


// ***************
// ADT: MFSet
// ***************

typedef PTree MFSet;

int find_mfset(MFSet mfs, int i);   // �㷨6.8
Status merge_mfset(MFSet mfs, int i, int j);   // �㷨6.9
Status mix_mfset(MFSet mfs, int i, int j);   // �㷨6.10
int fix_mfset(MFSet mfs, int i);   // �㷨6.11


// ***************
// ADT: HuffmanTree
// ***************

// �շ������ͺշ�������Ĵ洢��ʾ
typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
} HTNode, *HuffmanTree;   // ��̬��������洢�շ�����

typedef char **HuffmanCode;   // ��̬��������洢�շ��������


// �㷨6.12
void HuffmanCoding(HuffmanTree ht, HuffmanCode hc,
		           int *w, int n) {
	// w���n���ַ���Ȩֵ��������������շ�����ht�������n���ַ��ĺշ�������hc
	if (n <= 1) { return; }
	int m = 2 * n - 1;   // �������
	ht = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));
	HuffmanTree p = ht;
	for (int i = 1; i <= n; ++i, ++p, ++w) {
		*p->weight = *w;
		*p->parent = *p->lchild = *p->rchild = 0;
	}
	for (int i = 1; i <= m; ++i, ++p) {
		*p->weight = *p->parent = *p->lchild = *p->rchild = 0;
	}
	// ���շ�����
	for (int i = n + 1; i <= m; ++i) {
		// ��ht[1..i-1]ѡ��parentΪ0��weight��С��������㣬����ŷֱ�Ϊs1��s2��
		HTNode s1, s2;
		// TBD: Select(ht, i - 1, s1, s2);
		ht[s1].parent = ht[s2].parent = i;
		ht[i].lchild = s1;
		ht[i].rchild = s2;
		ht[i].weight = ht[s1].weight + ht[s2].weight;
	}
	// ��Ҷ�ӵ���������ÿ���ַ��ĺշ�������
	hc = (HuffmanCode)malloc((n + 1) * sizeof(char *));   // ����n���ַ������ͷָ������
	char *cd = (char *)malloc(n * sizeof(char));   // ���������Ĺ����ռ�
	cd[n - 1] = '\0';                              // ���������
	for (int i = 1; i <= n; ++i) {                 // ����ַ���շ�������
		int start = n - 1;                         // ���������λ��
		int f = ht[i].parent;
		for (int c = i; f != 0; c = f, f = ht[f].parent) {   // ��Ҷ�ӵ������������
			if (ht[f].lchild == c) {
				cd[--start] = "0";
			} else {
				cd[--start] = "1";
			}
		}
		hc[i] = (char *)malloc((n - start) *  sizeof(char));   // Ϊ��i���ַ��������ռ�
		strcpy(hc[i], &cd[start]);
	}
	free(cd);
}



