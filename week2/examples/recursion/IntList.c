// IntList.c - Lists of integers

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "IntList.h"

// data structures representing IntList
typedef struct intListNode IntListNode;

struct intListNode {
    int  data;      // value of this list item
    IntListNode * next;
	            // pointer to node containing next element
};

struct intListImp {
    IntListNode *  first; 
};


int length(IntListNode *n){
    if(n == NULL){
        return 0;
    } else {
        return 1 + length(n->next);
    }
}

//recursive function to find the length of a list
int lengthList(IntList list){
    return length(list->first);
}



// create a new IntListNode with value v
// (this function is local to this ADT)
static struct intListNode *newIntListNode(int v);


// create a new empty IntList
IntList newIntList(void){
    struct intListImp *list;

    list = malloc(sizeof (struct intListImp));
    assert (list != NULL);
    list->first = NULL;
    return list;
}


// create a new IntListNode with value v
// (this function is local to this ADT)
static IntListNode *newIntListNode(int v){
    IntListNode *n;

    n = malloc(sizeof (IntListNode));
    assert(n != NULL);
    n->data = v;
    n->next = NULL;
    return n;
}

// create an IntList by reading values from a file
// assume that the file is open for reading
IntList fScanIntList(FILE *inf){
    IntList list;
    int v;

    list = newIntList();
    while (fscanf(inf,"%d",&v) != EOF){
	insertIntList(list,v);
    }
    return list;
}

// apppend one integer to the end of a list
void insertIntList(IntList list, int v){
    IntListNode *n, * curr;

    assert(list != NULL);
    n = newIntListNode(v);
    
    //special case for when the list has no nodes yet
    if(list->first == NULL){
	list->first = n;
    }else{
        curr = list->first;
        while(curr->next != NULL){
	    curr = curr->next;
        }
    
        curr->next = n;
    }
}

// delete first occurrence of v from a list
// if v does not occur in List, no effect
void deleteIntList(IntList list, int v){
    IntListNode *curr, *prev;

    assert(list != NULL);

    // find where v occurs in list
    prev = NULL; curr = list->first;
    while (curr != NULL && curr->data != v) {
        prev = curr;
	curr = curr->next;
    }
    // not found; give up
    if (curr != NULL){
        // unlink curr
        if (prev == NULL){
            list->first = curr->next;
        }else{
       	    prev->next = curr->next;
        }
        // remove curr
        free(curr);
    }
}

// display list as one integer per line
void printIntList(IntList list){
    IntListNode *curr;

    assert(list != NULL);
    for (curr = list->first; curr != NULL; curr = curr->next){
        printf("%d\n", curr->data);
    }
}

//Reverses the order of elements in the list
void reverse(IntList list){
    IntListNode *curr,*tmp,*rev = NULL;
    assert(list !=NULL);
    curr=list->first;
    while(curr!=NULL){
       tmp = curr->next;
       curr->next = rev;
       rev = curr;
       curr = tmp;
    }
    list->first = rev;
}


//Will print list in order or reverse order depending on the order of
//the printf statement and the recursive call
static void recursivePrintNodes(IntListNode *n){
    if(n != NULL){
        printf("%d ",n->data); 
        recursivePrintNodes(n->next);
    }
}
    
// A function that calls recursivePrintNodes on the first element in a given
// list
void recursivePrint(IntList list){
    assert(list!=NULL);  
    recursivePrintNodes(list->first);
}   

//Will print list in order or reverse order depending on the order of
//the printf statement and the recursive call  
static void recursivePrintNodesReverse(IntListNode *n){
      if(n != NULL){
        recursivePrintNodesReverse(n->next);
        printf("%d ",n->data);
    }
}

// A function that calls recursivePrintNodes on the first element in a given
// list
void recursivePrintReverse(IntList list){
    assert(list!=NULL);
    recursivePrintNodesReverse(list->first);
} 

