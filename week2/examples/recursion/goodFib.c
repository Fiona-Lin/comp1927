#include <stdio.h>
#include <stdlib.h>


//Code to return the nth fibonacci number
//0 1 1 2 3 5 8 13 etc
//This code uses dynamic programming and caches intermediate results - 
//leading to increased  efficiency.
long long goodFib(long long n){
    long long i;
    long long prev1,prev2;
    long long tmp;
    prev1 = 0;
    prev2 = 1;
    for(i=0; i< n; i++){
       tmp = prev1;
       prev1 = prev2;
       prev2 = tmp + prev2;
    }
    return prev1;
}

int main(int argc, char * argv[]){
    long n;
    if(argc > 1){
       n = (long) atoi(argv[1]);
       printf("Fib %ld %lld\n",n,goodFib(n));
    } else {
       printf("Usage ./goodFib num\n");
    }

    return 0;
}


