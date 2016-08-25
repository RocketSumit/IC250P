/*...................................................................................
Name : Sumit Patidar
Roll no : B15237
Purpose : IC250 assignment 2, question 3(Double tower hanoi)
Date : 24.08.2016
.....................................................................................*/

// header file for stack and its functions

#ifndef PEG_H_
#define PEG_H_
#include <stdlib.h>

typedef struct stack {
    unsigned capacity;
    int top;
    int *data;
}peg;

void push(peg *ptr, int data){
    (ptr->top)++;
    ptr->data[ptr->top] = data;
}
int pop(peg *ptr){
    int data;
    data = ptr->data[ptr->top];
    (ptr->top)--;
    return data;
}
int isFull(peg *ptr){
    if((ptr->top) == (ptr->capacity - 1))
        return 1;
    
    else return 0;
}
int isEmpty(peg *ptr){
    if((ptr->top) == -1)
        return 1;
    
    else return 0;
}
peg* create(int capacity){
    peg* ptr = (peg *)malloc(sizeof(peg));
    
    ptr->capacity = capacity;
    ptr->top = -1;
    ptr->data = (int* )malloc(capacity * sizeof(int)); // allocating space for data
    return ptr;
}
int display(peg *ptr){
    if(ptr->top == -1)
        return (ptr->capacity) + 1;
    else
       return ptr->data[ptr->top];
}
#endif