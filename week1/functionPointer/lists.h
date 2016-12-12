typedef int Item;

typedef struct node * link;
struct node{
    Item item;
    link next;
};

void multByTwo(link ls);
void divideByTwo(link ls);

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

void traverseIf(link ls, void (*visit) (link),int (*f) (Item));

//int (*f) (Item)
int isNegative(Item item);
int isOdd(Item item);
int isFail(Item item);

//void (*visit) (link)
void printGrade(link ls);
void printNode(link ls);
void printValue(link ls);
