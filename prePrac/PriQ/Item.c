#include <stdlib.h>

#include "Item.h"

Item newItem(Key k,char * v){
    Item re = calloc(sizeof(struct record),1);
    re -> value = v;
    re -> keyVal = k;
    return re;
}
