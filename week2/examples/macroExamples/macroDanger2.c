#include <stdio.h>

#define double(x) ((x)+(x))
#define MAX 10 

int main()
{
    int x = 3;
    int y = double (++x);
 
    printf("y is %d\n",y); 
    printf("x is %d\n",x); 

    return 0;
}



