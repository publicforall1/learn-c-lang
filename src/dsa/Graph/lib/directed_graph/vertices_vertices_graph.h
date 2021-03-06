#ifndef GRAPH_H
#define GRAPH_H

#define MAX_NUMBER_OF_VERTICES 100
#define VISITED 1
#define UNVISITED 0
#define INFINITY 999

#include "../list/list.h"
#include "../queue/circular_queue.h"
#include "../stack/stack.h"

typedef struct Graph {
    int matrix[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_VERTICES];
    int vertices;
    int visited[MAX_NUMBER_OF_VERTICES];
    int lowlink[MAX_NUMBER_OF_VERTICES]; // low-link value (contact taiprogramer
                                         // if you don't understand)
    int time[MAX_NUMBER_OF_VERTICES]; // 1, 2, 3, 4, 5, ... order of vertex when
                                      // dfs
    int distance[MAX_NUMBER_OF_VERTICES]; // for Dijkstra shortest-path
                                          // algorithm
    int weight[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_VERTICES];
} Graph;

// Classic
void init_graph(Graph* G, int vertices, int edges);          // O(vertices ^2)
void add_edge(Graph* G, int edge, int vertex1, int vertex2); // O(1)
int is_adjacent(Graph G, int vertex1, int vertex2);          // O(1)
int in_degree(Graph g, int vertex);                          // O(n)
int out_degree(Graph g, int vertex);                         // O(n)
int degree(Graph G, int vertex);                             // O(n)

// Medium
List get_adjacents(Graph G, int vertex); // O(n)
// Medium :: Graph traversal
void reset_visited(Graph* g); // O(n)
void dfs(Graph* g, int vertex, List* traversal);
void dfs_using_stack(Graph* g, int start_vertex, List* traversal);
void bfs_using_queue(Graph* g, int start_vertex, List* traversal);
int have_cycle(Graph g); // O(Complexity(dfs))
int Tarjan_find_sccs(Graph g);
void add_weight(Graph* g, int x, int y, int weight);
void Dijkstra_find_and_set_distance(Graph* g, int source_vertex);
int have_negative_cycle(Graph g);

#endif
