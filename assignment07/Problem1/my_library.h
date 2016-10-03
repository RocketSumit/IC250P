#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct AdjListNode* newAdjListNode(int dest, double weight);
struct Graph* createGraph(int V);
void addEdge(struct Graph *graph, int src, int dest, double weight);
void printGraph(struct Graph *graph);
struct MinHeapNode* newMinHeapNode(int v, int dist);
struct MinHeap* createMinHeap(int capacity);
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
void minHeapify(struct MinHeap* minHeap, int idx);
int isEmpty(struct MinHeap* minHeap);
struct MinHeapNode* extractMin(struct MinHeap* minHeap);
void decreaseKey(struct MinHeap* minHeap, int v, int dist);
int isInMinHeap(struct MinHeap *minHeap, int v);
void printArr(double dist[], int n);
void dijkstra(struct Graph* graph, int src, double dist[]);

#endif
