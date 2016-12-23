#include <stdio.h>

//Calculate the factorial of an integer n
//Note that factorials grow big very quickly 
//Large n can result in int overflow - try factorial 20
//Even larger n can cause program to crash! Try 999999
long long factorial(int n){
    long long result;
    if(n ==0) { //base case
        result = 1;
    }else{
        result = n * factorial(n-1); //recursive case
    }
    return result;
}


long long iterativeFactorial(int n){
   long long result = 1;
   while(n >= 1){
       result = result * n;
       n--;
   }
   return result;
}

int main(void){
    int n;
    printf("Enter n:");
    while(scanf("%d",&n) == 1){
        printf("The factorial of %d is %lld\n",n,factorial(n));
        printf("The factorial of %d is %lld\n",n,iterativeFactorial(n));
        printf("Enter n:");
    }    

    return 0;
}
