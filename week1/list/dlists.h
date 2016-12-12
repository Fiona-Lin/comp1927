//doubly linked list

typedef int Item;

typedef struct dnode * dlink;
struct dnode{
    Item item;
    dlink prev;
    dlink next;
};



void printList(dlink list);
dlink newList(void);
dlink newNode(Item item);
dlink insertEnd(dlink list, dlink n);
dlink insertFront(dlink list, dlink n);
dlink delete(dlink list, dlink n);
