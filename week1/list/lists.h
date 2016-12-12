typedef int Item;

typedef struct node * link;
struct node{
    Item item;
    link next;
};



void printList(link list);
link newList();
link newNode(Item item);
link insertEnd(link list, link n);
link insertFront(link list, link n);
link deleteFirstItem(link list);
void deleteNext(link curr);

// These functions were created to demonstrate the
// use of function pointers
void traverse(link ls, void (*visit) (link));
void traverseIf(link ls, int (*f) (Item));
int isOdd(Item item);
int isFail(Item item);
void printGrade(link ls);
void printNode(link ls);
