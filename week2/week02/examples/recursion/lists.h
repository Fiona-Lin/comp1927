typedef int Item;

typedef struct node * link;
struct node{
    Item item;
    link next;
};

//recursive 
int length(link list);
int sumOfElems(link list);
void printListRec(link list);
void printListRev(link list);


void printList(link list);
link newList();
link newNode(Item item);
link insertEnd(link list, link n);
link insertFront(link list, link n);
link deleteFirst(link list);
void deleteFirstItem(link list, Item item);
void freeList(link list);
