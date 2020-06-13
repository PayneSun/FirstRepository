/*
 * ch_09_graph_theory_algorithm/shortest_path.c
 *
 * 2019/3/18
 */


void Unweighted(Table T)
{
	int CurrDist;
	Vertex V, W;

	for (CurrDist = 0; CurrDist < NumVertex; CurrDist++) {
		for each vertex V
			if (!T[V].Known && T[V].Dist == CurrDist) {
				T[V].Known = True;
				for each W adjacent to V
					if (T[W].Dist == Infinity) {
						T[W].Dist = CurrDist + 1;
						T[W].Path = V;
					}
			}
	}
}


void Unweighted2(Table T)
{
	Queue Q;
	Vertex V, W;
	Q = CreateQueue(NumVertex);
	MakeEmpty(Q);
	while (!IsEmpty(Q)) {
		V = Dequeue(Q);
		T[V].Known = True;
		for each W adjacent to V
			if (T[W].Dist == Infinity) {
				T[W].Dist = T[V].Dist + 1;
				T[W].Path = V;
				Enqueue(W, Q);
			}
	}
	DisposeQueue(Q);
}
