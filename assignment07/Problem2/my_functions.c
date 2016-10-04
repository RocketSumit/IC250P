#include "my_library.h"

/* structure to represent graph */
struct Graph
{
        int V, E; // V represent total vertices and E total edges
        struct edges *array;
};

/* structure to represent edges */
struct edges
{
        int src, dest;
        double weight;
};

/* Function to create graph */
struct Graph* createGraph(int V, int E)
{
        struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));
        graph->V = V;
        graph->E = E;
        graph->array = (struct edges*)malloc(E*sizeof(struct edges));

        return graph;
}

/* Function to find all shortest distances form source to destination
   using Bellman Ford Algorithm */
void BellmanFord(struct Graph *graph, int starting_point, double dist[])
{
        int V = graph->V;
        int E = graph->E;

        /* Initialize the all distances from source to destination */
        for (int i = 0; i < V; i++) {
                if(i == starting_point)
                        dist[i] = 0;
                dist[i] = DBL_MAX;
        }

        /* Relax all edges |V|- 1 times so that
           shortest path of all destination from source have atmost |v| - 1 edges */
        int u, v;
        double weight;

        for(int i = 0; i<V - 1; i++) {

                for(int j = 0; j<E; j++) {
                        u = graph->array[j].src;
                        v = graph->array[j].dest;
                        weight = graph->array[j].weight;

                        if(dist[u] != DBL_MAX && dist[v]> dist[u] + weight)
                                dist[v] = dist[u] + weight;
                }
        }

        /* check for negative weight cycles if any */
        for(int j = 0; j<E; j++) {
                u = graph->array[j].src;
                v = graph->array[j].dest;
                weight = graph->array[j].weight;

                if(dist[u] != DBL_MAX && dist[v]> dist[u] + weight) {
                        printf("Negative Cycles Exist, hence problem cannot be solved.\n");
                        exit(0);
                }
        }
}
