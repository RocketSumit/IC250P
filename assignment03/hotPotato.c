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
int Qdelete(children* ptr);

int main(){
    int players, elimination_number;
    printf("Enter the number of children n and i: ");
    scanf("%d%d", &players, &elimination_number);

    children *group1 = createQueue(players);
    
    //insert players in queue
    for (int i = 0; i < players; i++)
    {
        Qinsert(group1, i + 1);
    }
  
    int child, potato_position;
    printf("\n\nThe removal of sequence is as follows:\n\n");

    //plan the winning strategy
    for(int j = 1; j < players; j++ ){
         for (int k = 1; k < elimination_number; k++)
        {
              child = Qdelete(group1);
              Qinsert(group1, child);
        }
        //eliminating the potato bearer
        potato_position = Qdelete(group1);

        if( j == 1)
            printf("[%d] Firstly, the person at position %d is removed\n", j, potato_position);
        else if( j < players - 1)
            printf("[%d] Then person at position %d is removed\n", j, potato_position);
        else if(j == players - 1 )
            printf("[%d] Finally, person at position %d is removed\n", j , potato_position);
   }

    //declaring the winner
    printf("\n\nHence, the person at position %d survives (WINNER)\n", Qdelete(group1));

    return 0; 
}
//---------------------------------------------------------------------------------------------------------
children* createQueue(int capacity){
    children *ptr = (children*)malloc(sizeof(children));
    //initialize queue
    ptr->capacity = capacity;
    ptr->rear = ptr->front = -1;

    /* -1 indicates queue is empty */
    ptr->array = (int *)malloc(sizeof(int));

    return ptr;
}

int Qinsert(children* ptr, int data){
    // check wheather queue is full
    if((ptr->front == 0 && (ptr->rear) == (ptr->capacity) - 1) || (ptr->front) == (ptr->rear) + 1){
        printf("Overflow\n");
        return -1;
    }
    
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
    return 2;
}

int Qdelete(children* ptr){
    int item;
    //is queue empty
    if(ptr->front == -1){
        printf("Underflow\n");
        return -1;
    }
    // set the item as front element
    item = ptr->array[ptr->front];

    //set the value of rear and front
    if(ptr->front == ptr->rear){
        ptr->front = ptr->rear = -1;
    }
    else if(ptr->front == (ptr->capacity) - 1){
        ptr->front = 0;
    }
    else{
        ptr->front++;
    }
    
    return item;
}