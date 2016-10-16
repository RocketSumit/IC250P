#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/* structure to represent graph which consist
   of array of adjacency lists */
struct Graph {
        int V, E;
        int attribute;
        struct AdjList *array;
        struct edges *arrayEdges;
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

struct Graph* createGraph(int V, int attribute);

void addEdge(struct Graph *graph, int src, int dest, double weight);

void deleteEdge(struct Graph *graph, int src, int dest);

double* dijkstra(struct Graph* graph, int src);

double* BellmanFord(struct Graph *graph, int starting_point);

void findMinWeightPlanet(double dist[], int V, double initial_weight);

#endif
