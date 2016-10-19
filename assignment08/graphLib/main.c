#include "my_header.h"

int main(int argc, char const *argv[]) {

        struct Graph *graph = createGraph(3, 0);
        addEdge(graph, 0, 1, 3);
        addEdge(graph, 0, 2, 2);
        addEdge(graph, 1, 2, -1);
        KruskalMST(graph);

        return 0;
}
