// List.h ... interface to List GADT
// Written by John Shepherd, March 2013

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include "Item.h"

typedef struct ListRep *List;

List newList(); // create new empty list
void dropList(List); // free memory used by list
void showList(List); // display as [1,2,3...]
List readList(); // read+insert list values
List ListCopy(List); // make a copy of a list
void ListInsert(List,Item); // add item into list
void ListDelete(List,Item); // remove item(s)
Item ListItem(List,int); // get i'th item
int ListFindPos(List,Item); // position of item
int ListLength(List); // # items in list
void ListStartScan(List); // begin scan
Item ListScanNext(List); // fetch next element
int ListScanDone(List); // reached end of scan?

#endif
