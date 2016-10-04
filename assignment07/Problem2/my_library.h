#ifndef MY_LIBRARY_H_
#define MY_LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <float.h>

struct Graph* createGraph(int V, int E);
void BellmanFord(struct Graph *graph, int starting_point, double dist[]);

#endif
