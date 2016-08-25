/*...................................................................................
Name : Sumit Patidar
Roll no : B15237
Purpose : IC250 assignment 2, question 3(Double tower hanoi)
Date : 24.08.2016
.....................................................................................*/

// source code to solve puzzle of TOWER OF HANOI using recursion
#include <stdio.h>
#include <stdlib.h>
#include "peg.h"

void moveTower(int disks, char A, char B, char C, peg* ptrA, peg* ptrB, peg* ptrC); // move tower from  peg A to peg B using peg C

static int count = 0; // count moves
int disk_quantity;

int main(){
    
    printf("Enter the number of disks: ");
    scanf("%d", &disk_quantity);
    
    while((disk_quantity%2) != 0){
        printf("Total number of disk cannot be odd\n");
        printf("Enter once again\n");
        scanf("%d", &disk_quantity);
    }
    peg* ptrA = create(disk_quantity), *ptrB = create(disk_quantity), *ptrC = create(disk_quantity);
    // insert disk data into stack
    for(int i = disk_quantity; i >= 1; i--){
        push(ptrA, i);
        }

    // Make a recursive call to function moveTower
    moveTower(disk_quantity/2, 'A', 'B', 'C', ptrA, ptrB, ptrC); // half of disks are identical

    printf("\n\nTotal no of moves were %d\n", count);
    return 0;
}

void moveTower(int disks, char A, char B, char C, peg* ptrA, peg* ptrB, peg* ptrC)
{   
    
    int disk_no;
    if (disks == 1){
        count++;
        /* pop from A and push to C */
        disk_no = pop(ptrA);
        push(ptrC, disk_no);
        printf("[%d] Moved disk %d from %c to %c\n",count, disk_no, A, C);
        count++;

        /* pop from A and push to C */
        disk_no = pop(ptrA);
        push(ptrC, disk_no);
        printf("[%d] Moved disk %d from %c to %c\n",count, disk_no, A, C); 
        return;
        }
        
        // problem is divided to sub 3 problems
        moveTower(disks - 1, A, C, B, ptrA, ptrC, ptrB); 
        moveTower(1, A, B, C, ptrA, ptrB, ptrC);
        moveTower(disks - 1, B, A, C, ptrB, ptrA, ptrC);
}
