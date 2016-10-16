#include "my_library.h"

/* structure to represent graph which consist
   of array of adjacency lists */
struct Graph {
        int V;
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
        int weight;
        struct AdjListNode *next;
};

/* Function to create a node with given vertice */
struct AdjListNode* newAdjListNode(int dest, int weight)
{
        struct AdjListNode *new_node = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
        new_node->dest = dest;
        new_node->weight = weight;
        new_node->next = NULL;
        return new_node;
}

/* Function to create graph with V vertices with no neighbours */
struct Graph* createGraph(int V)
{
        struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

        graph->V = V;
        graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));

        for(int i = 0; i<V; i++) {
                graph->array[i].head = NULL;
        }

        return graph;
}

/* Function to add edge between two vertices */
void addEdge(struct Graph *graph, int src, int dest, int weight)
{
        /* Adds a edge from src to dest and prepends it to the existing list*/
        struct AdjListNode *new_node = newAdjListNode(dest, weight);
        new_node->next = graph->array[src].head;
        graph->array[src].head = new_node;

        /* adds a edge from dest to src since graph is undirected*/
        new_node = newAdjListNode(src, weight);
        new_node->next = graph->array[dest].head;
        graph->array[dest].head = new_node;
}

/* Function to print each vertices and their neighbours */
void printGraph(struct Graph *graph)
{
        int V = graph->V, vertice;
        struct AdjListNode *iterator = NULL;

        for(int i = 0; i<V; i++) {

                printf("\n%d", i+1 );
                iterator = graph->array[i].head;
                while(iterator!= NULL) {
                        vertice = iterator->dest;
                        printf("->%d", vertice);
                        iterator = iterator->next;
                }

                printf("->NULL");
        }
}

/* structure to represent node in priority queue
   using minheap tree stucture */
struct MinHeapNode
{
        int v;
        int dist;
};

/* structure to represent min heap */
struct MinHeap {
        int size; //number of heap nodes present currently
        int capacity; //denotes the capacity of entire heap
        int *pos; //help to find the index of v node in MinHeapNode array
        struct MinHeapNode **array; // array consist of list of minHeap nodes
};

/* function to create a new MinHeap Node */
struct MinHeapNode* newMinHeapNode(int v, int dist)
{
        struct MinHeapNode* minHeapNode =
                (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
        minHeapNode->v = v;
        minHeapNode->dist = dist;
        return minHeapNode;
}

/* Function to create a minimum heap */
struct MinHeap* createMinHeap(int capacity)
{
        struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
        minHeap->size = 0;
        minHeap->pos = (int *)malloc(capacity*sizeof(int));
        minHeap->capacity = capacity;
        minHeap->array = (struct MinHeapNode**)malloc(capacity*sizeof(struct MinHeapNode*));
        return minHeap;
}

/*A utility function to swap two nodes of min heap. Needed for min heapify */
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
        struct MinHeapNode* t = *a;
        *a = *b;
        *b = t;
}

/* Function to heapify at given index */
void minHeapify(struct MinHeap* minHeap, int idx)
{
        int smallest, left, right;
        smallest = idx;
        left = 2 * idx + 1;
        right = 2 * idx + 2;

        if (left < minHeap->size &&
            minHeap->array[left]->dist < minHeap->array[smallest]->dist )
                smallest = left;

        if (right < minHeap->size &&
            minHeap->array[right]->dist < minHeap->array[smallest]->dist )
                smallest = right;

        if (smallest != idx)
        {
                // The nodes to be swapped in min heap
                struct MinHeapNode *smallestNode = minHeap->array[smallest];
                struct MinHeapNode *idxNode = minHeap->array[idx];

                // Swap positions
                minHeap->pos[smallestNode->v] = idx;
                minHeap->pos[idxNode->v] = smallest;

                // Swap nodes
                swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);

                minHeapify(minHeap, smallest);
        }
}

/* Function to check if the given minHeap is ampty or not */
int isEmpty(struct MinHeap* minHeap)
{
        return minHeap->size == 0;
}

/* Standard function to extract minimum node from heap */
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
        if (isEmpty(minHeap))
                return NULL;

        // Store the root node
        struct MinHeapNode* root = minHeap->array[0];

        // Replace root node with last node
        struct MinHeapNode* lastNode = minHeap->array[minHeap->size - 1];
        minHeap->array[0] = lastNode;

        // Update position of last node
        minHeap->pos[root->v] = minHeap->size-1;
        minHeap->pos[lastNode->v] = 0;

        // Reduce heap size and heapify root
        --minHeap->size;
        minHeapify(minHeap, 0);

        return root;
}

/* Function to update the distance of node v and its position in heap */
void decreaseKey(struct MinHeap* minHeap, int v, int dist)
{
        // Get the index of v in  heap array
        int i = minHeap->pos[v];

        // Get the node and update its dist value
        minHeap->array[i]->dist = dist;

        // Travel up while the complete tree is not hepified.
        // This is a O(Logn) loop
        while (i && minHeap->array[i]->dist < minHeap->array[(i - 1) / 2]->dist)
        {
                // Swap this node with its parent
                minHeap->pos[minHeap->array[i]->v] = (i-1)/2;
                minHeap->pos[minHeap->array[(i-1)/2]->v] = i;
                swapMinHeapNode(&minHeap->array[i],  &minHeap->array[(i - 1) / 2]);

                // move to parent index
                i = (i - 1) / 2;
        }
}

/* Function to check the presence of node v in heap */
int isInMinHeap(struct MinHeap *minHeap, int v)
{
        if (minHeap->pos[v] < minHeap->size)
                return 1;
        return 0;
}

/* Function used to print the solution */
void printArr(int dist[], int n)
{
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < n; ++i)
                printf("%d \t\t %d\n", i, dist[i]);
}

/* Main Algorithm to find the shortest distance of source from all destinations */
void dijkstra(struct Graph* graph, int src, int dist[])
{
        int V = graph->V;// Get the number of vertices in graph

        // minHeap represents set E
        struct MinHeap* minHeap = createMinHeap(V);

        // Initialize min heap with all vertices. dist value of all vertices
        for (int v = 0; v < V; ++v)
        {
                dist[v] = INT_MAX;
                minHeap->array[v] = newMinHeapNode(v, dist[v]);
                minHeap->pos[v] = v;
        }

        // Make dist value of src vertex as 0 so that it is extracted first
        minHeap->array[src] = newMinHeapNode(src, dist[src]);
        minHeap->pos[src]   = src;
        dist[src] = 0;
        decreaseKey(minHeap, src, dist[src]);

        // Initially size of min heap is equal to V
        minHeap->size = V;

        // In the followin loop, min heap contains all nodes
        // whose shortest distance is not yet finalized.
        while (!isEmpty(minHeap))
        {
                // Extract the vertex with minimum distance value
                struct MinHeapNode* minHeapNode = extractMin(minHeap);
                int u = minHeapNode->v; // Store the extracted vertex number

                // Traverse through all adjacent vertices of u (the extracted
                // vertex) and update their distance values
                struct AdjListNode* iterator = graph->array[u].head;
                while (iterator != NULL)
                {
                        int v = iterator->dest;

                        // If shortest distance to v is not finalized yet, and distance to v
                        // through u is less than its previously calculated distance
                        if (isInMinHeap(minHeap, v) && dist[u] != INT_MAX &&
                            iterator->weight + dist[u] < dist[v])
                        {
                                dist[v] = dist[u] + iterator->weight;

                                // update distance value in min heap also
                                decreaseKey(minHeap, v, dist[v]);
                        }
                        iterator = iterator->next;
                }
        }
}
