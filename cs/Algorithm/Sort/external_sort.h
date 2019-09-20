// 数据结构（C语言描述）.严蔚敏
// 第11章.外部排序
// external_sort.h
// 2016.10.23


extern int k = 5;              // 归并的路数
extern int w = 10;             // 工作区容量
extern int MIN_KEY = 0;        // 最小关键字
extern int MAX_KEY = 100000;   // 最大关键字

extern External b;

typedef int LoserTree[k];

typedef struct {
	KeyType key;
} ExNode, External[k+1];   // 外部结点，只存放待归并记录的关键字

typedef struct {
	RcdNode rec;    // 记录
	KeyType key;    // 从记录中抽取的关键字
	int     rnum;   // 所属归并段的段号
} RcdNode, WorkArea[w];


// 算法11.01
void K_Merge(LoserTree ls, External b);

// 算法11.02
void Ajust(LoserTree ls, int s);

// 算法11.03
void CreateLoserTree(LoserTree ls);

// 算法11.04
void Replace_Selection(LoserTree ls, WorkArea wa, FILE *fi, FILE *fo);

// 算法11.05
void Get_Run(LoserTree ls, WorkArea wa);

// 算法11.06
void Select_MiniMax(LoserTree ls, WorkArea wa, int q);

// 算法11.07
void Construct_Loser(LoserTree ls, WorkArea wa);

