#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


int main(int argc, const char * argv[]){
    int i;
    link myList = newList();
    
    for(i=-9; i < 100; i = i+9){
        myList = insertEnd(myList,newNode(i));
    }
    printList(myList);    

   
    traverse(myList,printGrade);
   
    traverse(myList,printNode);
  
    traverse(myList,multByTwo);
    traverse(myList,printValue);
   
    traverse(myList,divideByTwo);
    traverse(myList,printValue);
   
    
    printf("Negative ");
    traverseIf(myList,printNode,isNegative);
    
    traverseIf(myList,printGrade,isOdd);
    traverseIf(myList,printNode,isOdd);
    traverseIf(myList,printNode,isFail);
   
    return 0;
}
