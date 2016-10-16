#include "my_library.h"

int main(int argc, char const *argv[]) {
        int V, E, src, dest;
        double weight;

        FILE *fptr  = fopen("data.txt", "r");
        fscanf(fptr,"%d%d\n", &V, &E);
        struct Graph *graph = createGraph(V, E);

        /* add adge between sorce and destination with given weight */
        for(int i = 0; i<E; i++) {
                fscanf(fptr,"%d%d%lf\n", &src, &dest, &weight);
                addEdge(graph, src - 1, dest - 1, weight, i);
        }

        int initial_planet;
        double initial_weight, dist[V];
        fscanf(fptr,"%d%lf\n", &initial_planet, &initial_weight);

        BellmanFord(graph, initial_planet - 1, dist);
        findMinWeightPlanet(dist, V, initial_weight );

        return 0;
}
