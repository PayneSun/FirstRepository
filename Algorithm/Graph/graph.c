// 数据结构（C语言描述）.严蔚敏
// 第7章.图
// graph.h
// 2016.09.26


#include "../Graph/graph.h"


// 算法7.1
Status CreateGraph(MGraph mg) {
	// 采用数组（邻接矩阵）表示法，构造图mg
	scanf(&mg.kind);
	switch(mg.kind) {
		case DG: return CreateDG(mg);
		case DN: return CreateDN(mg);
		case UDG: return CreateUDG(mg);
		case UDN: return CreateUDN(mg);
	}
}


// 算法7.2
Status CreateUDN(MGraph mg) {
	// 采用数组（邻接矩阵）表示法，构造无向网mg
	char *IncInfo;
	scanf(&mg.vex_num, &mg.arc_num, &IncInfo);   // IncInfo为0则各弧不含其他信息
	// 构造顶点向量
	for (int i = 0; i < mg.vex_num; ++i) { scanf(&mg.vex_num); }
	// 初始化邻接矩阵
	for (int i = 0; i < mg.vex_num; ++i) {
		for (int j = 0; j < mg.vex_num; ++j) {
			mg.arcs[i][j].adj = INFINITY;
			mg.arcs[i][j].info = NULL;
		}
	}
	// 构造邻接矩阵
	for (int k = 0; k < mg.arc_num; ++k) {
		VRType v1, v2;   // 顶点
		int w;           // 权值
		scanf(&v1, &v2, &w);
		// 确定v1和v2在图mg中的位置
		int i = LocateVex(mg, v1);
		int j = LocateVex(mg, v2);
		mg.arcs[i][j].adj = w;
		// 若弧含有相关信息，则输入
		if (IncInfo) {
			Input(*mg.arcs[i][j].info);
			mg.arcs[j][i] = mg.arcs[i][j];
		}
	}
	return TRUE;
}


// 算法7.3
Status CreateDG(OLGraph olg) {
	// 采用十字链表存储表示，构造有向图olg
	char *IncInfo;   // IncInfo为0则各弧不含其他信息
	scanf(&olg.vex_num, &olg.arc_num, &IncInfo);
	for (int i = 0; i < olg.vex_num; ++i) {   // 构造表头向量
		scanf(&olg.xlist[i].data);
		olg.xlist[i].firstin = NULL;
		olg.xlist[i].firstout = NULL;
	}
	for (int k = 0; k < olg.arc_num; ++k) {   // 输入各弧并构造十字链表
		ArcBox v1, v2;
		scanf(&v1, &v2);
		int i = LocateVex(olg, v1);
		int j = LocateVex(olg, v2);
		ArcBox *p = (ArcBox *)malloc(sizeof(ArcBox));
		*p->tail_vex = i;
		*p->head_vex = j;
		*p->hlink = olg.xlist[j].firstin;
		*p->tlink = olg.xlist[i].firstout;
		*p->info = NULL;
		olg.xlist[j].firstin = olg.xlist[i].firstout = p;
		if (IncInfo) { Input(*p->info); }
	}
}


// 算法7.4
void DFSTraverse(MGraph mg, Status (*Visit)(int v)) {
	// 对图mg作深度优先遍历
	VisitFunc = Visit;   // 使用全局变量VisitFunc，使DFS不必设函数指针参数
	for (int v = 0; v < mg.vex_num; ++v) {
		visited[v] = FALSE;
	}
	for (int v = 0; v < mg.vex_num; ++v) {
		if (!visited[v]) {
			DFS(mg, v);
		}
	}
}


// 算法7.5
void DFS(MGraph mg, int v) {
	// 从第v个顶点出发递归地深度优先遍历图mg
	visited[v] = TRUE;
	VisitFunc(v);
	for (int w = FirstAdjVex(mg, v); w >= 0;
			 w = NextAdjVex(mg, v, w)) {
		if (!visited[w]) {   // 对v的尚未访问的邻接顶点w递归调用DFS
			DFS(mg, w);
		}
	}
}


// 算法7.6
void BFSTraverse(MGraph mg, Status (*Visit)(int v)) {
	// 按广度优先非递归遍历图mg，使用辅助队列q和访问标志数组visited。
	for (int v = 0; v < mg.vex_num; ++v) {
		visited[v] = FALSE;
	}
	InitQueue(queue);
	for (int v = 0; v < mg.vex_num; ++v) {
		if (!visited[v]) {
			visited[v] = TRUE;
			Visit(v);
			EnQueue(queue, v);
			while (!QueueEmpty(queue)) {
				DeQueue(queue, u);   // 队列头元素出队并置为u
				for (int w = FirstAdjVex(mg, u); w >= 0;
						 w = NextAdjVex(mg, u, w)) {
					if (!visited[w]) {   // w为u的尚未访问的邻接顶点
						visited[w] = TRUE;
						Visit(w);
						EnQueue(queue, w);
					}   // if
				}   // for
			}   // while
		}   // if
	}   // for
}


// 算法7.7
void DFSForest(MGraph mg, CSTree t) {
	// 建立无向图mg的深度优先生成森林的（最左）孩子（右）兄弟链表t
	t = NULL;
	for (int v = 0; v < mg.vex_num; ++v) {
		visited[v] = FALSE;
	}
	for (int v = 0; v < mg.vex_num; ++v) {
		if (!visited[v]) {   // 第v顶点为新的生成树的根结点
			CSTree *qcst;
			CSTree *pcst = (CSTree)malloc(sizeof(CSNode));
			*pcst->data = GetVex(mg, v);
			*pcst->first_child = NULL;
			*pcst->next_sibling = NULL;
			if (!t) {
				t = pcst;
			} else {
				qcst->next_sibling = pcst;
			}
			qcst = pcst;
			DFSTree(mg, v, pcst);
		}   // if
	}   // for
}


// 算法7.8
void DFSTree(MGraph mg, int v, CSTree cst) {
	// 从第v个顶点出发深度优先遍历图mg，建立以cst为根的生成树
	visited[v] = TRUE;
	Status first = TRUE;
	for ( int w = FirstAdjVex(mg, v); w >= 0; w = NextAdjVex(mg, v, w)) {
		if (!visited[w]) {
			CSTree *qcst;
			CSTree *pcst = (CSTree)malloc(sizeof(CSNode));
			*pcst->data = GetVex(mg, v);
			*pcst->first_child = NULL;
			*pcst->next_sibling = NULL;
			if (first) {
				cst->first_child = pcst;
				cst->next_sibling = FALSE;
			} else {
				qcst->next_sibling = pcst;
			}
			qcst = pcst;
			DFSTree(mg, w, qcst);
		}   // if
	}   // for
}


// 算法7.9
void MST_PRIM(MGraph mg, VertexType u) {
	// 用普里姆算法从第u个顶点出发构造网mg的最小生成树mst，输出mst的各条边
	// 记录从顶点集U到V-U的代价最小的边的辅助数组定义
	struct {
		VertexType adjvex;
		VRType lowcost;
	} closedge[MAX_VERTEX_NUM];
	int k = LocateVex(mg, u);
	for (int j = 0; j < mg.vex_num; ++j) {
		if (j != k) {
			closedge[j].adjvex = u;
			closedge[j].lowcost = mg.arcs[k][j].adj;
		}
	}
	closedge[k].lowcost = 0;
	// 选择其余mg.vex_num个顶点
	for (int i = 1; i < mg.vex_num; ++i) {
		k = minimum(closedge);   // 求出mst的下一个结点：第k顶点
		printf(closedge[k].adjvex, mg.vexs[k]);   //输出生成树的边
		closedge[k].lowcost = 0;   // 第k顶点并入U集
		// 新顶点并入U后重新选择最小边
		for (int j = 0; j < mg.vex_num; ++j) {
			if (mg.arcs[k][j].adj < closedge[j].lowcost) {
				closedge[j].adjvex = mg.vexs[k];
				closedge[j].lowcost = mg.arcs[k][j].adj;
			}   // if
		}   // for
	}   // for
}


// 算法7.10
void FindArticul(ALGraph alg) {
	// 连通图alg以邻接表作存储结构，查找并输出alg上全部关节点
	// 全局量count对访问计数
	int count = 1;
	visited[0] = 1;   // 设定邻接表上0号顶点为生成树的根
	for (int i = 1; i < alg.vex_num; ++i) {
		visited[i] = 0;
	}
	ArcNode *p = alg.vertices[0].first_arc;
	int v = p->adj_vex;
	DFSArticul(alg, v);   // 从第v顶点出发深度优先查找关节点
	if (count < alg.vex_num) {
		printf(0, alg.vertices[0].data);
		while (p->next_arc) {
			p = p->next_arc;
			v = p->adj_vex;
			if (visited[v] == 0) {
				DFSArticul(alg, v);
			}   // if
		}   // while
	}   // if
}


// 算法7.11
void DFSArticul(ALGraph alg, int v0) {
	// 从第v0个顶点出发深度优先遍历图alg，查找并输出关节点
	visited[v0] = min = ++count;
	ArcNode *p = alg.vertices[v0].first_arc;
	for (; p; p = p->next_arc) {
		int w = p->adj_vex;
		if (visited[w] == 0) {
			DFSArticul(alg, w);
			if (low[w] < min) { min = low[w]; }
			if (low[w] >= visited[v0]) { printf(v0, alg.vertices[v0].data); }
		} else if (visited[w] < min) {
			min = visited[w];
		}
	}
	low[v0] = min;
}


// 算法7.12
Status ToplogicalSort(ALGraph alg) {
	// 有向图alg采用邻接表存储结构
	// 若alg无回路，则输出alg的顶点的一个拓扑序列并返回OK，否则返回ERROR
	Stack stack;
	int indegree[alg.vex_num];
	FindInDegree(alg, indegree);   // 对各顶点求入度indgree[0..alg.vex_num-1]
	InitStack(stack);
	for (int i = 0; i < alg.vex_num; ++i) {
		if (!indegree[i]) {
			push(stack, i);
		}
	}
	int i = 0;
	int count = 0;
	while (!StackEmpty(stack)) {
		pop(stack, i);
		printf(i, alg.vertices[i].data);
		count++;
		for (ArcNode* p = alg.vertices[i].first_arc; p; p = p->next_arc) {
			int k = p->adj_vex;   // 对顶点i的每个邻接点的入度减1
			if (!(--indegree[k])) {
				push(stack, k);
			} // if
		} // for
	} // while
	if (count < alg.vex_num) {
		return ERROR;
	} else {
		return OK;
	}
}


// 算法7.13
Status TopologicalOrder(ALGraph alg, Stack t) {
	// 有向网alg采用邻接表存储结构，求各顶点事件的最早发生时间ve
	// t为拓扑序列顶点栈， s为零入度顶点栈
	// 若alg无回路，则栈t返回alg的一个拓扑序列，且函数值为OK，否则为ERROR
	int ve[alg.vex_num];
	int indegree[alg.vex_num];
	Stack s, t;
	FindInDegree(alg, indegree);
	InitStack(t);
	int count = 0;
	for (int i = 0; i < alg.vex_num; ++i) {
		ve[i] = 0;
	}
	while (!StackEmpty(s)) {
		int j;
		pop(s, j);
		push(t, j);
		++count;
		for (ArcNode* p = alg.vertices[j].first_arc; p; p = p->next_arc) {
			int k = p->adj_vex;
			if (--indegree[k] == 0) {
				push(s, k);
			} // if
			if (ve[j] + *(p->info) > ve[k]) {
				ve[k] = ve[j] + *(p->info);
			} // if
		} // for
	} // while
	if (count < alg.vex_num) {
		return ERROR;
	} else {
		return OK;
	}
}


// 算法7.14
Status CriticalPath(ALGraph alg) {
	// alg为有向网，输出alg的各项关键活动
	if (!TopologicalOrder(alg, t)) return ERROR;
	int vl[alg.vex_num];
	for (int i = 0; i < alg.vex_num; ++i) {
		vl[i] = ve[i];
	}
	while (!StackEmpty(t)) {
		pop(t, j);
		ArcNode* p = alg.vertices[j].first_arc;
		for (; p; p = p->next_arc) {
			int k = p->adj_vex;
			int dut = *(p->info);
			if (vl[k] - dut < vl[j]) {
				vl[j] = vl[k] - dut;
			} // if
		} // for
	} // while
	for(int j = 0; j < alg.vex_num; ++j) {
		ArcNode* p = alg.vertices[j].first_arc;
		for (; p; p->next_arc) {
			int k = p->adj_vex;
			int dut = *(p->info);
			int ee = ve[j];
			int el = vl[k] - dut;
			char tag = (ee == el) ? '*' : '';
			printf(j, k, dut, ee, el, tag);   // 输出关键路径
		} // for
	} // for
}


// 算法7.15
void ShortestPath_Dijkstra(MGraph mg, PathMatrix pm, ShortPathTable spt) {
	// 用Dijkstra算法求有向网mg的v0顶点到其余顶点v的最短路径pm[v]及其带权长度spt[v]
	// 若pm[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点。
	// final[v]为TRUE当且仅当v属于S，即已经求得从v0到v的最短路径。
	for (int v = 0; v < mg.vex_num; ++v) {
		final[v] = FALSE;
		spt[v] = mg.arcs[v0][v];
		for (int w = 0; w < mg.vex_num; ++w) {
			pm[v][w] = FALSE;
		}
		if (spt[v] < INFINITY) {
			pm[v][v0] = TRUE;
			pm[v][v] = TRUE;
		}
	}
	// 初始化，v0顶点属于S集合
	spt[v0] = 0;
	final[v0] = TRUE;
	// 开始主循环，每次求得v0到某个v顶点的最短路径，并加v到S集
	for (int i = 1; i < mg.vex_num; ++i) {
		int min = INFINITY;
		for (int w = 0; w < mg.vex_num; ++i) {
			if (!final[w]) {          // w顶点在V-S中
				if (spt[w] < min) {   // w顶点离v0顶点更近
					int v = w;
					min = spt[w];
				} // if
			} // if
		} // for
		final[v] = TRUE;   // 离顶点最近的v加入S集
		for (int w = 0; w < mg.vex_num; ++w) {   // 更新当前最短路径及距离
			if (!final[w] && (min + mg.arcs[v][w] < spt[w])) {   // 修改spt[w]和pm[w]
				spt[w] = min + mg.arcs[v][w];
				pm[w] = pm[v];
				pm[w][w] = TRUE;
			} // if
		} // for
	} // for
}


// 算法7.16
void ShortestPath_Floyd(MGraph mg, PathMatrix pm, DistanceMatrix dm) {
	// 用Floyd算法求有向网mg中各对顶点v和w之间的最短的路径pm[v][w]及其带权长度dm[v][w]，
	// 若pm[v][w][u]为TRUE，则从u是从v到w当前求得最短路径上的顶点。
	for (int v = 0; v < mg.vex_num; ++v) {   // 各对结点之间初试已知路径及距离
		for (int w = 0; w < mg.vex_num; ++w) {
			dm[v][w] = mg.arcs[v][w];
			for (int u = 0; u < mg.vex_num; ++u) {
				pm[v][w][u] = FALSE;
			}
			if (dm[v][w] < INFINITY) {
				pm[v][w][v] = TRUE;
				pm[v][w][w] = TRUE;
			} // if
		} // for
	} // for
	for (int u = 0; u < mg.vex_num; ++u) {
		for (int v = 0; u < mg.vex_num; ++v) {
			for (int w = 0; u < mg.vex_num; ++w) {
				if (dm[v][u] + dm[u][w] < dm[v][w]) {
					dm[v][w] = dm[v][u] + dm[u][w];
					for (int i = 0; i < mg.vex_num; ++i) {
						pm[v][w][i] = pm[v][u][i] || pm[u][w][i];
					} // for
				} // if
			} // for
		} // for
	} // for
}
