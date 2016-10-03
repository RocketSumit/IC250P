#include "my_library.h"

int main(int argc, char const *argv[]) {
        int vertices, total_edges;
        scanf("%d%d", &vertices, &total_edges);

        struct Graph *graph = NULL;
        graph = createGraph(vertices);

        int src, dest;
        double weight;

        for(int i = 0; i<total_edges; i++) {
                scanf("%d%d%lf", &src, &dest, &weight);
                addEdge(graph, src, dest, weight);
        }

        int residing_hostel, total_hostels_csgo;
        scanf("%d%d", &residing_hostel, &total_hostels_csgo);
        int *hostels_csgo = (int *)malloc(total_hostels_csgo*sizeof(int));

        for(int j = 0; j<total_hostels_csgo; j++) {
                scanf("%d", hostels_csgo++);
        }

        printGraph(graph);

        return 0;
}
