#include "my_header.h"

int main(int argc, char const *argv[]) {

        system("clear");

        struct Graph *graph = createGraph(11, 1);
        addEdge(graph, 0, 1, 0);
        addEdge(graph, 0, 2, 0);
        addEdge(graph, 1, 2, 0);
        addEdge(graph, 2, 0, 0);
        addEdge(graph, 2, 3, 0);
        addEdge(graph, 3, 3, 0);

        int visited[4] = {0};

        dfs(graph, 2, visited);
        bfs(graph, 2);

        return 0;
}
