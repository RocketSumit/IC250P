/*...................................................................................
Name : Sumit Patidar
Roll no : B15237
Purpose : IC250 assignment 2, question 1
Date : 22.08.2016
.....................................................................................*/

// source code to solve puzzle of TOWER OF HANOI using recursion
#include <stdio.h>

void moveTower(int disks, char A, char B, char C); // move tower from  peg A to peg B using peg C
static int count = 0;

int main(){
    int disk_quantity;
    printf("Enter the number of disks: ");
    scanf("%d", &disk_quantity);
    printf("\n");
    // Make a recursive call to function moveTower
    moveTower(disk_quantity, 'A', 'B', 'C');

    printf("\nTotal number of moves are %d\n", count);
    return 0;
}

void moveTower(int disks, char A, char B, char C)
{
    if (disks == 1){
        count++;
        printf("[%d] Moved disk %d from %c to %c\n",count, disks, A, C); 

    }
    else {
        // problem is divided to sub 2 problem
        moveTower(disks - 1, A, C, B); 
        count++;
        printf("[%d] Moved disk %d from %c to %c\n",count, disks, A, C); 
        moveTower(disks - 1, B, A, C);
    }
}