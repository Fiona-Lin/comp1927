//A complex Item with a key and a value

#include <assert.h>

typedef int Key;    //Can change key type
struct record{
    Key keyVal;
    char * value;      //Can change value type
};
typedef struct record * Item;

#define NULLitem NULL  //This indicates no item
#define key(A) ((A)->keyVal)
#define value(A) ((A)->value)
#define less(A,B) (((A)->keyVal) < ((B)->keyVal))
#define lessEq(A,B) (((A)->keyVal) <= ((B)->keyVal))
#define greaterThan(A,B) (((A)->keyVal) > ((B)->keyVal))

Item newItem(Key k,char * v);
