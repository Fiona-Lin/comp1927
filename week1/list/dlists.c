#include <stdio.h>
#include <stdlib.h>
#include "dlists.h"


//This prints the list forwards and backwards 
//just to make sure our double links are set
//up correctly!
void printList(dlink list){
    dlink curr;
    dlink last = NULL;
    printf("Forwards\n");
    for(curr = list; curr != NULL; curr= curr->next){
        last = curr;
        printf("%d ",curr->item);
    }
    printf("\nBackwards\n");
    for(curr = last; curr != NULL; curr = curr->prev){
        printf("%d ",curr->item);
    }
    printf("\n");

}


dlink newList(void){
    return NULL;
}

dlink newNode(Item item){
    dlink n = (dlink) malloc(sizeof(*n));
    n->item = item;
    n->next = NULL;
    n->prev = NULL;
    return n;
    
}

dlink insertEnd(dlink list, dlink n){
    dlink curr;
    if(list == NULL){
        list = n;
    } else {
        for(curr = list; curr->next != NULL; curr = curr->next){
    
        }
        curr->next = n;
        n->prev = curr;
    }
    return list;
    
}

dlink insertFront(dlink list, dlink n){
   n->next = list;
   if(list != NULL){
       list->prev = n;
   }
   return n;
}

//Now that we have a doubly linked list
//we can delete the curr node without 
//searching through the list for the previous
//node.
dlink delete(dlink list, dlink curr){
    if(curr != NULL){
        dlink p = curr->prev;
        dlink n = curr->next;
        if( p != NULL){
            p->next = n;
        } else {
            list = n;
        }
        if(n != NULL){
            n->prev = p;
        }
        free(curr);
    }
    return list;
}

