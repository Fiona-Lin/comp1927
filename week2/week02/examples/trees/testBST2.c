#include <stdlib.h>
#include <stdio.h>
#include "BST.h"
#include <assert.h>

//To compile please type
//gcc -Wall -Werror -O -o testBST2 BST.c testBST2.c Stack.c
//To run please type
//./testBST2

void printStuff(Treelink tree);

   
//Need to change type of TreeItem to char
int main(int argc, char * argv[]){
    Treelink t1 = createTree();
    //assert(size(t1) == 0);
    t1 = insertIterative(t1,'e');
    t1 = insertIterative(t1,'a');   
    t1 = insertIterative(t1,'m');
    t1 = insertIterative(t1,'t');
    t1 = insertIterative(t1,'s');
    t1 = insertIterative(t1,'f');
    t1 = insertIterative(t1,'y');
  
    t1 = delete(t1,'m');
    t1 = delete(t1,'f');
    t1 = delete(t1,'t');

    printStuff(t1);
    
    destroyTree(t1);
  
    return 0;
}


void printStuff(Treelink tree){
    
  
    printf("Pre order traversal: ");
    preorderTraversal(tree);
  
    printf("\n");
    
}
