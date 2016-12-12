#include <stdio.h>
#include <stdlib.h>

typedef struct node * link;

struct node{
   int item;
   int stuff;
   char otherStuff[100];
   link next;
};


int main(void){
    link x = NULL;
    
    printf("%d size of struct node\n",sizeof(struct node));
    printf("%d size of *x\n",sizeof(*x));
  
    printf("%d size of x\n",sizeof(x));
    printf("%d size of link\n",sizeof(link));
 

    return 0;
}
