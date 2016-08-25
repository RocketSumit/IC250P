//source code to check for palindrome paragraph

#include <stdio.h>
#include <string.h>

int main(){

    char string[20][50];
    char token[50];

    printf("Enter the paragraph :\n");

    int no_token = 0;

    //reading each word till the EOF
    while(scanf("%s", token) != EOF){

        strcpy(string[no_token], token);
         no_token++;

    }
 
    int flag = 0;

    //comparing the first and second half
    for(int i = 0; i<(no_token/2); i++){
        if(strcmp(string[i], string[no_token - (i + 1)]) == 0)
        flag++;
    }
    
    if(flag == (no_token/2))
    printf("Given paragraph is palindrome.\n");
    else
    printf("Given paragraph is NOT palindrome.\n");

    return 0;
}






