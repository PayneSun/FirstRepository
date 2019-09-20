// ���ݽṹ��C����������.��ε��
// ��11��.�ⲿ����
// external_sort.h
// 2016.10.23


extern int k = 5;              // �鲢��·��
extern int w = 10;             // ����������
extern int MIN_KEY = 0;        // ��С�ؼ���
extern int MAX_KEY = 100000;   // ���ؼ���

extern External b;

typedef int LoserTree[k];

typedef struct {
	KeyType key;
} ExNode, External[k+1];   // �ⲿ��㣬ֻ��Ŵ��鲢��¼�Ĺؼ���

typedef struct {
	RcdNode rec;    // ��¼
	KeyType key;    // �Ӽ�¼�г�ȡ�Ĺؼ���
	int     rnum;   // �����鲢�εĶκ�
} RcdNode, WorkArea[w];


// �㷨11.01
void K_Merge(LoserTree ls, External b);

// �㷨11.02
void Ajust(LoserTree ls, int s);

// �㷨11.03
void CreateLoserTree(LoserTree ls);

// �㷨11.04
void Replace_Selection(LoserTree ls, WorkArea wa, FILE *fi, FILE *fo);

// �㷨11.05
void Get_Run(LoserTree ls, WorkArea wa);

// �㷨11.06
void Select_MiniMax(LoserTree ls, WorkArea wa, int q);

// �㷨11.07
void Construct_Loser(LoserTree ls, WorkArea wa);

