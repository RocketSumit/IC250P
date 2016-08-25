// Sumit Patidar, B15237
// source code to find optimum threshold for pixels using structures and linked list

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MAX_GRAYVALUE 256

/* Functions declaration for initializing
    and creating matrix */

int** inti_2DArray(int r, int c);
int** create_2DArray(FILE *ptr, int r, int c );

/* define two different structures for 
    cluster A and cluster B */

typedef struct clusterA{
    int grey_value;
    struct clusterA *next;
}cluster_A;

typedef struct clusterB{
    int grey_value;
    struct clusterB *next;
}cluster_B;

//declare function to fill the clusters A and B
void insert_cluster_A(cluster_A **head_A, int pixel_value);
void insert_cluster_B(cluster_B **head_B, int pixel_value);

/* declare function to compute the statistics
        for cluster A and B */
double* statistics_A(cluster_A *head);
double* statistics_B(cluster_B *head);

int main(){
    int r, c;//rows and coulumns
    int **mat_ptr;//pointer to matrix

    clock_t start, end;

    double time_taken_for_reading;

    //Opening file
    FILE *ptr;
    ptr = fopen("/Users/sumitpatidar/Desktop/1.txt", "r");

    //reading no_of rows & coulumn
    fscanf(ptr,"%d %d", &r, &c);

    printf("Reading the input data........\n");
    start = clock();

    mat_ptr = create_2DArray(ptr, r, c);//matrix is created

    end = clock();

    time_taken_for_reading = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Data read in %lf ms\n", time_taken_for_reading*1000);
// ---------------------------------------Data reading completed----------------------------------------------------
    
    printf("Performing iterative thresholding......\n");
    start = clock();
    
    //head points to clusters for each threshold
    cluster_A *head_A[256];
    cluster_B *head_B[256];
    
    int threshold , i , j ;

    //start thresholding
    for( threshold = 0; threshold < MAX_GRAYVALUE; threshold++ ){

        
        head_A[threshold] = NULL;
        head_B[threshold] = NULL;
       
       //dividing into clusters
        for(i = 0; i < r; i++){

            for(j = 0; j < c; j++){

                  if(*(mat_ptr[i] + j) <= threshold)
                     insert_cluster_A(&head_A[threshold], *(mat_ptr[i] + j));
                  else
                     insert_cluster_B(&head_B[threshold], *(mat_ptr[i] + j));
             }
        }
    }

    end = clock();
    double time_taken_for_thresholding = ((double) (end - start))/CLOCKS_PER_SEC;
    printf("Thresholding done in %lf ms\n", time_taken_for_thresholding*1000);
//-------------------------------------Thresholding done----------------------------------------------------------------------------

    //defining commands for gnuplot
    char *commandsForGnuplot[] = { "set terminal png"," set title\"th vs d'\"", " set output 'a.png'", " plot \"result.dat\" using 1:2 "};
    char *commandsForGnuplot2[] = { "set terminal png"," set title\"th vs n_p\"", " set output 'b.png'", " plot \"result.dat\" using 1:3 "};
    char *commandsForGnuplot3[] = { "set terminal png"," set title\"d' vs n_p\"", " set output 'c.png'", " plot \"result.dat\" using 2:3 "};
    FILE *result_ptr = fopen("/Users/sumitpatidar/Desktop/result.dat", "w");

    
    fprintf(result_ptr, "%s\t%s\t%s\n", "#th", "d'", "n_p");

    //finding out the result
   for(int k = 0; k < MAX_GRAYVALUE; k++){

        double *ptr_A = statistics_A(head_A[k]);
        double *ptr_B = statistics_B(head_B[k]);

        double points_ratio = ((*ptr_A)/(*ptr_B));

        if (isinf(points_ratio) == 1)  /* check for infinity */
        points_ratio = 0;

        double discriminative_index = 0;

        discriminative_index = (*(ptr_A + 1) - *(ptr_B + 1))/(pow ((pow(*(ptr_A + 2), 2) + pow(*(ptr_B + 2), 2)), 0.5));

        fprintf(result_ptr, "%d\t%lf\t%lf\n", k, fabs(discriminative_index), points_ratio);
    }

    FILE *gnuplotPipe = popen("gnuplot -persistent", "w");
    for(int ind = 0; ind<5; ind++){

        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot[ind]);
       }

       for(int ind = 0; ind<5; ind++){

        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot2[ind]);
       }
       for(int ind = 0; ind<5; ind++){

        fprintf(gnuplotPipe, "%s \n", commandsForGnuplot3[ind]);
       }

    // writing the time taken for part A and B to res.txt
    FILE *time_taken = fopen("/Users/sumitpatidar/Desktop/res.txt", "w");
    fprintf(time_taken, "%s\n", "Time data using structures");
    fprintf(time_taken, "%s %lf %s \n%s %lf %s","Time taken in Part A = ", time_taken_for_reading,"ms","Time taken in Part B = ",time_taken_for_thresholding, "ms");

    fclose(time_taken);
    fclose(result_ptr);
    pclose(gnuplotPipe);
    fclose(ptr);

    printf("Result.dat generated at <Desktop>\n");
    printf("\nGraphs  genarated at <Desktop>\n");
    printf("\nFinal res.txt is generated at Desktop\n");

    return 0;
}
//-------------------------------------------- Main() ends------------------------------------------------------------------------------------------------
//Allocate memory for matrix
int** inti_2DArray(int r, int c)
{
        int **x, i;
        x = (int **)malloc(r * sizeof(int*));

        //allocating memory for each row
        for(int i = 0; i < r; i++ )
            x[i] = (int *)malloc(c * sizeof(int));

        return x;

}

//create matrix
int** create_2DArray(FILE *ptr, int  r, int c )
{
    int **x, i, j;
    x = inti_2DArray(r, c);

    for( i = 0; i < r; i++){

        for( j = 0; j < c; j++ ){
            fscanf(ptr, "%d", &x[i][j]);//filling matrix
        }
    }
    
    return x;
}

//function to insert grey value of pixel in group A
void insert_cluster_A(cluster_A **head_A, int pixel_value)
{
    
    cluster_A * new_node;
    new_node = malloc(sizeof(cluster_A));

    new_node->grey_value = pixel_value;

    // prepending the new element 
    if(*head_A == NULL){
        new_node->next = NULL;
        *head_A = new_node;
    }
    else{
        new_node->next = *head_A;
        *head_A = new_node;
    }
}

//function to insert grey value of pixel in group A
void insert_cluster_B(cluster_B **head_B, int pixel_value)
{
    
    cluster_B * new_node;
    new_node = malloc(sizeof(cluster_B));

    new_node->grey_value = pixel_value;

    // prepending the new element 
    if(*head_B == NULL){           
        new_node->next = NULL;
        *head_B = new_node;
    }
    else{
        new_node->next = *head_B;
        *head_B = new_node;
    }
 }

//function to find statistics for cluster A
double* statistics_A(cluster_A *head){
    cluster_A * current = head;
    double no_points_A = 0.0, mean = 0.0, standard_deviation = 0.0, sum = 0.0;

    //calculating no_of points and their sum
    while (current != NULL) {
        sum += current->grey_value;
        no_points_A++;
        current = current->next;
    }

    if(no_points_A != 0){

    mean = (double)(sum/(no_points_A ));

    //calculating standard deviation
    current = head;
    double square_sum = 0.0;
     while (current != NULL) {
        square_sum += pow((mean - (current->grey_value)), 2);
        current = current->next;
        }
    standard_deviation = pow((square_sum)/(no_points_A), 1.0/2.0);
    }
    
   double static statistic_data[3]; 
   statistic_data[0] = no_points_A ;
   statistic_data[1] = mean;
   statistic_data[2] = standard_deviation;
   
   return statistic_data;
}

//function to find statistics for cluster A
double* statistics_B(cluster_B *head){
    cluster_B * current = head;
    double no_points_B = 0.0, mean = 0.0, standard_deviation = 0.0, sum = 0.0;

    // calculating no of points & their sum
    while (current != NULL) {
        sum += current->grey_value;
        no_points_B++;
        current = current->next;
    }
    if(no_points_B != 0){

    mean = (double)(sum/(no_points_B));

    // calculating standard_deviation
    current = head;
    double square_sum = 0.0;
     while (current != NULL) {
        square_sum += pow(fabs(mean - (current->grey_value)), 2.0);
        current = current->next;
        }
    standard_deviation = pow((square_sum)/(no_points_B), 0.5);
    }
    
   double static statistic_data[3]; 
   statistic_data[0] = no_points_B;
   statistic_data[1] = mean;
   statistic_data[2] = standard_deviation;
   
    return statistic_data;
}