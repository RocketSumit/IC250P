#ifndef MY_HEADER_H_
#define MY_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>
#include <stdbool.h>

/* structure to represent graph which consist
   of array of adjacency lists */
struct Graph {
        int V;
        int E;
        int attribute;
        struct AdjList *array;
};

/* structure to represent adjacency list */
struct AdjList {
        struct AdjListNode *head;
};

/* structure to represent adjacency node
   which consist of destination and its weight from source */
struct AdjListNode {
        int dest;
        double weight;
        struct AdjListNode *next;
};

typedef struct queue {
        int front, rear, capacity;
        int *array;
}Queue;

struct Edge
{
        int src, dest, weight;
};

// A structure to represent a subset for union-find
struct subset
{
        int parent;
        int rank;
};

struct Graph* createGraph(int V, int attribute);

void addEdge(struct Graph *graph, int src, int dest, double weight);

void deleteEdge(struct Graph *graph, int src, int dest);

double* dijkstra(struct Graph* graph, int src);

double* BellmanFord(struct Graph *graph, int starting_point);

int degree(struct Graph *graph, int v);

int* neigh(struct Graph *graph, int v);

void dfs(struct Graph *graph, int v, int visited[]);

void bfs(struct Graph *graph, int v);

void primMST(struct Graph *graph);

void KruskalMST(struct Graph* graph);


#endif
