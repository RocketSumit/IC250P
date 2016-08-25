//Sumit Patidar, B15237
// source code to find optimum threshold using histogram

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

// Error definitions
#define NO_FILE_EXISTS_ERROR 1

// constants
#define NUMBER_OF_POSSIBLE_THRESHOLDS 256

int main()
{
    int frequencies[NUMBER_OF_POSSIBLE_THRESHOLDS];
    clock_t start, end;

    // Reseting array
    int i;
    for(i = 0; i < NUMBER_OF_POSSIBLE_THRESHOLDS; i++)
        frequencies[i] = 0;
    
    start = clock();

    // Open the data file
    FILE *data_file = fopen("/Users/sumitpatidar/Desktop/1.txt", "r");

    if (data_file == NULL)
        return NO_FILE_EXISTS_ERROR;

    // Get the total number of pixels from the data file
    int column, row;
    fscanf(data_file, "%d %d", &column, &row);
    int total_pixels = column * row;

    // Fill the frequencies array with numbers from the file
    for(int k = 0; k < total_pixels; k++) {
        // Get the next pixel data
        int buffer;
        fscanf(data_file, "%d", &buffer);

        // If pixel data is valid
        if (buffer >= 0 && buffer < NUMBER_OF_POSSIBLE_THRESHOLDS) 
            // Add to frequencies array
            frequencies[buffer] += 1;
    }
    
    end = clock();
    double time_taken_for_reading = (double)(end - start)/CLOCKS_PER_SEC;
    printf("Data read in %lf ms\n", 1000*time_taken_for_reading);
    
    //----------------------Data reading completed----------------------------------------------------------------------------------------------------------------------------
    
    start = clock();

    //defining commands for gnuplot
    char *commandsForGnuplot[] = { "set terminal png"," set title\"th vs d'\"", " set output 'a2.png'", " plot \"result2.dat\" using 1:2 "};
    char *commandsForGnuplot2[] = { "set terminal png"," set title\"th vs n_p\"", " set output 'b2.png'", " plot \"result2.dat\" using 1:3 "};
    char *commandsForGnuplot3[] = { "set terminal png"," set title\"d' vs n_p\"", " set output 'c2.png'", " plot \"result2.dat\" using 2:3 "};

    // Open the result file
    FILE *result_ptr = fopen("/Users/sumitpatidar/Desktop/result2.dat", "w");
    fprintf(result_ptr, "%s\t%s\t%s\n", "#th", "d'", "n_p");

    // Iterate over all possible partitions
    int threshold;
    for (threshold = 0; threshold < NUMBER_OF_POSSIBLE_THRESHOLDS; threshold++) {
        int clusterA_num = 0;
        int clusterB_num = 0;

        int clusterA_sum = 0;
        int clusterB_sum = 0;

        // calculate lower sum and number of elements
        for (i = 0; i <= threshold; i++) {
            clusterA_num += frequencies[i];
            clusterA_sum += i * frequencies[i];
        }
        
        // Calculate upper sum and number of elements
        for (i = threshold + 1; i < NUMBER_OF_POSSIBLE_THRESHOLDS; i++) {
            clusterB_num += frequencies[i];
            clusterB_sum += i * frequencies[i];
        }
        
        // Calculate points ratio
        double points_ratio = (double) clusterA_num/ (double) clusterB_num;
        if(isinf(points_ratio) == 1) /* check for infinity */
        points_ratio = 0;

        // Calculate means
        double clusterA_mean = 0;
        double clusterB_mean = 0;

        if (clusterA_num != 0)
            clusterA_mean = (double) clusterA_sum / (double) clusterA_num;
        if (clusterB_num != 0)
            clusterB_mean = (double) clusterB_sum / (double) clusterB_num;

        // standard Deviation
        double standard_deviation_A = 0;
        double standard_deviation_B = 0;

        double sum_of_squares_A = 0;
        double sum_of_squares_B = 0;

        int k = 0;

        //calculating sum of squares
        for(int i = 0; i <= threshold; i++){
            if(frequencies[i] != 0)
                sum_of_squares_A += (pow((clusterA_mean - i), 2)) * frequencies[i];
        }

        for(int i = threshold + 1; i < NUMBER_OF_POSSIBLE_THRESHOLDS; i++){
            if(frequencies[i] != 0)
                 sum_of_squares_B += (pow((clusterB_mean - i), 2)) * frequencies[i];
        }

        if(clusterA_num != 0)
        standard_deviation_A = sqrt((sum_of_squares_A)/ (double) (clusterA_num));
        if(clusterB_num != 0)
        standard_deviation_B = pow( ((sum_of_squares_B)/ (double) (clusterB_num)), 0.5);

        // Calculate discriminative index
        double discriminative_index = 0.0;
        if(standard_deviation_A != 0 || standard_deviation_B != 0)
        discriminative_index = (clusterA_mean - clusterB_mean)/pow((pow(standard_deviation_A, 2) + pow(standard_deviation_B, 2)), 0.5);
        
        //print the data on file
        fprintf(result_ptr, "%d\t%lf\t%lf\n", threshold, fabs(discriminative_index), points_ratio);
        
    }
     end = clock();
     double time_taken_for_thresholding = (double)(end - start)/CLOCKS_PER_SEC;

     printf("Thresholding done in %lf ms\n", time_taken_for_thresholding);
  // ------------------------------------------Thresholding done------------------------------------------------------------

     FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
      for(int ind = 0; ind<4; ind++){

        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[ind]);
       }

       for(int ind = 0; ind<5; ind++){

        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot2[ind]);
       }
       for(int ind = 0; ind<5; ind++){

        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot3[ind]);
       }

     // appending time taken in Part A and Part B to res.txt
     FILE *time_taken = fopen("/Users/sumitpatidar/Desktop/res.txt", "a+");
     fprintf(time_taken, "%s\n", "\n\nTime data using histogram");
     fprintf(time_taken, "%s %lf %s \n%s %lf %s","Time taken in Part A = ", time_taken_for_reading,"ms","Time taken in Part B = ",time_taken_for_thresholding, "ms");

     printf("Result.dat generated at <Desktop>\n");
     printf("\nGraphs  genarated at <Desktop>\n");
     printf("\nFinal res.txt is generated at Desktop\n");
     return 0;
}