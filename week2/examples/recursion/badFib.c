#include <stdio.h>
#include <stdlib.h>

//Code to return the nth fibonacci number
//0 1 1 2 3 5 8 13 etc
//This code is very inefficient! It is exponential.
//Time it with input of say 30 vs  45 vs 46 vs 47 etc 
unsigned long long badFib(unsigned long long n){
    unsigned long long result = 0;
    if(n == 0){
        result = 0;
    }else if(n == 1){
        result = 1;
    }else{
        result = badFib(n-1) + badFib(n-2);
    }
    return result;
}


int main(int argc, char * argv[]){
    int n;
    if(argc > 1){
       n = atoi(argv[1]);
       printf("Fib %d %llu\n",n,badFib(n)); 
    } else {
       printf("Usage: ./badFib num\n");
    }   

    return 0;
}
