#include <stdio.h>

void printSomething(int x){
    printf("%d\n",x);
}
int square(int x){
   return x*x;
}

int absVal(int x){
   if(x < 0) return -x;
   return x;
}

int main(int argc, char * argv[]){
    int (*fp)(int);
    fp = square;

    int n = (*fp)(10);

    printf("The answer is %d\n",n); //100

    fp = absVal;

    n = fp(-99);
    printf("The answer is %d\n",n); //99
    
    //fp = printSomething;
    return 0;
}
