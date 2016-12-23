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

    printf("The length is %d\n",length(myList));
    printf("Sum is %d\n",sumOfElems(myList));
    printListRec(myList);
    printf("\nIn reverse \n");
    printListRev(myList);    
    printf("\n");
   
    return 0;
}
