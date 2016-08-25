/*.....................................................................................
Name : Sumit Patidar
Roll no : B15237
Purpose : IC250 assignment, question 2
Date : 23.08.2016
.......................................................................................*/

//source code to solve TOWER OF HANOI puzzle using iterative method
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define odd 1
#define even 0

typedef struct stack {
    unsigned capacity;
    int top;
    int *data;
}peg;

int push(peg *ptr, int data);
int pop(peg *ptr);
int isFull(peg *ptr);
int isEmpty(peg *ptr);
peg* create(int capacity);
int display(peg *ptr);

int main(){
    int disk_quantity;
    printf("Enter the number of disk : ");
    scanf("%d", &disk_quantity);

    peg* ptrA = create(disk_quantity);
    peg* ptrB = create(disk_quantity);
    peg* ptrC = create(disk_quantity);

    // insert disk data into stack
    for(int i = disk_quantity; i >= 1; i--){
        push(ptrA, i);
    }
   
    int number_of_steps = pow(2, disk_quantity) - 1;
    int odd_even;

    // check disk_quantity for odd & even
    if(disk_quantity%2 == 0)
        odd_even = 0;
    
    else
        odd_even = 1;
    
    int disk_data;

    switch(odd_even){
         
        case 0:
        // source and destination are interchanged since number of disk are even
        for(int i = 1; i <= number_of_steps; i++){

             if(i%3 == 1){
                if(display(ptrB) > display(ptrA)){
                    disk_data =  pop(ptrA);
                    push(ptrB, disk_data);
                    printf("[%d] disk %d moved from peg A to peg B\n", i, disk_data);
                }
                else{
                    disk_data =  pop(ptrB);
                    push(ptrA, disk_data);
                    printf("[%d] disk %d moved from peg B to peg A\n", i, disk_data);
                }
             }

            else if(i%3 == 2){
                if(display(ptrC) > display(ptrA)){
                    disk_data =  pop(ptrA);
                    push(ptrC, disk_data);
                    printf("[%d] disk %d moved from peg A to peg C\n", i, disk_data);
                }
                
                else{
                    disk_data =  pop(ptrC);
                    push(ptrA, disk_data);
                    printf("[%d] disk %d moved from peg C to peg A\n", i, disk_data);
                }
            }
        
            else{
                if(display(ptrC) > display(ptrB)){
                    disk_data =  pop(ptrB);
                    push(ptrC, disk_data);
                    printf("[%d] disk %d moved from peg B to peg C\n", i, disk_data);
                }
                else{
                    disk_data =  pop(ptrC);
                    push(ptrB, disk_data);
                    printf("[%d] disk %d moved from peg C to peg B\n", i, disk_data);
                }
            }
        }
        break;

         case 1:
         
         for(int i = 1; i <= number_of_steps; i++){

             if(i%3 == 1){
                if(display(ptrC) > display(ptrA)){
                    disk_data =  pop(ptrA);
                    push(ptrC, disk_data);
                    printf("[%d] disk %d moved from peg A to peg C\n", i, disk_data);
                }
                else{
                    disk_data =  pop(ptrC);
                    push(ptrA, disk_data);
                    printf("[%d] disk %d moved from peg C to peg A\n", i, disk_data);
                }
             }

            else if(i%3 == 2){
                 if(display(ptrB) > display(ptrA)){
                    disk_data =  pop(ptrA);
                    push(ptrB, disk_data);
                    printf("[%d] disk %d moved from peg A to peg B\n", i, disk_data);
                }
                
                else{
                    disk_data =  pop(ptrB);
                    push(ptrA, disk_data);
                    printf("[%d] disk %d moved from peg B to peg A\n", i, disk_data);
                }
            }
        
            else{
                if(display(ptrB) > display(ptrC)){
                    disk_data =  pop(ptrC);
                    push(ptrB, disk_data);
                    printf("[%d] disk %d moved from peg C to peg B\n", i, disk_data);
                }
                else{
                    disk_data =  pop(ptrB);
                    push(ptrC, disk_data);
                    printf("[%d] disk %d moved from peg B to peg C\n", i, disk_data);
                }
            }
         }
    }
      printf("\nTotal number of moves are %d\n", number_of_steps);
      return 0;
}

int push(peg *ptr, int data){
    if(ptr->top != (ptr->capacity - 1)){
      (ptr->top)++;
       ptr->data[ptr->top] = data;
       return 0;
    }
    else return -5; // negative integer for empty stack
}
int pop(peg *ptr){
    int data;
    data = ptr->data[ptr->top];
    (ptr->top)--;
    return data;
}
peg* create(int capacity){
    peg* ptr = (peg *)malloc(sizeof(peg));
    
    ptr->capacity = capacity;
    ptr->top = -1;
    ptr->data = (int* )malloc(capacity * sizeof(int)); // allocating space for data
    return ptr;
}
int display(peg *ptr){
    if(ptr->top == -1)//stack is empty
        return (ptr->capacity) + 1;
    else
       return ptr->data[ptr->top];
}