/*
 * ch_09_graph_theory_algorithm/dijkstra.h
 *
 * 2019/3/19
 */

#ifndef CH_09_GRAPH_THEORY_ALGORITHM_DIJKSTRA_H_
#define CH_09_GRAPH_THEORY_ALGORITHM_DIJKSTRA_H_


typedef int Vertex;

struct TableEntry {
	List Header;
	int Known;
	DistType Dist;
	Vertex Path;
};

#define NotAVertex (-1)
typedef struct TableEntry Table[NumVertex];


#endif /* CH_09_GRAPH_THEORY_ALGORITHM_DIJKSTRA_H_ */
