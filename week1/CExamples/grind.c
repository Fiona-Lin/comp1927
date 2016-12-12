#include <stdlib.h>
#include <stdio.h>

  void f() {
     int *x = malloc(sizeof(int)*10);
     x[10]=20;
     printf("int is: %d \n",x[0]);
}

int main()
{
  f();
  return 0;
}
