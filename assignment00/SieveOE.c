//source code to find prime numbers between 1-100 using sieve of Eratosthenes
#include <stdio.h>

int main(){
    int num[100];

    //filling the array with numbers from 1-100
    for(int i = 1; i<= 100; i++){
        num[i] = i;
    }

    int current_position = 3;

    for(int j = 1; j<48; j++){
        
        //checks the multiple of current_position
        for(int i = current_position; i <= 100; i++){
            if((num[i]%(j + 1)) == 0)
            num[i] = 0;
        }
        current_position++;
    }

    //counting the number of prime numbers
    int count_prime = 0;

    for(int k = 1; k<=100; k++){
        if(num[k] != 0)
        count_prime++;
    }

    printf("There are %d prime numbers between 1 to 100 printed as follows :\n", count_prime);
    
    //printing all the prime numbers 
    for(int k = 1; k<=100; k++){

        if(num[k] != 0){
        printf("%d", num[k]);
        
        if(count_prime != 1)
        printf(", ");
        else 
        printf(".\n");
        
        count_prime--;

        }
    }

    return 0;
}

