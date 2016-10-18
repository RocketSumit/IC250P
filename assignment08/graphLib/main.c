#include "my_header.h"

int main(int argc, char const *argv[]) {
        int V, E, src, dest;
        double weight;

        FILE *fptr  = fopen("data.txt", "r");
        fscanf(fptr,"%d%d\n", &V, &E);
        struct Graph *graph = createGraph(V, 1);

        /* add adge between sorce and destination with given weight */
        for(int i = 0; i<E; i++) {
                fscanf(fptr,"%d%d%lf\n", &src, &dest, &weight);
                addEdge(graph, src - 1, dest - 1, weight);
        }

        int initial_planet;
        double initial_weight, *dist;
        fscanf(fptr,"%d%lf\n", &initial_planet, &initial_weight);

        dist = BellmanFord(graph, initial_planet - 1);
        findMinWeightPlanet(dist, V, initial_weight );

        printf("Degree of 2 is %d\n", degree(graph, 1));
        int *n =  neigh(graph, 1);

        for(int i = 0; i<degree(graph, 1); i++) {
                printf("%d\t", n[i]);
        }
        printf("\n");
        printf("Degree of 1 is %d\n", degree(graph, 0));

        return 0;
}
