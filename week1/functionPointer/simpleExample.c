#include <stdio.h>

int square(int x){
    return x*x;
}

int absVal(int x){
    if( x < 0){
        return -x;
    } 
    return x;
}

int main(int argc, char * argv[]){
    int (*fp)(int);
    fp = &square;
    int n = (*fp)(9.8);

    printf("answer is %d\n",n);
    //& is optional
    fp = absVal;
    printf("answer is %d %d\n",(*fp)(-8),fp(-8));    
    

    printf("%p %p\n",absVal,&absVal);
    printf("%p %p\n",square,&square);
    return 0;
}
