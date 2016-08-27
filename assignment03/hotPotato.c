/*-------------------------------------------------------------------------------
Name: Sumit Patidar
Roll no: B15237
Purpose: IC250 assignment, question 01
Date: 27/08/2016
---------------------------------------------------------------------------------*/
#include <stdio.h>

typedef struct queue{
    int front , rear;
    int *array;
}children;
/* Front points to first element in queue,
    Rear points to last element in queue */
    
int Qinsert(children* ptr, int front, int rear, int data);
int Qdelete(children* ptr, int front, int rear);

int main(){
    int players;
    printf("Enter the number of children: ");
    scanf("%d", &players);

    children *group1; 
}