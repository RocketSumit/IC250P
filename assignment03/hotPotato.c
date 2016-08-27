/*-------------------------------------------------------------------------------
Name: Sumit Patidar
Roll no: B15237
Purpose: IC250 assignment, question 01
Date: 27/08/2016
---------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

typedef struct queue{
    int front , rear, capacity;
    int *array;
}children;
/* Front points to first element in queue,
    Rear points to last element in queue */
children* createQueue(int capacity);
int Qinsert(children* ptr, int data);
int Qdelete(children* ptr, int front, int rear);

int main(){
    int players;
    printf("Enter the number of children: ");
    scanf("%d", &players);

    children *group1 = createQueue(players);
    
    return 0; 
}

children* createQueue(int capacity){
    children *ptr = (children*)malloc(sizeof(children));
    //initialize queue
    ptr->capacity = capacity;
    ptr->rear = ptr->front = -1;
    /* -1 indicates queue is empty */
    ptr->array = (int *)malloc(sizeof(int));
}

int Qinsert(children* ptr, int data){
    // check wheather queue is full
    if((ptr->front == 0 && (ptr->rear) == (ptr->capacity) - 1) || (ptr->front) == (ptr->rear) + 1)  
        return -1;
    
    // for a non empty queue set rear and front
    else{
        if(ptr->front == -1){
             ptr->front = 0;
             ptr->rear = 0;
        }
        else if((ptr->rear) == (ptr->capacity - 1)){
            ptr->rear = 0;
        }
        else{
            (ptr->rear)++;
        }
    }

    //insert data to array
    ptr->array[ptr->rear] = data;
    return 0;
}