#include "my_library.h"

int main(int argc, char const *argv[]) {
        printf("INPUT:\n");
        int vertices, total_edges;
        scanf("%d%d", &vertices, &total_edges);

        struct Graph *graph = createGraph(vertices, 0);

        int src, dest;
        double weight;

        for(int i = 0; i<total_edges; i++) {
                scanf("%d%d%lf", &src, &dest, &weight);
                addEdge(graph, src - 1, dest - 1, weight);
        }

        int residing_hostel, total_hostels_csgo;
        scanf("%d%d", &residing_hostel, &total_hostels_csgo);
        int *hostels_csgo = (int *)malloc(total_hostels_csgo*sizeof(int));

        for(int j = 0; j<total_hostels_csgo; j++) {
                scanf("%d", (hostels_csgo + j));
        }

        double *dist = dijkstra(graph, residing_hostel - 1);

        printf("\nOUTPUT:\n");

        for(int i = 0; i<total_hostels_csgo; i++) {
                printf("%d\t%lf\n", *(hostels_csgo + i), dist[*(hostels_csgo + i) - 1]);
        }

        return 0;
}
