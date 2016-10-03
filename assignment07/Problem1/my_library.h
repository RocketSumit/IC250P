#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>

struct AdjListNode* newAdjListNode(int dest, double weight);
struct Graph* createGraph(int V);
void addEdge(struct Graph *graph, int src, int dest, double weight);
void printGraph(struct Graph *graph);

#endif
