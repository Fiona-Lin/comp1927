#include <stdlib.h>
#include <stdio.h>
#include "BST.h"
#include <assert.h>

//To compile please type
//gcc -Wall -Werror -O -o testBST BST.c testBST.c
//To run please type
//./testBST

void printStuff(Treelink tree);

   

int main(int argc, char * argv[]){
    Treelink t1 = createTree();
    assert(size(t1) == 0);
    t1 = insertIterative(t1,1);
    t1 = insertIterative(t1,5);
    t1 = insertIterative(t1,10);
    t1 = insertIterative(t1,11);
    t1 = insertIterative(t1,15);
    t1 = insertIterative(t1,20);
    assert(size(t1) == 6);
    assert(height(t1) == 5); 
    printStuff(t1);
    
    Treelink t2 = createTree();
    t2 = insertIterative(t2,10);
    t2 = insertIterative(t2,15);
    t2 = insertIterative(t2,11);
    t2 = insertIterative(t2,20);
    t2 = insertIterative(t2,1);
    t2 = insertIterative(t2,5);
    assert(height(t2) == 2);
    printStuff(t2);
    
    destroyTree(t1);
    destroyTree(t2);    
    return 0;
}


void printStuff(Treelink tree){
    
    printf("\nPlease turn head on side to the left to see the tree\n");
    showBSTree(tree);
    printf("\n");
    if(size(tree) > 0)
        printf("Root of tree is %d\n",getItem(tree));
    

    printf("\nheight is %d\n",height(tree));
    
    printf("size is %d\n",size(tree));

   
    printf("Pre order traversal: ");
    preorderTraversal(tree);
    printf("\nIn order traversal: ");
    inorderTraversal(tree);
   
    printf("\nPost order traversal: ");
    postorderTraversal(tree); 
    printf("\nLevel order traversal: ");
    levelOrderTraversal(tree);
    printf("\nMystery order iterative : ");
    mysteryIterativeTraversal(tree);
    printf("\n");
    
}
