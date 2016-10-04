#include "my_library.h"

int main(int argc, char const *argv[]) {
        int V, E, src, dest;
        double weight;

        scanf("%d %d", &V, &E);
        struct Graph *graph = createGraph(V, E);

        for(int i = 0; i<E; i++) {
                scanf("%d%d%lf", &src, &dest, &weight);
                addEdge(graph, src - 1, dest - 1, pow(weight, -1), i);
        }

        int initial_planet;
        double initial_weight, dist[V];

        scanf("%d%lf", &initial_planet, &initial_weight);

        BellmanFord(graph, initial_planet - 1, dist);

        findMinWeightPlanet(dist, V, initial_weight);

        return 0;
}
