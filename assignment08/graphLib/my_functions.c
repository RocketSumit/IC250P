#include "my_header.h"

/* Function to create graph with V vertices with no neighbours */
struct Graph* createGraph(int V, int attribute)
{
        struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

        graph->V = V;
        graph->attribute = attribute;
        graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));

        for(int i = 0; i<V; i++) {
                graph->array[i].head = NULL;
        }

        return graph;
}

/* Function to create a node with given vertice */
struct AdjListNode* newAdjListNode(int dest, int weight)
{
        struct AdjListNode *new_node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
        new_node->dest = dest;
        new_node->weight = weight;
        new_node->next = NULL;
        return new_node;
}

/* Function to add edge between two vertices */
void addEdge(struct Graph *graph, int src, int dest, double weight)
{

        /* Adds a edge from src to dest and prepends it to the existing list*/
        struct AdjListNode *new_node = newAdjListNode(dest, weight);
        new_node->next = graph->array[src].head;
        graph->array[src].head = new_node;

        if(graph->attribute == 0) {
                /* adds a edge from dest to src since graph is undirected*/
                new_node = newAdjListNode(src, weight);
                new_node->next = graph->array[dest].head;
                graph->array[dest].head = new_node;
        }
}

/* Funtion to delete an adge between two vertices */
void deleteEdge(struct Graph *graph, int src, int dest)
{
        struct AdjListNode *iterator = graph->array[src].head;
        struct AdjListNode *target = NULL;
        /* find the node to be deleted by traversing the list */
        while(iterator->next->dest != dest) {
                iterator = iterator->next;
        }

        target = iterator->next;
        iterator->next = iterator->next->next;
        free(target);
}
