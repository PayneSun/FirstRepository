// 数据结构（C语言描述）.严蔚敏
// 第7章.图
// graph.h


#include "public.h"


// ***************
// ADT: Graph
// ***************
/*
ADT Graph {
	CreateGraph(&G, V, VR);
	DestroyGraph(&G);
	LocateVex(G, u);
	GetVex(G, v);
	PutVex(&G, v, value);
	FirstAdjVex(G, v);
	NextAdjVex(G, v, w);
	InsertVex(&G, v);
	DeleteVex(&G, v);
	InsertArc(&G, v, w);
	DeleteArc(&G, v, w);
	DFSTraverse(G, Visit());
	BFSTraverse(G, Visit());
} ADT Graph
*/


#define INFINITY 10000000   // 最大值
#define MAX_VERTEX_NUM 20   // 最大顶点个数
typedef enum {
	DG, DN, UDG, UDN   // 有向图，有向网，无向图，无向网
} GraphKind;


// 图 的数组（邻接矩阵）存储表示
typedef int VRType;       // VRType是顶点关系类型。对无权图，用1或0表示相邻与否；对带权图，则为权值类型
typedef char* InfoType;   // 该弧相关信息的指针
typedef struct ArcCell {
	VRType adj;
	InfoType *info;
} ArcCell, AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

typedef int VertexType;
typedef struct {
	VertexType vexs[MAX_VERTEX_NUM];   // 顶点向量
	AdjMatrix arcs;                    // 邻接矩阵
	int vex_num, arc_num;              // 图的当前顶点数和弧数
	GraphKind kind;                    // 图的种类标志
} MGraph;


// 图的邻接表存储表示
typedef struct ArcNode {
	int adj_vex;         // 该弧所指向的顶点的位置
	ArcNode *next_arc;   // 指向下一条弧的指针
	InfoType *info;      // 该弧相关信息的指针
} ArcNode;

typedef struct VNode {
	VertexType data;      // 顶点信息
	ArcNode *first_arc;   // 指向第一条依附该顶点的弧的指针
} VNode, AdjList[MAX_VERTEX_NUM];

typedef struct ALGraph {
	AdjList vertices;
	int vex_num, arc_num;   // 图的当前顶点数和弧数
	int kind;               // 图的种类标志
} ALGraph;


// 有向图的十字链表存储表示
typedef struct ArcBox {
	int tail_vex, head_vex;   // 分别为弧的尾和头的顶点的位置
	ArcBox *hlink, *tlink;    // 分别为弧头相同和弧尾相同的弧的链域
	InfoType *info;           // 弧相关信息的指针
} ArcBox;

typedef struct VexNode {
	VertexType data;
	ArcBox *firstin, * firstout;    // 分别指向该顶点第一条入弧和出弧
} VexNode;

typedef struct OLGraph {
	VexNode xlist[MAX_VERTEX_NUM];   // 表头向量
	int vex_num, arc_num;            // 有向图的当前顶点数和弧数
} OLGraph;


// 无向图的邻接多重表存储表示
typedef enum VisitIF { unvisited, visited } VisitIF;

typedef struct EBox {
	VisitIF mark;          // 访问标记
	int ivex, jvex;        // 该边依附的两个顶点的位置
	EBox *ilink, *jlink;   // 分别指向依附这两个顶点的下一条边
	InfoType *info;        // 该边信息指针
} EBox;

typedef struct VexBox {
	VertexType data;
	EBox *first_edge;   // 指向第一条依附该顶点的边
} VexBox;

typedef struct {
	VexBox adjmulist[MAX_VERTEX_NUM];
	int vex_num, arc_num;   // 无向图的当前顶点数和边数
} AMLGraph;


// 算法7.1
Status CreateGraph(MGraph mg);

// 算法7.2
Status CreateUDN(MGraph mg);

// 算法7.3
Status CreateDG(OLGraph olg);

// 算法7.4
Status visited[];             // 访问标志数组
Status (*VisitFunc)(int v);   // 函数变量
void DFSTraverse(MGraph mg, Status (*Visit)(int v));

// 算法7.5
void DFS(MGraph mg, int v);

// 算法7.6
void BFSTraverse(MGraph mg, Status (*Visit)(int v));

// 算法7.7
void DFSForest(MGraph mg, CSTree cst);

// 算法7.8
void DFSTree(MGraph mg, int v, CSTree cst);

// 算法7.9
void MST_PRIM(MGraph, VertexType vt);

// 算法7.10
void FindArticul(ALGraph alg);

// 算法7.11
void DFSArticul(ALGraph alg, int v0);

// 算法7.12
Status ToplogicalSort(ALGraph alg);

// 算法7.13
Status TopologicalOrder(ALGraph alg, Stack stack);

// 算法7.14
Status CriticalPath(ALGraph alg);

// 算法7.15
void ShortestPath_Dijkstra(MGraph mg, PathMatrix pm, ShortPath spt);

// 算法7.16
void ShortestPath_Floyd(MGraph mg, PathMatrix pm, DistanceMatrix dm);
