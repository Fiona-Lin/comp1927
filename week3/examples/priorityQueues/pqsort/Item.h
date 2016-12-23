//A complex Item with a key and a value

#include <assert.h>

typedef int Key;
typedef int Item;    //Can change key type

#define NULLitem NULL  //This indicates no item
#define key(A) (A)
#define value(A) (A)
#define less(A,B) ((A) < (B))
#define lessEq(A,B) ((A) <= (B))
#define greaterThan(A,B) ((A) > (B))

