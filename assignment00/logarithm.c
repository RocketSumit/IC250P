// source code to find logarithm
#include <stdio.h>
#include <math.h>

double logarithm(double x, int n);//function to finf logarithm

int main(){
    int n;
    double x;

    printf("Enter the value of x: ");
    scanf("%lf", &x);
    
    printf("Enter the numbers of terms n: ");
    scanf("%d", &n);

    if(x>0 && n>0)
        printf("The value of log(%lf) approximated to %d terms is : %lf\n", x, n, logarithm(x, n));
    
    else
    printf("Try again\n");
    
    return 0;
}

 double logarithm(double x, int n){
    
    double ans = ((x - 1)/x);
    if (n == 1){
        return ans;//return only first term
    }
    else{
        for(int i = 1;i < n;i++){
            ans += (1.0/(i+1)) * pow(((x - 1)/x), i + 1);
        }
        return ans;//value of log for more than 1 terms
    }
    
}


