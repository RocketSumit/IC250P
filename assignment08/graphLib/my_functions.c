#include "my_header.h"

/* Function to create graph with V vertices with no neighbours */
struct Graph* createGraph(int V, int attribute)
{
        struct Graph *graph = (struct Graph*)malloc(sizeof(struct Graph));

        graph->V = V;
        graph->E = 0;
        graph->attribute = attribute;
        graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));

        for(int i = 0; i<V; i++) {
                graph->array[i].head = NULL;
        }

        return graph;
}

/* Function to create a node with given vertice */
struct AdjListNode* newAdjListNode(int dest, double weight)
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
        (graph->E)++;

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

/* function to find weight of given edge */
double weight(struct Graph *graph, int src, int dest)
{
        struct AdjListNode *iterator = NULL;
        iterator = graph->array[src].head;
        double edge_weight;

        while(iterator->dest != dest) {
                iterator = iterator->next;
        }

        edge_weight = iterator->weight;

        return edge_weight;
}

/* structure to represent node in priority queue
   using minheap tree stucture */
struct MinHeapNode
{
        int v;
        double dist;
};

/* structure to represent min heap */
struct MinHeap {
        int size; //number of heap nodes present currently
        int capacity; //denotes the capacity of entire heap
        int *pos; //help to find the index of v node in MinHeapNode array
        struct MinHeapNode **array; // array consist of list of minHeap nodes
};

/* function to create a new MinHeap Node */
struct MinHeapNode* newMinHeapNode(int v, double dist)
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
void decreaseKey(struct MinHeap* minHeap, int v, double dist)
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
void printArr(double *dist, int n)
{
        printf("Vertex   Distance from Source\n");
        for (int i = 0; i < n; ++i)
                printf("%d \t\t %lf\n", i, dist[i]);
}

/* Dijkstra Algorithm to find the shortest distance of source from all destinations */
double* dijkstra(struct Graph* graph, int src)
{
        int V = graph->V;// Get the number of vertices in graph
        double *dist = (double *)malloc(V*sizeof(double));

        // minHeap represents set E
        struct MinHeap* minHeap = createMinHeap(V);

        // Initialize min heap with all vertices. dist value of all vertices
        for (int v = 0; v < V; ++v)
        {
                dist[v] = DBL_MAX;
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
                        if (isInMinHeap(minHeap, v) && dist[u] != DBL_MAX &&
                            iterator->weight + dist[u] < dist[v])
                        {
                                dist[v] = dist[u] + iterator->weight;

                                // update distance value in min heap also
                                decreaseKey(minHeap, v, dist[v]);
                        }
                        iterator = iterator->next;
                }
        }

        return dist;
}

/* BellmanFord algorithm to solve the single source shortest path problem */
double* BellmanFord(struct Graph *graph, int starting_point)
{
        int V = graph->V;

        double *dist = (double *)malloc(V*sizeof(double));

        /* Initialize the all distances from source to destination */
        for (int i = 0; i < V; i++) {
                if(i == starting_point)
                        dist[i] = 0;
                else
                        dist[i] = DBL_MAX;
        }

        /* Relax all edges |V|- 1 times so that
           shortest path of all destination from source have atmost |v| - 1 edges */
        int u, v;
        double weight;

        struct AdjListNode *iterator = NULL;

        for(int i = 0; i<V - 1; i++) {

                for(int j = 0; j<V; j++) {
                        iterator = graph->array[j].head;

                        while(iterator!= NULL) {
                                u = j;
                                v = iterator->dest;
                                weight = iterator->weight;
                                iterator = iterator->next;

                                if(dist[u] != DBL_MAX && dist[v]> dist[u] + weight)
                                        dist[v] = dist[u] + weight;
                        }
                }
        }

        /* check for negative weight cycles if any */
        for(int j = 0; j<V; j++) {
                iterator = graph->array[j].head;

                while(iterator!=NULL) {
                        u = j;
                        v = iterator->dest;
                        weight = iterator->weight;
                        iterator = iterator->next;

                        if(dist[u] != DBL_MAX && dist[v]> dist[u] + weight) {
                                printf("Negative Cycles Exist, hence problem cannot be solved.\n");
                                exit(0);
                        }
                }
        }

        return dist;
}

/* Find the path where the weight of person is minimum */
void findMinWeightPlanet(double *dist, int V, double initial_weight)
{
        int planet_count = 0;
        double shortest_path;

        shortest_path = dist[0];

        for(int i = 1; i<V; i++) {
                if(dist[i]<shortest_path) {
                        shortest_path = dist[i];
                        planet_count = i;
                }
        }

        printf("\nOUTPUT:\n%d\t%lf\n", planet_count + 1, pow(10, shortest_path )*initial_weight);
}

/* Returns the number of neigbours of given vertex */
int degree(struct Graph *graph, int v)
{
        struct AdjListNode *iterator = NULL;
        iterator = graph->array[v].head;

        int neighboursCount = 0;

        while(iterator!= NULL) {
                neighboursCount++;
                iterator = iterator->next;
        }

        return neighboursCount;
}

/* Function to give the nighbours of given vertex */
int* neigh(struct Graph *graph, int v)
{
        struct AdjListNode *iterator = NULL;
        iterator = graph->array[v].head;

        int total_neighbours = degree(graph, v), count=0;

        int *neighbours = (int *)malloc(total_neighbours*sizeof(int));

        while(iterator!= NULL) {
                neighbours[count] = iterator->dest;
                iterator = iterator->next;
                count++;
        }

        return neighbours;
}

/* Performs dfs traversal */
void dfs(struct Graph *graph, int v, int visited[])
{

        visited[v] = 1;

        printf("\nThe graph vertex %d just got visited.\n", v);

        struct AdjListNode *iterator = graph->array[v].head;

        while(iterator!=NULL) {
                if(visited[iterator->dest] != 1) {
                        dfs(graph, iterator->dest, visited);
                }
                iterator = iterator->next;
        }
}

/* Function to create queue */
Queue* createQueue(int capacity){
        Queue *ptr = (Queue*)malloc(sizeof(Queue));
        //initialize queue
        ptr->capacity = capacity;
        ptr->rear = ptr->front = -1; //-1 indicates queue is empty

        ptr->array = (int *)malloc(capacity*sizeof(int));

        return ptr;
}

/* Inserts the element to queue */
int Qinsert(Queue* ptr, int data){
        // check wheather queue is full
        if((ptr->front == 0 && (ptr->rear) == (ptr->capacity) - 1) || (ptr->front) == (ptr->rear) + 1) {
                printf("Overflow\n");
                return -1;
        }

        // for a non empty queue set rear and front
        else{
                if(ptr->front == -1) {
                        ptr->front = 0;
                        ptr->rear = 0;
                }
                else if((ptr->rear) == (ptr->capacity - 1)) {
                        ptr->rear = 0;
                }
                else{
                        (ptr->rear)++;
                }
        }

        //insert data to array
        ptr->array[ptr->rear] = data;
        return 2;
}

/* Dequeue the element from queue */
int Qdelete(Queue* ptr){
        int item;
        //is queue empty
        if(ptr->front == -1) {
                printf("Underflow\n");
                return -1;
        }
        // set the item as front element
        item = ptr->array[ptr->front];

        //set the value of rear and front
        if(ptr->front == ptr->rear) {
                ptr->front = ptr->rear = -1;
        }
        else if(ptr->front == (ptr->capacity) - 1) {
                ptr->front = 0;
        }
        else{
                ptr->front++;
        }

        return item;
}

/* check for an enpty queue */
int isEmptyQueue(Queue* q)
{
        if((q->front) == -1)
                return 1;
        else
                return 0;
}

/* Performs bfs traversal */
void bfs(struct Graph *graph, int v)
{
        #define initial 1
        #define waiting 2
        #define visited 3

        int state[graph->V], neighbour;

        /* initialize the state of all nodes */
        for(int i = 0; i<graph->V; i++) {
                state[i] = initial;
        }

        Queue *q = createQueue(graph->V);
        Qinsert(q, v);
        state[v] = waiting;

        while(!isEmptyQueue(q)) {
                v = Qdelete(q);
                printf("\n The Graph Node : %d Just Got Visited \n",v);
                state[v] = visited;

                //go to the adjacency list of node v
                struct AdjListNode *iterator = graph->array[v].head;

                /* inserts all neighbours of node v in queue */
                while(iterator!=NULL) {
                        neighbour = iterator->dest;
                        if(state[neighbour] == initial) {
                                Qinsert(q, neighbour);
                                state[neighbour] = waiting;
                        }
                        iterator = iterator->next;
                }
        }
}

/* A utility function to find the vertex with minimum key value, from
   the set of vertices not yet included in MST */
int minKey(double key[], bool mstSet[], int V)
{
        // Initialize min value
        double min = DBL_MAX;
        int min_index;

        for (int v = 0; v < V; v++)
                if (mstSet[v] == false && key[v] < min)
                        min = key[v], min_index = v;

        return min_index;
}

// A utility function to print the constructed MST stored in parent[]
void printMST(struct Graph *graph, int parent[])
{

        printf("Edge   Weight\n");
        for (int i = 1; i < graph->V; i++)
                printf("%d - %d    %lf \n", parent[i], i, weight(graph, i, parent[i]));
}

/* Function to construct and print MST for a graph represented using adjacency
   list representation */
void primMST(struct Graph *graph)
{
        int V = graph->V;
        int parent[V]; // Array to store constructed MST
        double key[V]; // Key values used to pick minimum weight edge in cut
        bool mstSet[V]; // To represent set of vertices not yet included in MST

        // Initialize all keys as INFINITE
        for (int i = 0; i < V; i++)
                key[i] = DBL_MAX, mstSet[i] = false;

        // Always include first 1st vertex in MST.
        key[0] = 0;  // Make key 0 so that this vertex is picked as first vertex
        parent[0] = -1; // First node is always root of MST

        // The MST will have V vertices
        for (int count = 0; count < V-1; count++)
        {
                // Pick the minimum key vertex from the set of vertices
                // not yet included in MST
                int u = minKey(key, mstSet, V), v;

                // Add the picked vertex to the MST Set
                mstSet[u] = true;

                // Update key value and parent index of the adjacent vertices of
                // the picked vertex. Consider only those vertices which are not yet
                // included in MST

                double weight;

                struct AdjListNode *iterator = NULL;

                iterator = graph->array[u].head;

                while(iterator!= NULL) {
                        v = iterator->dest;
                        weight = iterator->weight;
                        iterator = iterator->next;

                        if(mstSet[v] == false && weight < key[v]) {
                                parent[v] = u;
                                key[v] = weight;
                        }
                }
        }

// print the constructed MST
        printMST(graph, parent);
}

/* Function to create set of edges */
struct Edge* setOfEdges(struct Graph *graph){

        struct Edge *ptr = (struct Edge*)malloc(sizeof(struct Edge)*(graph->E));
        int edgesCount = 0;

        for(int i = 0; i<(graph->V); i++) {
                struct AdjListNode *iterator = NULL;
                iterator = graph->array[i].head;

                while(iterator!=NULL) {
                        ptr[edgesCount].src = i;
                        ptr[edgesCount].dest = iterator->dest;
                        ptr[edgesCount].weight = iterator->weight;
                        iterator = iterator->next;
                        edgesCount++;
                }
        }

        return ptr;
}

/* A utility function to find set of an element i
   (uses path compression technique) */
int find(struct subset subsets[], int i)
{
        // find root and make root as parent of i (path compression)
        if (subsets[i].parent != i)
                subsets[i].parent = find(subsets, subsets[i].parent);

        return subsets[i].parent;
}

/* A function that does union of two sets of x and y
   (uses union by rank) */
void Union(struct subset subsets[], int x, int y)
{
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        // Attach smaller rank tree under root of high rank tree
        // (Union by Rank)
        if (subsets[xroot].rank < subsets[yroot].rank)
                subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
                subsets[yroot].parent = xroot;

        // If ranks are same, then make one as root and increment
        // its rank by one
        else
        {
                subsets[yroot].parent = xroot;
                subsets[xroot].rank++;
        }
}

/* Compare two edges according to their weights.
   Used in qsort() for sorting an array of edges */
int myComp(const void* a, const void* b)
{
        struct Edge* a1 = (struct Edge*)a;
        struct Edge* b1 = (struct Edge*)b;
        return a1->weight > b1->weight;
}

// The main function to construct MST using Kruskal's algorithm
void KruskalMST(struct Graph* graph)
{
        int V = graph->V;
        struct Edge result[V]; // Tnis will store the resultant MST
        int e = 0; // An index variable, used for result[]
        int i = 0; // An index variable, used for sorted edges
        struct Edge* edge = setOfEdges(graph);

        // Step 1:  Sort all the edges in non-decreasing order of their weight
        // If we are not allowed to change the given graph, we can create a copy of
        // array of edges
        qsort(edge, graph->E, sizeof(edge[0]), myComp);

        // Allocate memory for creating V ssubsets
        struct subset *subsets =
                (struct subset*) malloc( V * sizeof(struct subset) );

        // Create V subsets with single elements
        for (int v = 0; v < V; ++v)
        {
                subsets[v].parent = v;
                subsets[v].rank = 0;
        }

        // Number of edges to be taken is equal to V-1
        while (e < V - 1)
        {
                // Step 2: Pick the smallest edge. And increment the index
                // for next iteration
                struct Edge next_edge = edge[i++];

                int x = find(subsets, next_edge.src);
                int y = find(subsets, next_edge.dest);

                // If including this edge does't cause cycle, include it
                // in result and increment the index of result for next edge
                if (x != y)
                {
                        result[e++] = next_edge;
                        Union(subsets, x, y);
                }
                // Else discard the next_edge
        }

        // print the contents of result[] to display the built MST
        printf("Following are the edges in the constructed MST\n");
        for (i = 0; i < e; ++i)
                printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                       result[i].weight);
        return;
}
