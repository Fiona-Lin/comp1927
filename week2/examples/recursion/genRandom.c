#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    int i, numElements;

    fprintf(stderr, "Number of samples: ");
    scanf("%d", &numElements);
    
    // Output number of samples - it is required by the sort program
    printf("%d\n", numElements);

    // Generate random data
    srand(time(NULL));
    
    for (i = 0; i < numElements; i++) { // Randomly generate data
         printf("%d\n",rand()%1000000);
    }
    return 0;
}
