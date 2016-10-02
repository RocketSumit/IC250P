#include "my_library.h"

struct Graph {
        int V;
        struct AdjList *array;
};

struct AdjList {
        struct AdjListNode *head;
};

struct AdjListNode {
        int dest;
        struct AdjListNode *next;
};

/* Function to create a node with given vertice */
struct AdjListNode* newAdjListNode(int dest)
{
        struct AdjListNode *new_node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
        new_node->dest = dest;
        new_node->next = NULL;
        return new_node;
}

/* Function to create graph with V vertices with no neighbours */
struct Graph* createGraph(int V)
{
        struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

        graph->V = V;
        graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));

        int i = 0;

        for(i = 0; i<V; i++) {
                graph->array[i].head = NULL;
        }

        return graph;
}

/* Function to add edge between two vertices */
void addEdge(struct Graph *graph, int src, int dest)
{
        /* Adds a edge from src to dest and prepends it to the existing list*/
        struct AdjListNode *new_node = newAdjListNode(dest);
        new_node->next = graph->array[src].head;
        graph->array[src].head = new_node;

        /* adds a edge from dest to src */
        new_node = newAdjListNode(src);
        new_node->next = graph->array[dest].head;
        graph->array[dest].head = new_node;
}

/* Function to print each vertices and their neighbours */
void printGraph(struct Graph *graph){

        int V = graph->V, vertice;
        struct AdjListNode *iterator = NULL;

        for(int i = 0; i<V; i++) {

                printf("\n%d", i+1 );
                iterator = graph->array[i].head;
                while(iterator!= NULL) {
                        vertice = iterator->dest;
                        printf("->%d\n", vertice);
                        iterator = iterator->next;
                }

                printf("->NULL");
        }
}
