#include <stdio.h>
#include <stdlib.h>

#define NAIVE_PIVOT 0
#define RANDOM_PIVOT 1
#define MT_PIVOT 2

#define TRUE 1
#define FALSE 0

void quicksort(int a[], int left, int right, int mode);
int partition(int a[], int left, int right);
void swap(int *a, int *b);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Invalid Usage: %s -p(n|r|m) [-q]\n", argv[0]);
        return EXIT_FAILURE;
    }
    int i;
    
    // grab modes 
    int mode;    
    if (strcmp(argv[1], "-pn") == 0) {
        mode = NAIVE_PIVOT;
    } else if (strcmp(argv[1], "-pm") == 0) {
        mode = MT_PIVOT;
    } else if (strcmp(argv[1], "-pr") == 0) {
        mode = RANDOM_PIVOT;
        // seed rand if we are using this
        srand(time(NULL));
    } else {
        printf("Invalid Usage: %s -p(n|r|m) [-q]\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    // quiet mode
    int quiet = FALSE;
    if (argc == 3 && strcmp(argv[2], "-q") == 0) {
        quiet = TRUE;
    }
    
    // get array size
    int size;
    printf("Enter data size: ");
   
    scanf("%d", &size);
    
    // get array
    int data[size];
 
    printf("Enter data:\n");
 
    for (i = 0; i < size; i++) {
        scanf("%d", &(data[i]));
    }
    
    // quicksort it
    quicksort(data, 0, size-1, mode);
    // print it if not quiet
    
    if (!quiet) {
        printf("Sorted with ");
        if (mode == NAIVE_PIVOT) {
            printf("naive");
        } else if (mode == MT_PIVOT) {
            printf("median of three");
        } else if (mode == RANDOM_PIVOT) {
            printf("randomised");
        } else {
            printf("Unknown option\n");
	        exit(1);
        }
        printf(" pivot:\n");
    // print array
        for (i = 0; i < size; i++) {
            printf("%d ", data[i]);
        }       
        printf("\n");
    }
    
    return EXIT_SUCCESS;
}

void quicksort(int a[], int left, int right, int mode) {
    int i;
    // Base-case: if left is greater than right, we have sorted.
    if (left >= right) {
        return;
    }
    
    // Normal quick-sort
    i = partition(a, left, right);
    // sort the partitions
    quicksort(a, left, i-1, mode);
    quicksort(a, i+1, right, mode);

    // Implement quick-sort with median of three partition and randomised pivot
    // To be completed...
}

int partition(int a[], int left, int right) {
    int i, j;
    
    i = left - 1;
    j = right;
    
    // now we have an appropriate pivot in a[r]
    int pivot = a[right];
    
    // pivot element
    for (;;) {
        // increment i until we approach the element that shouldnt be in pivot
        while (a[++i] < pivot);
        // get the element towards the right
        while (pivot < a[--j] && j != left);
        
        // if the left hand counter is greater than the right, we stop
        if (i >= j) {
            break;
        }

        // now we swap elements
        swap(&(a[i]), &(a[j]));    
    }   
    
    // place the pivot
    swap(&(a[i]), &(a[right]));
    // return the pivot index
    return i;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
