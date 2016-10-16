#ifndef MY_HEADER_H_
#define MY_HEADER_H_

#include <stdio.h>
#include <stdlib.h>

/* structure to represent graph which consist
   of array of adjacency lists */
struct Graph {
        int V;
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

struct Graph* createGraph(int V, int attribute);

void addEdge(struct Graph *graph, int src, int dest, double weight);

void deleteEdge(struct Graph *graph, int src, int dest);

#endif
