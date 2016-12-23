// testList.c ... simple List testing client
// Written by John Shepherd, March 2013

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "Item.h"
#include "List.h"

int main(int argc, char *argv[])
{
	int i;
	List L = newList();

        printf("test list");	
        int a[] = {1,2,3};
        printf("%d\n",a[0]);
        assert(ListLength(L) == 0);
        showList(L);
	for (i = 0; i < 20; i++)
		ListInsert(L,i);

	assert(ListLength(L) == 20);
	printf("L: "); showList(L); printf("\n");
	int curr, prev = -1;
	ListStartScan(L);
	while (!ListScanDone(L)) {
		curr = ListScanNext(L);
		assert(curr > prev);
		prev = curr;
	}
	dropList(L);
	return 0;
}

