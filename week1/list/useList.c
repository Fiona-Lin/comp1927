#include <stdio.h>
#include <stdlib.h>
#include "lists.h"


int main(int argc, const char * argv[]){
    int i;
    link myList = newList();
    link node1 = newNode(10);
    
    myList = insertEnd(myList,node1);
    link node2 = newNode(99);
    myList = insertFront(myList,node2);
    printList(myList);
    
    for(i=0; i < 10; i++){
        myList = insertFront(myList,newNode(i));
    }
    printList(myList);    

    myList = deleteFirstItem(myList);
    printList(myList);

    deleteNext(node2);
    printList(myList);

    traverse(myList,printNode);
    printf("\n");
    traverse(myList,printGrade);
    printf("\n");
    traverseIf(myList,isFail);
    traverseIf(myList,isOdd);
    return 0;
}
