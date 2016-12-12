#include <stdio.h>
#include <stdlib.h>
#include "dlists.h"


int main(int argc, const char * argv[]){
    int i;
    dlink myList = newList();
    dlink node1 = newNode(10);
    
    myList = insertFront(myList,node1);
    dlink node2 = newNode(99);
    myList = insertEnd(myList,node2);
    printList(myList);
    
    for(i=0; i < 10; i++){
        myList = insertEnd(myList,newNode(i));
    }
    dlink node3 = newNode(-10);
    myList = insertEnd(myList,node3);
    printList(myList);    
    printf("Delete 99\n");
    myList = delete(myList,node2);
    printList(myList);
    printf("Delete 10\n");
    myList = delete(myList,node1);
    printList(myList);
    printf("Delete -10\n");
    myList = delete(myList,node3);
    printList(myList);
   
    return 0;
}
