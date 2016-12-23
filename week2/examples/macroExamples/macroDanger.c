#include <stdio.h>


//run
//gcc -E macroDanger.c
//To see the output from the preprocessor


#define cube(x) ((x)*(x)*(x))
#define double(x) ((x)+(x))
 
int main()
{
    int x = 3;
    int y = cube(x + 1); //?64
    int z = 5 * double(x); //30
 
    printf("y is %d\n",y);
    printf("z is %d\n",z);  
 
    return 0;
}

