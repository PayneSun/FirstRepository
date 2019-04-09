/*
 * ch_09_graph_theory_algorithm/dijkstra.c
 *
 * 2019/3/19
 */


#include "dijkstra.h"


void InitTable(Vertex Start, Graph G, Table T)
{
	int i;

	ReadGraph(G, T);
	for (i = 0; i < NumVertex; i++) {
		T[i].Known = False;
		T[i].Dist = Infinity;
		T[i].Path = NotAVertex;
	}
	T[Start].Dist = 0;
}


void PrintPath(Vertex V, Table T)
{
	if (T[V].Path != NotAVertex) {
		PrintPath(T[V].Path, T);
		printf(" to");
	}
	printf("%v", V);
}


void Dijkstra(Table T)
{
	Vertex V, W;

	for (;;) {
		V = /* smallest unknown distance vertex */;
		if (V == NotAVertex) {
			break;
		}

		T[V].Known = True;
		for each W adjacent to V
			if (!T[W].Known) {
				if (T[V].Dist + Cvw < T[W].Dist) {
					Decrease(T[W].Dist to T[V].Dist + Cvw);
					T[W].Path = V;
				}
			}
	}
}


void WeightedNegative(Table T)
{
	Queue Q;
	Vertex V, W;

	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);
	Enqueue(S, Q);

	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		for each W adjacent to V
			if (T[V].Dist + Cvw < T[W].Dist) {
				T[W].Dist = T[V].Dist + Cvw;
				T[W].Path = V;
				if (W is not already in Q) {
					Enqueue(W, Q);
				}
			}
	}
	DisposeQueue(Q);
}
