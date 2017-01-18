//A complex Item with a key and a value

#include <assert.h>

typedef double Key;    //Can change key type
struct record{
    Key keyVal; //distance/weight
    int value;      //vertex id
};
typedef struct record * Item;

#define NULLitem NULL  //This indicates no item
#define key(A) ((A)->keyVal)
#define value(A) ((A)->value)
#define less(A,B) (((A)->keyVal) < ((B)->keyVal))
#define greater(A,B) (((A)->keyVal) > ((B)->keyVal))
#define lessEq(A,B) (((A)->keyVal) <= ((B)->keyVal))

Item newItem(double w,int v);
