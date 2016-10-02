struct Graph {
        int V;
        struct AdjList *arrray;
};

struct AdjList {
        struct AdjListNode *head;
};

struct AdjListNode {
        int dest;
        struct AdjListNode *next;
};
