// Bool.h ... faux boolean data type
//
// WARNING: never use expressions like
//   (x > 5) == TRUE  or  (x < 3) == FALSE
// use simply
//   (x > 5)          or  !(x < 3)  or (x >= 3)

#ifndef BOOL_H
#define BOOL_H 1

#define TRUE  1
#define FALSE 0

typedef int Bool;

#endif
