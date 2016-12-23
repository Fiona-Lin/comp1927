#include <stdlib.h>

#include "Item.h"

Item newItem(Key k,char * v){
    Item i = malloc(sizeof(struct record));
    assert(i != NULL);
    i->keyVal = k;
    i->value = v;
    return i;
}
