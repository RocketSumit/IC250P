#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

struct Graph* createGraph(int V, int E);
void addEdge(struct Graph *graph, int src, int dest, double weight, int edgeCount);
void BellmanFord(struct Graph *graph, int starting_point, double dist[]);
void findMinWeightPlanet(double dist[], int V, double initial_weight);

#endif
