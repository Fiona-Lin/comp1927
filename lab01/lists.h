// Doubly and singly linked lists 
//

typedef int Item;

typedef struct _node *link;

typedef struct _node {
  Item item;
  link next;
} node;


typedef struct _dnode *dlink;

typedef struct _dnode {
  Item item;
  dlink prev;
  dlink next;
} dnode;


// traverses the list and prints the list
void printList (link list);

// return the sum of all items in list
int sumListItems (link lists);

//frees all memory used in the list
void freeList(link list);

// create a double-linked list which has contains the same elements,
// in the same order as 'list'
dlink doublify (link list);

// frees all the memory used in the double-linked list
void freeDList(dlink list);

// create a circular list with the number of nodes specified with 
// each link storing data from 1 to the number of nodes specified
link create_circular_list(int num_nodes);

// print the data in a circular fashion starting from any node
void print_nodes(link);
