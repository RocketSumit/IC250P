//source code to check for a pailndrome number
#include <stdio.h>
#include <string.h>

int main(){
    
    char string[100];
    
    printf("Please enter the string to be checked as palindrome :\n");
    scanf("%s",string);

    int similar = strlen(string)/2; // represent the number of similar characters

    int j = 0;

    //comparing first half and second half of string 
    for(int i = 0; i < similar; i++){

        if(string[i] == string[strlen(string) - (i + 1)])
        j++;
        else
        ;
    }

    if( j == similar)
    printf("%s is a pailndrome string.\n", string);
    else
    printf("%s is NOT a palindrome string.\n", string);

    return 0;

}