/*
 * ch_09_graph_theory_algorithm/example.c
 *
 * 2019/3/18
 */


void TopSort(Graph G)
{
	int Counter;
	Vertex V, W;

	for (Counter = 0; Counter < NumVertex; Counter++) {
		V = FindNewVertexOfIndegreeZero();
		if (V == NotAVertex) {
			Error("Graph has a cycle");
			break;
		}
		TopNum[V] = Counter;
		for each W adjacent to V
			Indegree[W]--;
	}
}


void TopSort2(Graph G)
{
	Queue Q;
	int Counter = 0;
	Vertex V, W;

	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);
	for each vertex V
		if (Indegree[V] == 0) {
			Enqueue(V, Q);
		}

	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		TopNum[V] = ++Counter;

		for each W adjacent to V
			if(--Indegree[W] == 0) {
				Enqueue(W, Q);
			}
	}

	DisposeQueue(Q);
}
